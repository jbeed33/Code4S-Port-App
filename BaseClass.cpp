#include "BaseClass.h"
#include <iostream>

void Base::baseSetup(vector<vector<tuple<Container, int>>> ship, int craneRow, int craneCol, int craneZone){
	frontier.clear();
	closed.clear();
	Node first;
	first.ship = ship;
	first.cranePos = {craneRow, craneCol};
	first.craneLocation = craneZone;
	frontier.push_back(first);
}


Node Base::search(vector<vector<tuple<Container, int>>> ship, int craneRow, int craneCol, int craneZone, int numToLoad, vector<string> toUnload) {
	baseSetup(ship, craneRow, craneCol, craneZone);

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
			cout << "To solve this problem the search algorithm expanded a total of " << expandedNodeCount << " nodes." << endl;
			cout << "The maximum number of nodes in the queue at any one time : " << maxQueueSize << endl;
			cout << "The depth of the goal node was " << frontier[0].path.size() << endl;
			cout << "\n\n";
			return frontier[0];
		}
		if (0 == expandedNodeCount++ % 100) {	//Shows the program hasn't gotten stuck
			cout << ".";
		}
		nodeExpand(frontier[0]);
	}
}


/*
*	takes the node we are expanding from, the start and end columns, the start and end zones,
*	and if the crane is carrying a container for the current move
*/
int Base::cost(Node current, int startCol, int endCol, int startZone, int endZone, bool justCrane){
	int cost = 0;
	int startTop;
	int endTop;
	int startZoneHeight;
	int endZoneHeight;

	int craneRow = current.cranePos.first;
	int craneCol = current.cranePos.second;

	if(0 == startZone){	//Starts on ship
		startTop = findTopShip(current.ship, startCol);
		startZoneHeight = SHIPHEIGHT - 1;
	}
	else if(2 == startZone){	//starts in buffer
		startTop = findTopBuffer(current.buffer, startCol);
		startZoneHeight = BUFFERHEIGHT - 1;
	}
	else{	//Starts on truck
		startTop = 0;
		startZoneHeight = 0;
	}

	if(0 == endZone){	//Ends on ship
		endTop = 1 + findTopShip(current.ship, endCol);
		endZoneHeight = SHIPHEIGHT - 1;
	}
	else if(2 == endZone){	//Ends in buffer
		endTop = 1 + findTopShip(current.buffer, endCol);
		endZoneHeight = BUFFERHEIGHT - 1;
	}
	else{	//Ends on truck
		endTop = 0;
		endZoneHeight = 0;
	}

	if(true == justCrane && 0 == current.prev[2][0]){	//Dropped off a container to start move
		cost += craneRow - (startTop + 1);
	}
	else if(false == justCrane && 1 == current.prev[2][0]) {	//Picked up a container to start move
		cost += craneRow - startTop;
	}
	else{	//Maintain position to start move
		startTop = craneRow;
	}

	if(startZone != endZone){	//move between zones
		cost += PORTALTIME;
		cost += startZoneHeight - startTop;	//move up to portal
	}
	else{
		cost += SINGLEMOVETIME;
		if(endTop > startTop){	//have to move up to get over containers
			cost += endTop - startTop;
		}
	}
	return cost;
}