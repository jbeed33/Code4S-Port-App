#ifndef EXPAND_H
#define EXPAND_H

#include "node.hpp"
#include <iostream>
#include<vector>
#include<cmath>
#include "helper.hpp"
using namespace std;

const vector<int> shipPortal = {0, 0, 0};
const vector<int> bufferPortal = {0, BUFFERWIDTH - 1, 2};
const vector<int> truckPortal = {1, 0, 1};

void PrintShip(Node n){
    for(int i = 0; i < n.ship.size(); i++){
        for(int j = 0; j < n.ship[0].size(); j++){
                cout << n.ship[i][j].status << '\t';
            if(n.ship.at(i).at(j).status > 1)  ;
            if(i == n.cranePos.first && j == n.cranePos.second){
            } 
            
            if(n.ship.at(i).at(j).status == 0)  ;
           
        }
        cout << endl;
    }
}

void PrintBuffer(Node n){
    for(int i = 0; i < n.buffer.size(); i++){
        for(int j = 0; j < n.buffer[0].size(); j++){
            if(n.buffer.at(i).at(j).status > 1)  ;
            if(i == n.cranePos.first && j == n.cranePos.second){
                ;
            } 
            
            if(n.buffer.at(i).at(j).status == 0)  ;
           
        }
        ;
    }
}

// 0 - ship 1-buffer
//Get all avaliable columns from buffer and ship
vector<int> getWallsForZone(Node &n, int zone ){
    
    
    

    //Scan through top row and detect if there is a wall for ship
    if(zone == 0){
        vector<int> avaliableColsForShip(n.ship[0].size(),0);
         for(int i = 0; i < n.ship[0].size(); i++){
            if(n.ship.at(0).at(i).status != 0){
                avaliableColsForShip.at(i) = 1; // there is a wall
            }
        }

        return avaliableColsForShip;
    }
    else{
        vector<int> avaliableColsForBuffer(n.buffer[0].size(),0);

         //Scan through top row and detect if there is a wall for buffer
        for(int i = 0; i < n.buffer[0].size(); i++){
            if(n.buffer.at(0).at(i).status != 0){
                avaliableColsForBuffer.at(i) = 1; // there is a wall
            }
        }

        return avaliableColsForBuffer;
    }

}

// Return <row, col>
vector<vector<int>> getContainerDataFromCranePos(Node& n, int craneCol, int zone){

    vector<vector<int>> boxPos;

        if(zone == 0){ //crane starts from ship
            for (int j = 0; j < n.ship.size(); j++) 
		    { 
                if(n.ship.at(j).at(craneCol).status > 0){
                    boxPos.push_back({j, craneCol});
                    return boxPos;
                }
			
		    }

            
        }
        else if(zone == 2){ //crane starts from buffer
            for (int j = 0; j < n.buffer.size(); j++) 
		    { 
                if(n.buffer.at(j).at(craneCol).status > 0){
                    boxPos.push_back({j, craneCol});
                    return boxPos;
                }
			
		    }

           
           
        }
        else if(zone == 1){ 
            if(n.numToLoad > 0) {
                boxPos.push_back({1,0});
            }
        }

        // returns nothing if - no container in row or its a structural wall
        return boxPos;
}

int findTopContainerInCol(Node &n, int col, int zone){
    //returns the row of emtpy spot

    if(zone == 0){ //ship
		for (int j = 0; j < n.ship.size(); j++) 
		{ 
		    if(n.ship.at(j).at(col).status != 0){
                
                return j;
            } else{
                if(j == n.ship.size()-1){ // bottom row
                    return j;
                }
            }
			
		}

    }
    else if( zone == 2){ //buffer
        for (int j = 0; j < n.buffer.size(); j++) 
		{ 
		    if(n.buffer.at(j).at(col).status != 0){
                
              return j;
            } else{
                if(j == n.buffer.size()-1){ // bottom row
                    return j;
                }
            }
			
		}
		return n.buffer.size() - 1;
    }
    else{ // truck
        return 1;
    }
	return -1;
}

int findTopContainerInColWithStartingRow(Node &n, int col, int zone, int startRow){
    //returns the row of emtpy spot

    if(zone == 0){ //ship
		for (int j = startRow; j < n.ship.size(); j++) 
		{ 
		    if(n.ship.at(j).at(col).status != 0){
                
                return j;
            } 
		}

        return n.ship.size();

    }
    else if( zone == 2){ //buffer
        for (int j = startRow; j < n.buffer.size(); j++) 
		{ 
		    if(n.buffer.at(j).at(col).status != 0){
                
              return j;
            }
			
		}

        return n.buffer.size();
    }
    else{ // truck
        return 1;
    }
		 
}

 // left / right for crane ( store vector< endRow, endCol, endZone>)
vector<vector<int>> craneMovement(Node &n, vector<int> avaliableColsForBuffer, vector<int> avaliableColsForShip ){
            vector<vector<int>> craneMovement;
            int craneRow = n.cranePos.first;
            int craneCol = n.cranePos.second;

            //try left
            if(n.craneLocation == 0){ //crane starts from ship
                
                //if(craneCol == 0){
                //    
                //    // //buffer - need to move left until can find a position that is avaliable
                //    // int bufferColIndex = n.buffer[0].size() - 1;
                //        
                //    //  craneMovement.push_back({0,bufferColIndex, 2});
                //    
                //    //truck not sure about the index it should what column number it should have
                //    // craneMovement.push_back({1,0, 1});
                //   
                //    
                //}
                if(craneCol != 0){ // case of not first column, try left
                    int leftColHeight = findTopContainerInCol(n, craneCol - 1, 0 );


                    //check to see if crane has to move up
                    if(craneRow > leftColHeight){
                        craneMovement.push_back({leftColHeight, craneCol -1, 0});
                    }
                    else{
                         craneMovement.push_back({craneRow, craneCol -1, 0});
                    }

                   

                }  

                 //try right

                    if(craneCol < n.ship[0].size() - 1){
                        int rightColHeight = findTopContainerInCol(n, craneCol + 1, 0 );

                        //check to see if crane has to move up
                        if(craneRow > rightColHeight ){
                            craneMovement.push_back({rightColHeight, craneCol + 1, 0});
                        }
                        else{
                            craneMovement.push_back({craneRow, craneCol + 1, 0});
                        }
                    }
               
    
            }
        
        else if(n.craneLocation == 2){ //crane starts from buffer
            
                //try to move right
                if(craneCol == n.buffer[0].size() - 1){
                    // //ship - need to move right 
                    // int bufferColIndex = 0;
                        
                    //  craneMovement.push_back({0,bufferColIndex, 0});
                    
                    
                    // //truck not sure about the index it should what column number it should have
                    //  craneMovement.push_back({1,0, 1});
                   
                }
                else{ // case of not last column of buffer, move right

                    int rightColHeight = findTopContainerInCol(n, craneCol + 1, 2 );

                    //check to see if crane has to move up
                    if(craneRow > rightColHeight ){
                        craneMovement.push_back({rightColHeight, craneCol + 1, 2});
                    }
                    else{
                         craneMovement.push_back({craneRow, craneCol + 1, 2});
                    }
                    ;
                }  

                 //try left
                if(craneCol > 0){
                    int leftColHeight = findTopContainerInCol(n, craneCol - 1, 2 );

                    //check to see if crane has to move up
                    if(craneRow > leftColHeight ){
                        craneMovement.push_back({leftColHeight, craneCol - 1, 2});
                    }
                    else{
                        craneMovement.push_back({craneRow, craneCol - 1, 2});
                    }
                }

        }
        else if(n.craneLocation == 1){ // crane starts from truck
           //try left
           int bufferWidth = n.buffer.size() - 1;
           craneMovement.push_back({0,bufferWidth, 2}); // go to buffer

           //try right
           craneMovement.push_back({0, 0, 0}); // go to ship
        }

        return craneMovement;
}

bool swapContainers(Node &n, int oldrow, int oldcol, int newrow, int newcol, int startZone, int endZone){
    
    const Container truckContainer = {"", 0, 2};
    const Container emptyContainer = {"", 0, 0};

    int oldRow = oldrow;
    int oldCol = oldcol;
    int newRow = newrow;
    int newCol = newcol;
    
    Container startContainer;

    //checking to see if we start on the truck and there are no containers left to load.
    if(startZone == 1 && n.numToLoad <= 0) return false;
    
    if(startZone == 0){
        startContainer = n.ship.at(oldRow).at(oldCol);
    }
    else if(startZone == 2){
        startContainer = n.buffer.at(oldRow).at(oldCol);
    }
    else if(startZone == 1){
        startContainer = truckContainer;
    }

     // if the endzone is truck and start container status != 1
     if(endZone == 1 && startContainer.status != 1) return false;
   
    //place in correct Zones. The boxes swap places!!!
     if(startZone == 0){
        n.ship.at(oldRow).at(oldCol) = emptyContainer;
    }
    else if(startZone == 2){
        n.buffer.at(oldRow).at(oldCol) = emptyContainer;
    }


     if(endZone == 0){
         n.ship.at(newRow).at(newCol) = startContainer;
    }
    else if(endZone == 2){
        n.buffer.at(newRow).at(newCol) = startContainer;
    }

     //updating crane position to final position.
     n.cranePos = {newRow, newCol};
    // //;

    return true;
}

/*The following bottom functions are the operators*/ 

void justCraneMovesLeftOrRight(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList ){
     Node op4 = n;
    
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

	int endRow = craneMoves[indexCraneMove][0];
	int endCol = craneMoves[indexCraneMove][1];
	int endZone = craneMoves[indexCraneMove][2];
	vector<int> farthest = findFarthest(n);
	//printf("left %d, \tlZone %d,\tright %d,\trZone %d,\tendCol %d,\tendZone %d\n", farthest[0], farthest[1], farthest[2], farthest[3], endCol, endZone);
	if(startCol > farthest[0] && endCol < farthest[0] && endZone == farthest[1])
		return;
	if(startCol > farthest[3] && endCol > farthest[2] && endZone == farthest[3])
		return;

     int sizeToCheck = (startZone == 0) ? n.ship[0].size() : n.buffer[0].size();
       
     bool isValidMove = (endCol > -1 && endCol < sizeToCheck);
     
     int newRow = findTopContainerInCol(n, endCol, endZone);
     
     if(newRow > startRow){
        newRow = startRow;
     }

    //move crane left or right
    if(isValidMove && n.prev.at(2).at(0) != 0 ){
        
        op4.cranePos = {newRow, endCol};
        op4.prev = {{startRow, startCol, startZone}, {{newRow, endCol, endZone}}, {1} };

        expandedNodesList.push_back(op4);
    }
}


void justCraneStartPortalShip(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    // crane must start on ship's location (0,0)
    if(startZone == 0 && startCol == 0){
        //Move to truck
		n1.cranePos = {1, 0};
        n1.craneLocation = 1;
        n1.prev = {{startRow, startCol, startZone}, truckPortal, {1} };
		if(0 < n.numToLoad)
        	expandedNodesList.push_back(n1);
    	
		//Move to move to buffer portal
		n1.cranePos = {0, BUFFERWIDTH - 1};
    	n1.craneLocation = 2;
    	n1.prev = {{startRow, startCol, startZone}, bufferPortal, {1}};
    	PrintBuffer(n1);
		if(false == bufferEmpty(n))
    		expandedNodesList.push_back(n1);
	}
}

void justCraneStartPortalBuffer(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    // crane must start on buffer's column
    if(startZone == 2 && startCol == BUFFERWIDTH - 1){
		//Move to ship
        n1.cranePos = {0, 0};
        n1.craneLocation = 0;
        n1.prev = {{startRow, startCol, startZone}, shipPortal, {1} };
		if(false == shipEmpty(n))
        	expandedNodesList.push_back(n1);

		n1.cranePos = {1, 0};
        n1.craneLocation = 1;
        n1.prev = {{startRow, startCol, startZone}, truckPortal, {1} };
		if(0 < n.numToLoad)
        	expandedNodesList.push_back(n1);
    }
}

void justCraneStartPortalTruck(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    // crane must start in trucks's zone
    if(startZone == 1){
		//Move to buffer
		n1.cranePos = {0, BUFFERWIDTH - 1};
		n1.craneLocation = 2;
		n1.prev = {{startRow, startCol, startZone}, bufferPortal, {1}};
		if(false == bufferEmpty(n))
			expandedNodesList.push_back(n1);

		//Move to ship
        n1.cranePos = {0, 0};
        n1.craneLocation = 0;
        n1.prev = {{startRow, startCol, startZone}, shipPortal, {1} };
		if(false == shipEmpty(n))
        	expandedNodesList.push_back(n1);
	}
}


void craneMovesLeftOrRightWithBox(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node op1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

	int endRow = craneMoves[indexCraneMove][0];
	int endCol = craneMoves[indexCraneMove][1];
	int endZone = craneMoves[indexCraneMove][2];

    int sizeToCheck = (n.craneLocation == 0) ? n.ship[0].size() : n.buffer[0].size();
    bool isValidMove = (endCol > -1 && endCol < sizeToCheck);
    

    if( startZone == 0){
		if(0 != n.ship[endRow][endCol].status){	//Moving into an occupied space
			if(0 < endRow){	//can we go up
				endRow--;
			}
			else{
				return;
			}
		}
        if(isValidMove){
            swapContainers(op1, startRow, startCol, endRow, endCol, startZone, endZone);
            op1.prev = {{startRow, startCol, startZone}, {{endRow, endCol, endZone}}, {0} };
            //PrintShip(op1);
            expandedNodesList.push_back(op1);
        }     
    }
                
    //buffer
    if( startZone == 2){
		if(0 != n.buffer[endRow][endCol].status){	//Moving into an occupied space
			if(0 < endRow){	//can we go up
				endRow--;
			}
			else{
				return;
			}
		}
         if(isValidMove){
            swapContainers(op1, startRow, startCol, endRow, endCol, startZone, endZone);
            op1.prev = {{startRow, startCol, startZone}, {{endRow, endCol, endZone}}, {0} };
            expandedNodesList.push_back(op1);
         } 
    }
}

void craneMovesWithBoxStartPortalShip(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    // crane must start on ship's portal column
    if(startZone == 0 && startCol == 0){
        //Move to truck if container is unloadable
        if(n.ship.at(startRow).at(startCol).status == 1){
            swapContainers(n1, startRow, startCol, 1, 0, startZone, 1);
            n1.cranePos = {1, 0};
            n1.craneLocation = 1;
            n1.prev = {{startRow, startCol, startZone}, truckPortal, {1}};
            expandedNodesList.push_back(n1);
        }
		//Move to buffer if portal is clear
		n1 = n;
        if(n1.buffer.at(0).at(n1.buffer[0].size() - 1).status == 0){
            swapContainers(n1, startRow, startCol, 0,  BUFFERWIDTH - 1, startZone, 2);
            n1.cranePos = { 0, n.buffer[0].size() - 1};
            n1.craneLocation = 2;
            n1.prev = {{startRow, startCol, startZone}, {0, BUFFERWIDTH - 1, 2}, {0}};
        	expandedNodesList.push_back(n1);
        }
	}
}

void craneMovesWithBoxStartPortalBuffer(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    //check to see if we are starting from buffer portal
    if(n.craneLocation == 2 && startCol == BUFFERWIDTH - 1){

        //check to see if ship portal is empty
        if(n1.ship.at(0).at(0).status == 0){
            swapContainers(n1, startRow, startCol, 0, 0, startZone, 0);
            n1.cranePos = {0, 0};
            n1.craneLocation = 0;
            n1.prev = {{startRow, startCol, n.craneLocation}, shipPortal, {0}};
            expandedNodesList.push_back(n1);
        }
    }
}

void craneMovesWithBoxStartPortalTruck(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
    int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    //check to see if we are starting from truck portal
    if(startZone == 1){
        //check to see if ship portal is empty and there are containers to load
        if(n1.ship.at(0).at(0).status == 0 && n1.numToLoad > 0){
            swapContainers(n1, startZone, startCol, 0, 0, startZone, 0);
            n1.cranePos = {0, 0};
            n1.craneLocation = 0;
            n1.numToLoad -= 1;
            n1.prev = {{startRow, startCol, n.craneLocation}, shipPortal, {0} };
            expandedNodesList.push_back(n1);
        }
    }
}


void craneDropsOffBox(Node &n, vector<Node> &expandedNodesList){
    Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    int newRow = findTopContainerInColWithStartingRow(n1, startCol, startZone, startRow + 1) - 1;

	if(1 == startZone)
		return;
    

    swapContainers(n1, startRow, startCol, newRow, startCol, startZone, startZone);
    n1.cranePos = {newRow, startCol};

    //update prev
    n1.prev = {{startRow, startCol, startZone}, {newRow, startCol, startZone}, {1}};

    //PrintShip(n1);
    expandedNodesList.push_back(n1);
}

void cranePicksUpBox(Node &n, vector<Node> &expandedNodesList){
	Node n1 = n;
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;
   
   // If row is empty, then do not expand
    bool isRowEmpty = true;
	int newRow = 1;

	if(1 != startZone){	//not in truck
		newRow = findTopContainerInColWithStartingRow(n, startCol, startZone, startRow);
		if(0 == startZone && newRow < SHIPHEIGHT){
			isRowEmpty = false;
			if(0 > n.ship[newRow][startCol].status)	//Trying to move ship wall
				return;
		}
		else if(newRow < BUFFERHEIGHT)
			isRowEmpty = false;
	}
	else{
		if(0 < n.numToLoad)
			isRowEmpty = false;
	}

    if(isRowEmpty == true ){
        return;
    }

    n1.cranePos = {newRow, startCol};
	
    //update prev
    n1.prev = {{startRow, startCol, startZone}, {newRow, startCol, startZone}, {0}};

    expandedNodesList.push_back(n1);
}

vector<Node> expandNodeBasedOnCraneMovement(Node &n, vector<vector<int>> boxPos, bool hasBox, vector<vector<int>> craneMoves  ){

    /*
        Operators  (AT most we expand -- 4 nodes for each node)

        // Crane already has a container
        - move crane left or right with container (Check walls and within ship or buffer)
        - move up with crane with box (to top container row next to it)
        - Drop off container in column (automatically move crane down)

        //Crane does not already have a container
        - move crane by itself to left or right by one (Within ship or buffer and check walls)
        - pick up container in column
        - move crane up by itself (to top container row next to it)

        // special cases rarely will happen (Using Portals - crane must be at correct zone and portal location)
        -  move crane (by itself) start from ship
        -  move crane (by itself) start from buffer
        -  move crane (by itself) start from truck

        - move crane with container to buffer (Check for walls) or truck (ONLY UNLOADING Container are valid) from ship
        - move crane with container to ship from buffer or truck (loading)
    */
    
    vector<Node> expandedNodesList;

	int startRow = n.prev[0][0];
	int startCol = n.prev[0][1];
	int startZone = n.prev[0][2];
	int startState = n.prev[2][0];

    //Creating nodes (expand)
    for(int i = 0;  i < craneMoves.size(); i++){

        //operators where crane already has a container
        if(startState == 0){
            //move crane left or right with container (Check walls and within ship or buffer)
            craneMovesLeftOrRightWithBox(n, craneMoves, i, expandedNodesList);
        }
		
        //operators where crane DOES NOT already have a container
        else
        {
		//move crane by itself to left or right by one ( Stays Within ship or buffer and check walls)
            justCraneMovesLeftOrRight(n, craneMoves, i, expandedNodesList);
        }
    }
	
        //portal operators
    if(startState == 0){

		//start from ship
    	craneMovesWithBoxStartPortalShip(n, expandedNodesList);	//go to buffer

		// start from buffer
	    craneMovesWithBoxStartPortalBuffer(n, expandedNodesList);	//go to ship

		//start from truck
	    craneMovesWithBoxStartPortalTruck(n, expandedNodesList);
       
    }
	else{
		// move crane (by itself) start from ship
    	justCraneStartPortalShip(n, expandedNodesList);

        // move crane (by itself) start from buffer
        justCraneStartPortalBuffer(n, expandedNodesList);

        // move crane (by itself) start from truck
        justCraneStartPortalTruck(n, expandedNodesList);

    }

    if(startState == 0){
           //Drop off container in column (automatically move crane down)
            craneDropsOffBox(n, expandedNodesList); 
    }else{
         //pick up container in column
            cranePicksUpBox(n, expandedNodesList);
          
    }
	/*
	vector<int> toRemove;
	for(int i = 0; i < expandedNodesList.size(); i++){
		Node tmp = expandedNodesList[i];
		int endRow = tmp.prev[0][0];
		int endCol = tmp.prev[0][1];
		int endZone = tmp.prev[0][2];
		int endState = tmp.prev[2][0];

		if(startRow == endRow && startCol == endCol && startZone == endZone && startState == endState){
			toRemove.push_back(i);
		}
	}
	for(int i = toRemove.size() - 1; i >= 0; i--){
		expandedNodesList.erase(expandedNodesList.begin() + i);
	}
	//*/
    return expandedNodesList;
}







#endif
