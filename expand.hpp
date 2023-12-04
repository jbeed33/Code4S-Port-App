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
        else if(zone == 1){ // crane starts from truck
            // take from loading buffer if there is set hasBox to true
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

bool swapContainers(Node &n, int prevX, int prevY, int newX, int newY, int startZone, int endZone){
    
    const Container truckContainer = {"", 0, 2};
    const Container emptyContainer = {"", 0, 2};

    int oldRow = prevY;
    int oldCol = prevX;
    int newRow = newY;
    int newCOl = newX;
    
    Container startContainer;

    //checking to see if we start on the truck and there are no containers left to load.
    if(startZone == 1 && n.numToLoad <= 0) return false;
    
    if(startZone == 0){
        startContainer = n.ship.at(prevY).at(prevX);
    }
    else if(startZone == 2){
        startContainer = n.buffer.at(prevY).at(prevX);
    }
    else if(startZone == 1){
        startContainer = truckContainer;
    }

   
    Container endContainer = emptyContainer;
    if(endZone == 0){
         endContainer = n.ship.at(newY).at(newX);
    }else if(endZone == 2){
         endContainer = n.buffer.at(newY).at(newX);
    }

    

     // if the endzone is truck and start container status != 1
     if(endZone == 1 && startContainer.status != 1) return false;

    // check to see if the new pos.status != 0 
    if(endContainer.status != 0){
         // check for wall
         if(newY == 0) return false;
         newY -= 1; // to move the crane up :)
    }
   
   
    


    //place in correct Zones. The boxes swap places!!!
     if(startZone == 0){
        n.ship.at(prevX).at(prevY) = emptyContainer;
    }
    else if(startZone == 2){
        n.buffer.at(prevX).at(prevY) = emptyContainer;
    }


     if(endZone == 0){
         n.ship.at(newX).at(newY) = startContainer;
    }
    else if(endZone == 2){
        n.buffer.at(newX).at(newY) = startContainer;
    }

    return true;
}

vector<Node> expandNodeBasedOnCraneMovement(Node &n, vector<vector<int>> boxPos, bool hasBox, vector<vector<int>> craneMoves  ){

    //call cost function
    //call hurestic function
    
    vector<Node> expandedNodesList;

    //Creating nodes (expand)
    for(int i = 0; craneMoves.size(); i++){
        //Check to go

        //just crane
        Node newNode = n;
        newNode.cranePos = {craneMoves.at(i).at(0), n.cranePos.second}; //(x,y)
        newNode.craneLocation = craneMoves.at(i).at(2);

        expandedNodesList.push_back(newNode);

        // if starting position crane is able to move a box then we should.
        //Check to see if I am unloading a container that cannot be unloaded.
        
        int craneRow = n.cranePos.first;
        int craneCol = n.cranePos.second;
        if(hasBox){
            
            Node newNodewithBox = n;
          
            //update buffer, ship, or truck

                int oldx = boxPos.at(0).at(0); //col
                int oldy = boxPos.at(0).at(1); //row
                int newx = craneMoves.at(i).at(0); //col
                int newy = craneMoves.at(i).at(0) - 1; //row


                int endZone = craneMoves.at(i).at(2);
            
                if(swapContainers(newNodewithBox, oldx, oldy, newx, newy, n.craneLocation, endZone)){
                    expandedNodesList.push_back(newNodewithBox);
                };

                
        }

        return expandedNodesList;
    }
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
    int craneCol = n.cranePos.first;
    int zone = n.craneLocation;
    boxPos = getContainerDataFromCranePos(n,craneCol, zone );

    if(boxPos.size() > 0){
        hasBox = true;

    }
        
    //Crane movemnt 
     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip );


    //Expand Nodes
    return expandNodeBasedOnCraneMovement(n, boxPos, hasBox, craneMoves);

}

#endif
