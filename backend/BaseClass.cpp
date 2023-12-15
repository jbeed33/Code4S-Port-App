#include "BaseClass.hpp"
#include <iostream>
#include "expand.hpp"

void Base::baseSetup(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone){
	frontier.clear();
	closed.clear();
	Node first;
	first.ship = ship;
	first.cranePos = {craneRow, craneCol};
	first.prev = {{0,0,0},{craneRow, craneCol, craneZone}, {1}};
	first.craneLocation = craneZone;
	

	//create buffer
	for(int i = 0; i < BUFFERHEIGHT; i++){
		vector<Container> row;
		for(int j = 0; j < BUFFERWIDTH; j++){
			row.push_back(first.e);
		}
    	first.buffer.push_back(row);
	}


	first.heuristic = heuristic(first);
	frontier.push_back(first);
}

void Base::addToFrontier(Node toAdd) {
	if (frontier.size() + 1 > maxQueueSize)
		maxQueueSize = frontier.size() + 1;
	if (true == frontier.empty()) {
		frontier.push_back(toAdd);
		return;
	}
	for (int i = 0; i < frontier.size(); i++) {
		int toAddCost = toAdd.cost;
		int frontierCost = frontier[i].cost;
		toAddCost += toAdd.heuristic;
		frontierCost += frontier[i].heuristic;
		if (toAddCost < frontierCost) {
			frontier.emplace(frontier.begin() + i, toAdd);
			return;
		}
	}
	frontier.push_back(toAdd);
}

Node Base::search(vector<vector<Container>> ship, int craneRow, int craneCol, int craneZone, int numToLoad, vector<string> toUnload) {
	baseSetup(ship, craneRow, craneCol, craneZone);
	expandedNodeCount = 1;
	maxQueueSize = 0;
	
	while (true) {
		if (true == frontier.empty()) {
			cout << "\n\nFailed\n\n";
			cout << "To solve this problem the search algorithm expanded a total of " << expandedNodeCount << " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time : " << maxQueueSize << endl;
			Node failed;
			failed.cost = -1;	//Signals the search failed
			return failed;
		}
		if (0 == frontier[0].heuristic) {	//(true == goalTest(frontier[0].ship)) {
			cout << "\n\nFOUND\n\n" << endl;
			 cout << "Final Crane location: " << frontier[0].cranePos.first << "    " << frontier[0].cranePos.second << endl;
			cout << "To solve this problem the search algorithm expanded a total of " << expandedNodeCount << " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time : " << maxQueueSize << endl;
			cout << "The depth of the goal node was " << frontier[0].path.size() << endl;
			cout << "\n\n";
			return frontier[0];
		}
		if (0 == expandedNodeCount++ % 1000) {	//Shows the program hasn't gotten stuck
			cout << "." << endl;
			cout << "Expanded a total of " << expandedNodeCount << " nodes." << endl;
			cout << "The maximum number of nodes: " << maxQueueSize << endl;
			break;
		}

		nodeExpand(frontier[0]);
		

	}
}


/*
*	takes the node we are expanding from, the start and end columns, the start and end zones,
*	and if the crane is carrying a container for the current move
*/
int Base::cost(Node current){
	int cost = current.cost;

	int startRow = current.prev[0][0];
	int startCol = current.prev[0][1];
	int startZone = current.prev[0][2];
	int endRow = current.prev[1][0];
	int endCol = current.prev[1][1];
	int endZone = current.prev[1][2];

	if(startZone != endZone){	//move between zones
		cost += PORTALTIME;
	}
	else{
		cost += max(startCol, endCol) - min(startCol, endCol);
	}

	cost += max(startRow, endRow) - min(startRow, endRow);

	return cost;
}


void Base::nodeExpand(Node n){
    // 0 - ship
    // 1 - truck
    // 2 - buffer

	closed.push_back(frontier[0]);
	frontier.erase(frontier.begin());

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);


    
    //check to see if the crane start col has a box to move
    bool hasBox = false;
    vector<vector<int>> boxPos;
    Container box;
    int craneCol = n.cranePos.second;
    // cout << "crane" << craneCol << endl;
    int zone = n.craneLocation;
    boxPos = getContainerDataFromCranePos(n,craneCol, zone );

    if(boxPos.size() > 0){
        cout << "updated hasbox" << endl;
        hasBox = true;

    }

    //save current prev on node to path
    n.path.push_back(n.prev);
        
    //Crane movemnt 
     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip );

     for(int i = 0; i < craneMoves.size(); i++){
        cout << "< " << craneMoves.at(i).at(0) << " , " << craneMoves.at(i).at(1) << " >" << endl;
     }

     cout << "craneMoves size: " << craneMoves.size() << endl;

	cout << 1 << endl;
    //Expand Nodes
    vector<Node> returnedNodes = expandNodeBasedOnCraneMovement(n, boxPos, hasBox, craneMoves);

    //For each Node - call cost and heurstic
	 
	 cout << 2 << endl;
    //call state exsists - if does not already state exsist-> push to fronteir
	for(int i = 0; i < returnedNodes.size(); i++){
		
		
			if(!stateExists(returnedNodes.at(i))){
				//update cost
				returnedNodes.at(i).cost = cost(returnedNodes.at(i));
			

				//update heuristic
				 cout << "Position of Crane: " << returnedNodes.at(i).cranePos.first << " , " <<  returnedNodes.at(i).cranePos.second << endl;
				returnedNodes.at(i).heuristic = heuristic(returnedNodes.at(i));
			
				addToFrontier(returnedNodes.at(i));
			}

			
		
	}

	cout << 3 << endl;
	
    



}