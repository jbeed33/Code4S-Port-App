#ifndef EXPAND_H
#define EXPAND_h

#include "node.hpp"
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

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
    }
    else{ // truck
        return 1;
    }
		 
}

int findTopContainerInColWithStartingRow(Node &n, int col, int zone, int startRow){
    //returns the row of emtpy spot

    if(zone == 0){ //ship
		for (int j = startRow; j < n.ship.size(); j++) 
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
        for (int j = startRow; j < n.buffer.size(); j++) 
		{ 
		    if(n.buffer.at(j).at(col).status != 0){
                
              return j;
            } else{
                if(j == n.buffer.size()-1){ // bottom row
                    return j;
                }
            }
			
		}
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
                
                if(craneCol == 0){
                    
                    //buffer - need to move left until can find a position that is avaliable
                    int bufferColIndex = n.buffer[0].size() - 1;
                        
                     craneMovement.push_back({0,bufferColIndex, 2});
                    
                    //truck not sure about the index it should what column number it should have
                     craneMovement.push_back({1,0, 1});
                   
                    
                }
                else{ // case of not first column, try left
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

                    if(craneCol < n.ship.size() - 1){
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
                if(craneCol == n.buffer.size() - 1){

                    //ship - need to move right 
                    int bufferColIndex = 0;
                        
                     craneMovement.push_back({0,bufferColIndex, 0});
                    
                    
                    //truck not sure about the index it should what column number it should have
                     craneMovement.push_back({1,0, 1});
                   
                    
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

    cout << "start container name: " << startContainer.name << endl;

   
    cout << "Made it passed startContainer" << endl;
    Container endContainer = emptyContainer;
    if(endZone == 0){
        endContainer = n.ship.at(newRow).at(newCol);
    }else if(endZone == 2){
         endContainer = n.buffer.at(newRow).at(newCol);
    }

    cout << "end container name: " << endContainer.name << endl;

    cout << "Made it passed endContainer" << endl;

     // if the endzone is truck and start container status != 1
     if(endZone == 1 && startContainer.status != 1) return false;

    // // check to see if the new pos.status != 0 
    // if(endContainer.status > 0){
    //     cout << "inside special case" << endl;
    //      // check for wall
    //      if(newRow == 0){
    //          return false;
    //      }
    //      newRow -= 1; // to move the crane up :)
    //      cout << "New row after special case: " << newRow << endl;
    // }

    cout << "Made it passed the checks" << endl;
   
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
    cout << "made it passed swap containers" << endl;

    return true;
}

/*The following bottom functions are the operators*/ 

void justCraneMovesLeftOrRight(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList ){
     Node op4 = n;
     int sizeToCheck = (n.craneLocation == 0) ? n.ship[0].size() : n.buffer[0].size();
     bool isValidMove = (craneMoves.at(indexCraneMove).at(1) > 0 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1)) || (craneMoves.at(indexCraneMove).at(1) < sizeToCheck && n.cranePos.second  < craneMoves.at(indexCraneMove).at(1));
    

    //move crane left or right
    if(isValidMove){
        op4.cranePos = {op4.cranePos.first, craneMoves.at(indexCraneMove).at(1)};
        op4.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1), craneMoves.at(indexCraneMove).at(2)}}, {1} };
        expandedNodesList.push_back(op4);
    }
    
}

void justCraneMoveUp(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    int sizeToCheck = (n.craneLocation == 0) ? n.ship[0].size() : n.buffer[0].size();
    bool canMove = (craneMoves.at(indexCraneMove).at(1) > 0 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1)) || (craneMoves.at(indexCraneMove).at(1) < sizeToCheck && n.cranePos.second  < craneMoves.at(indexCraneMove).at(1));
    cout << "canMove: " << canMove << endl;
    

    Node op6 = n;

    if(op6.craneLocation == 0){
      
        if(canMove && op6.ship.at( op6.ship.size() - 1).at(craneMoves.at(indexCraneMove).at(1)).status > 0 ){ // column has a container
            int newRow = findTopContainerInCol(op6, craneMoves.at(indexCraneMove).at(1), op6.craneLocation);
            //only move up
            if(newRow  < op6.cranePos.first){
                 op6.cranePos = {newRow, op6.cranePos.second};
                 op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{craneMoves.at(indexCraneMove).at(0), n.cranePos.second, n.craneLocation}}, {1} };
                 expandedNodesList.push_back(op6);
            }
           
        }  
   }

    if(op6.craneLocation == 2){
        if(canMove && op6.buffer.at( op6.buffer.size() - 1).at(craneMoves.at(indexCraneMove).at(1)).status > 0 ){ // column has a container
            int newRow = findTopContainerInCol(op6, craneMoves.at(indexCraneMove).at(1), op6.craneLocation);
             //only move up
            if(newRow > op6.cranePos.first){
                 op6.cranePos = {newRow, op6.cranePos.second};
                 op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{craneMoves.at(indexCraneMove).at(0), n.cranePos.second, n.craneLocation}}, {1} };
                 expandedNodesList.push_back(op6);
            }
        } 
    }
               
}

void justCraneStartPortalShip(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;

    // crane must start on ship's location (0,0)
    if(n.craneLocation == 0 && n.cranePos.first == 0 && n.cranePos.second == 0){

        //try to move to truck
        if(craneMoves.at(indexCraneMove).at(2) == 1){
            n1.cranePos = {1, 0};
            n1.craneLocation = craneMoves.at(indexCraneMove).at(2);
            n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{1, 0, craneMoves.at(indexCraneMove).at(2)}}, {1} };
            expandedNodesList.push_back(n1);
        }
        else{
            //try move to move to buffer portal

            //check to see if buffer portal is empty and end location is buffer zone
             if( craneMoves.at(indexCraneMove).at(2) == 2){
                 n1.cranePos = { 0, n.buffer[0].size() - 1};
                 n1.craneLocation = craneMoves.at(indexCraneMove).at(2);
                 n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{0, n.buffer[0].size() - 1, craneMoves.at(indexCraneMove).at(2)}}, {1} };
                 expandedNodesList.push_back(n1);
             }

        }



        
    }
}

void justCraneStartPortalBuffer(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;

    // crane must start on buffer's location (0, size of buffer)
    if(n.craneLocation == 2 && n.cranePos.first == 0 && n.cranePos.second == n.buffer[0].size() - 1){

        //try to move to truck
        if(craneMoves.at(indexCraneMove).at(2) == 1){
            n1.cranePos = {1, 0};
            n1.craneLocation = 1;
            n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{1, 0, craneMoves.at(indexCraneMove).at(2)}}, {1} };
            expandedNodesList.push_back(n1);
        }
        else{
            //try move to move to ship portal

            //check to see if end zone is ship
             if(craneMoves.at(indexCraneMove).at(2) == 0){
                 n1.cranePos = {0, 0};
                 n1.craneLocation = 0;
                 n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{0, 0, craneMoves.at(indexCraneMove).at(2)}}, {1} };
                 expandedNodesList.push_back(n1);
             }

        }



        
    }
}

void justCraneStartPortalTruck(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;

    // crane must start on trucks's location (0, size of buffer)
    if(n.craneLocation == 1 && n.cranePos.first == 1 && n.cranePos.second == 0){

        //try to move to buffer
        if(craneMoves.at(indexCraneMove).at(2) == 2 ){
                n1.cranePos = {0, n1.buffer[0].size() -1 };
                n1.craneLocation = 2;
                n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{0, n1.buffer[0].size() -1, craneMoves.at(indexCraneMove).at(2)}}, {1} };
                expandedNodesList.push_back(n1);
        }
        else{
            //try move to move to ship portal

            if(craneMoves.at(indexCraneMove).at(2) == 0 ){
                n1.cranePos = {0, 0};
                n1.craneLocation = 0;
                n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{0,0, craneMoves.at(indexCraneMove).at(2)}}, {1} };
                expandedNodesList.push_back(n1);
            }

        }



        
    }
}

void craneMovesUpWithBox(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
   
    int sizeToCheck = (n.craneLocation == 0) ? n.ship[0].size() : n.buffer[0].size();
    bool canMove = (craneMoves.at(indexCraneMove).at(1) > 0 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1)) || (craneMoves.at(indexCraneMove).at(1) < sizeToCheck && n.cranePos.second  < craneMoves.at(indexCraneMove).at(1));
    cout << "canMove: " << canMove << endl;

    Node op6 = n;

    if(n.craneLocation == 0){
      
        if(canMove && op6.ship.at( op6.ship.size() - 1).at(craneMoves.at(indexCraneMove).at(1)).status > 0 ){ // column has a container
            int newRow = findTopContainerInCol(op6, craneMoves.at(indexCraneMove).at(1), op6.craneLocation) - 1; // move it up by 1
            if(newRow < 0) newRow = 0;
            //only move up
            if(newRow < op6.cranePos.first){

                 // if its unloadable container just bring it up to the top of container
                if(op6.ship.at(op6.cranePos.first).at(op6.cranePos.second).status == 1){
                   
                    newRow = 0;
                }

                swapContainers(op6, op6.cranePos.first, op6.cranePos.second, newRow, op6.cranePos.second, op6.craneLocation, op6.craneLocation);
                 op6.cranePos = {newRow, op6.cranePos.second};
                 op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{newRow, op6.cranePos.second, n.craneLocation}}, {0} };
                 expandedNodesList.push_back(op6);
            }
           
        }else{
            // end col does not have any containers
                int newRow = 0;
                swapContainers(op6, op6.cranePos.first, op6.cranePos.second, newRow, op6.cranePos.second, op6.craneLocation, op6.craneLocation);
                 op6.cranePos = {newRow, op6.cranePos.second};
                 op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{newRow, op6.cranePos.second, n.craneLocation}}, {0} };
                 expandedNodesList.push_back(op6);
        } 
   }

    if(n.craneLocation == 2){
        if(canMove && op6.buffer.at( op6.buffer.size() - 1).at(craneMoves.at(indexCraneMove).at(1)).status > 0 ){ // column has a container
             int newRow = findTopContainerInCol(op6, craneMoves.at(indexCraneMove).at(1), op6.craneLocation) - 1; // move it up by 1
            if(newRow < 0) newRow = 0;

            //only move up
            if(newRow < op6.cranePos.first){
                // if its unloadable container just bring it up to the top of container
                if(op6.buffer.at(op6.cranePos.first).at(op6.cranePos.second).status == 1){
                    newRow = 0;
                }

            
                swapContainers(op6, op6.cranePos.first, op6.cranePos.second, newRow, op6.cranePos.second, op6.craneLocation, op6.craneLocation);
                op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{newRow, op6.cranePos.second, n.craneLocation}}, {0} };
                 op6.cranePos = {newRow, op6.cranePos.second};
                 expandedNodesList.push_back(op6);
            }
           
        }else{
            // end col does not have any containers
                int newRow = 0;
                swapContainers(op6, op6.cranePos.first, op6.cranePos.second, newRow, op6.cranePos.second, op6.craneLocation, op6.craneLocation);
                 op6.cranePos = {newRow, op6.cranePos.second};
                 op6.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{newRow, op6.cranePos.second, n.craneLocation}}, {0} };
                 expandedNodesList.push_back(op6);
        } 
    }
}

void craneMovesLeftOrRightWithBox(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node op1 = n;
    int sizeToCheck = (n.craneLocation == 0) ? n.ship[0].size() : n.buffer[0].size();
    bool canMove = (craneMoves.at(indexCraneMove).at(1) > 0 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1)) || (craneMoves.at(indexCraneMove).at(1) < sizeToCheck && n.cranePos.second  < craneMoves.at(indexCraneMove).at(1));
    cout << "canMove: " << canMove << endl;

    //checking for wall only checking one to the left and right of crane (Within ship and buffer only test)
     bool isValidMove = (
        canMove &&
        (n.craneLocation == 0 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1) && n.ship.at(n.cranePos.first).at(n.cranePos.second - 1).status == 0   || // on ship crane moves left
        n.craneLocation == 0 &&  n.cranePos.second < craneMoves.at(indexCraneMove).at(1) && n.ship.at(n.cranePos.first).at(n.cranePos.second + 1).status == 0   ||
        n.craneLocation == 2 && n.cranePos.second > craneMoves.at(indexCraneMove).at(1)  && n.buffer.at(n.cranePos.first).at(n.cranePos.second - 1).status == 0 ||
        n.craneLocation == 2 && n.cranePos.second < craneMoves.at(indexCraneMove).at(1)  && n.buffer.at(n.cranePos.first).at(n.cranePos.second + 1).status == 0  )
    );
    
    if( n.craneLocation == 0){
        if(isValidMove){
            if(n.ship.at(op1.cranePos.first).at(craneMoves.at(indexCraneMove).at(1)).status == 0){
                swapContainers(op1, n.cranePos.first, n.cranePos.second, craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1), n.craneLocation, n.craneLocation);
                op1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1), craneMoves.at(indexCraneMove).at(2)}}, {0} };
                expandedNodesList.push_back(op1);
            }
        }
       
                    
    }
                
    //buffer
    if( n.craneLocation == 2){
         if(isValidMove){
            if(n.buffer.at(op1.cranePos.first).at(craneMoves.at(indexCraneMove).at(1)).status == 0){
                swapContainers(op1, n.cranePos.first, n.cranePos.second, craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1), n.craneLocation, n.craneLocation);
                op1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1), craneMoves.at(indexCraneMove).at(2)}}, {0} };
                expandedNodesList.push_back(op1);
            }
         } 
    }
}

void craneMovesWithBoxStartPortalShip(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;
    // crane must start on ship's location (0,0)
    if(n.craneLocation == 0 && n.cranePos.first == 0 && n.cranePos.second == 0){
        //try to move to truck and container is unloadable
        if(craneMoves.at(indexCraneMove).at(2) == 1 && n.ship.at(0).at(0).status == 1){
            swapContainers(n1, n1.cranePos.first, n1.cranePos.second, 1, 0, n1.craneLocation, craneMoves.at(indexCraneMove).at(2));
            n1.cranePos = {craneMoves.at(indexCraneMove).at(0), craneMoves.at(indexCraneMove).at(1) };
            n1.craneLocation = craneMoves.at(indexCraneMove).at(2);
            n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{1, 0, 1}}, {0} };
            expandedNodesList.push_back(n1);
        }
        else{
            //try move to move to buffer portal

            //check to see if buffer portal is empty
             if(n1.buffer.at(0).at(n1.buffer[0].size() -1).status == 0){
                 swapContainers(n1, n1.cranePos.first, n1.cranePos.second, 0,  n.buffer[0].size() - 1, n1.craneLocation, craneMoves.at(indexCraneMove).at(2));
                 n1.cranePos = { 0, n.buffer[0].size() - 1};
                 n1.craneLocation = 2;
                 n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{ 0, n1.buffer[0].size() - 1, 2}}, {0} };
                 expandedNodesList.push_back(n1);
             }

        }



        
    }
}

void craneMovesWithBoxStartPortalBuffer(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;
    //only move box to ship

    //check to see if we are starting from buffer portal
    if(n.craneLocation == 2 && n.cranePos.first == 0 && n.cranePos.second == n.buffer[0].size() - 1){

        //check to see if ship portal is empty
        if(n1.ship.at(0).at(0).status == 0){
            swapContainers(n1, n1.cranePos.first, n1.cranePos.second, 0, 0, n1.craneLocation, 0);
            n1.cranePos = {0, 0 };
            n1.craneLocation = 0;
            n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{ 0, 0, 0}}, {0} };
            expandedNodesList.push_back(n1);
        }
    }


}

void craneMovesWithBoxStartPortalTruck(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){
    Node n1 = n;
    //only move box to ship

    //check to see if we are starting from truck portal
    if(n.craneLocation == 1 && n.cranePos.first == 1 && n.cranePos.second == 0){

        //check to see if ship portal is empty and there are containers to load
        if(n1.ship.at(0).at(0).status == 0 && n1.numToLoad > 0){
            swapContainers(n, n1.cranePos.first, n1.cranePos.second, 0, 0, n1.craneLocation, craneMoves.at(indexCraneMove).at(2));
            n1.cranePos = {0, 0};
            n1.craneLocation = 0;
            n1.numToLoad -= 1;
            n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{ 0, 0, 0}}, {0} };
            expandedNodesList.push_back(n1);
            
        }
    }




}


void craneDropsOffBox(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){

    Node n1 = n;
    int newRow = findTopContainerInColWithStartingRow(n1, n1.cranePos.second, n1.craneLocation, n1.cranePos.first + 1);
   
    if(newRow != n.cranePos.first){
        newRow -= 1;
    }
     cout << "new row: " << newRow << endl;
    swapContainers(n1, n1.cranePos.first, n1.cranePos.second, newRow, n1.cranePos.second, n1.craneLocation, n1.craneLocation);
    n1.cranePos = {newRow, n1.cranePos.second};

    //update prev
    n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{n1.cranePos.first, n1.cranePos.second, n1.craneLocation}}, {1} };

    expandedNodesList.push_back(n1);
}

void cranePicksUpBox(Node &n, vector<vector<int>> craneMoves, int indexCraneMove, vector<Node> &expandedNodesList){

    Node n1 = n;
    int newRow = findTopContainerInColWithStartingRow(n1, n1.cranePos.second, n1.craneLocation, n1.cranePos.first + 1);
   
    if(newRow != n.cranePos.first){
        newRow -= 1;
    }
     cout << "new row: " << newRow << endl;
    swapContainers(n1, n1.cranePos.first, n1.cranePos.second, newRow, n1.cranePos.second, n1.craneLocation, n1.craneLocation);
    n1.cranePos = {newRow, n1.cranePos.second};

    //update prev
    n1.prev = {{n.cranePos.first, n.cranePos.second, n.craneLocation}, {{n1.cranePos.first, n1.cranePos.second, n1.craneLocation}}, {0} };

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

    //Creating nodes (expand)
    for(int i = 0;  i < craneMoves.size(); i++){

        //operators where crane already has a container
        if(n.prev.at(2).at(0) == 0){
        

            //move crane left or right with container (Check walls and within ship or buffer)
            craneMovesLeftOrRightWithBox(n, craneMoves, i, expandedNodesList);

            //move up with crane with box (to top container row next to it)
            craneMovesUpWithBox(n, craneMoves, i, expandedNodesList);
           
            //Drop off container in column (automatically move crane down)
            craneDropsOffBox(n, craneMoves, i, expandedNodesList);

           
                   
            
        }
        else
        {
        //operators where crane DOES NOT already have a container

            //move crane by itself to left or right by one ( Stays Within ship or buffer and check walls)
            justCraneMovesLeftOrRight(n, craneMoves, i, expandedNodesList);
                

            //pick up container in column
            cranePicksUpBox(n, craneMoves, i, expandedNodesList);
            
            //move crane up by itself (to top container row next to it)
            justCraneMoveUp(n, craneMoves, i, expandedNodesList);

        }
    
    
        //portal operators
         if(n.prev.at(2).at(0) == 0){

           ///start from ship
           craneMovesWithBoxStartPortalShip(n, craneMoves, i, expandedNodesList);

           // start from buffer
           craneMovesWithBoxStartPortalBuffer(n, craneMoves, i, expandedNodesList);

           //start from truck
           craneMovesWithBoxStartPortalTruck(n, craneMoves, i, expandedNodesList);
           
         }
         else{
            // move crane (by itself) start from ship
            justCraneStartPortalShip(n, craneMoves, i, expandedNodesList);

            // move crane (by itself) start from buffer
            justCraneStartPortalBuffer(n, craneMoves, i, expandedNodesList);

            // move crane (by itself) start from truck
            justCraneStartPortalTruck(n, craneMoves, i, expandedNodesList);

         }
    
    }

    return expandedNodesList;
}



vector<Node> expandNode(Node n){
    // 0 - ship
    // 1 - truck
    // 2 - buffer

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);


    
    //check to see if the crane start col has a box to move
    bool hasBox = false;
    vector<vector<int>> boxPos;
    Container box;
    int craneCol = n.cranePos.second;
    cout << craneCol << endl;
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


    //Expand Nodes
    vector<Node> returnedNodes = expandNodeBasedOnCraneMovement(n, boxPos, hasBox, craneMoves);

    //For each Node - call cost and heurstic

    return returnedNodes;

}

#endif
