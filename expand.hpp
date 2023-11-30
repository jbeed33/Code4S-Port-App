#include "node.hpp"
#include <iostream>
#include<vector>
#include<cmath>
using namespace std;

// 0 - ship 1-buffer
vector<int> getWallsForZone(Node &n, int zone ){
    //Get all avaliable columns from buffer and ship
    
    

    //Scan through top row and detect if there is a wall for ship
    if(zone == 0){
        vector<int> avaliableColsForShip(12,0);
         for(int i = 0; i < n.ship[0].size(); i++){
            if(n.ship.at(0).at(i).status != 0){
                avaliableColsForShip.at(i) = 1; // there is a wall
            }
        }

        return avaliableColsForShip;
    }
    else{
        vector<int> avaliableColsForBuffer(24,0);

         //Scan through top row and detect if there is a wall for buffer
        for(int i = 0; i < n.buffer[0].size(); i++){
            if(n.buffer.at(0).at(i).status != 0){
                avaliableColsForBuffer.at(i) = 1; // there is a wall
            }
        }

        return avaliableColsForBuffer;
    }

}

vector<vector<int>> getContainerDataFromCranePos(Node& n, int craneCol, int zone){

    vector<vector<int>> boxPos;

        if(zone == 0){ //crane starts from ship
            for (int j = 0; j < n.ship.size(); j++) 
		    { 
                if(n.ship.at(j).at(craneCol).status != 0){
                    boxPos.push_back({j, craneCol});
                    break;
                }
			
		    }
        }
        else if(zone == 2){ //crane starts from buffer
            for (int j = 0; j < n.buffer.size(); j++) 
		    { 
                if(n.buffer.at(j).at(craneCol).status != 0){
                    boxPos.push_back({j, craneCol});
                    break;
                }
			
		    }
        }
        else if(zone == 1){ // crane starts from truck
            // take from loading buffer if there is set hasBox to true
        }
}

int FindEmptySpotInCol(Node &n, int col, int zone){
    
    if(zone == 0){ //ship
		for (int j = 0; j < n.ship.size(); j++) 
		{ 
		    if(n.ship.at(j).at(col).status != 0){
                
                if(j != 0){ // not the top row
                  return j-1;  
                }
                break;
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
                
                if(j != 0){ // not the top row
                  return j-1;  
                }
                break;
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

            if(n.craneLocation == 0){ //crane starts from ship
           // keep moving left until we either reach column zero or find an avaliable spot
           int index = n.cranePos.first;
           while(index > -1){
                
                if(index == 0){

                    //buffer - need to move left until can find a position that is avaliable
                    for(int bufferColIndex = 23; bufferColIndex >= 0; bufferColIndex--){
                        if(avaliableColsForBuffer.at(bufferColIndex) == 0){
                             craneMovement.push_back({bufferColIndex, 2});
                             break;
                        }
                    }
                    
                    //truck not sure about the index it should what column number it should have
                     craneMovement.push_back({index, 1});
                     index = -1; //break
                    
                }
                else if(avaliableColsForShip.at(index) == 0){ // case of not first column, continue left until you find an avaliable spot
                    craneMovement.push_back({index, 0});
                    index = -1; //break
                }

                index--;
           }
           

           //try right
            index = n.cranePos.first;
            while(index < 11){
                
                if(avaliableColsForShip.at(index) == 0){
                    craneMovement.push_back({index, 0});
                    index = 12; //break;
                }

                index++;
           }

        }
        else if(n.craneLocation == 2){ //crane starts from buffer

           // keep moving right until we either reach last column or find an avaliable spot
           int index = n.cranePos.first;
           while(index < 24){
                
                if(index == 23){

                    //Ship - need to move right until can find a position that is avaliable
                    for(int shipColIndex = 0; shipColIndex < n.ship.size(); shipColIndex++){
                        if(avaliableColsForShip.at(shipColIndex) == 0){
                             craneMovement.push_back({shipColIndex, 0});
                             break;
                        }
                    }
                    
                    //truck not sure about the index it should what column number it should have
                     craneMovement.push_back({index, 1});
                     index = 25; //break
                    
                }
                else if(avaliableColsForBuffer.at(index) == 0){ // case of not first column, continue left until you find an avaliable spot
                    craneMovement.push_back({index, 0});
                    index = 25; //break
                }

                index++;
           }
           

           //try left
           index = n.cranePos.first;
            while(index  > -1){
                
                if(avaliableColsForBuffer.at(index) == 0){
                    craneMovement.push_back({index, 0});
                    index = -1;
                }

                index--;
           }

        }
        else if(n.craneLocation == 1){ // crane starts from truck
            // try left
            //buffer - need to move left until can find a position that is avaliable
            for(int bufferColIndex = 23; bufferColIndex >= 0; bufferColIndex--){
                if(avaliableColsForBuffer.at(bufferColIndex) == 0){
                        craneMovement.push_back({bufferColIndex, 2});
                        break;
                    }
            }
            
                    
            //try right
            //Ship - need to move right until can find a position that is avaliable
                for(int shipColIndex = 0; shipColIndex < n.ship.size(); shipColIndex++){
                    if(avaliableColsForShip.at(shipColIndex) == 0){
                        craneMovement.push_back({shipColIndex, 0});
                        break;
                        }
                }
        }
}

void swapContainers(Node &n, int prevX, int prevY, int newX, int newY, int startZone, int endZone){
    
    
    Container startContainer;
    Container endContainer;

    
    if(startZone == 0){
        startContainer = n.ship.at(prevX).at(prevY);
    }
    else if(startZone == 2){
        startContainer = n.buffer.at(prevX).at(prevY);
    }
    else if(startZone == 1){
        //truck
    }

     if(endZone == 0){
        endContainer = n.ship.at(newX).at(newY);
    }
    else if(endZone == 2){
        endContainer = n.buffer.at(newX).at(newY);
    }
    else if(endZone == 1){
        //truck
    }

    //place in correct Zones. The boxes swap places!!!
     if(startZone == 0){
        n.ship.at(prevX).at(prevY) = endContainer;
    }
    else if(startZone == 2){
        n.buffer.at(prevX).at(prevY) = endContainer;
    }
    else if(startZone == 1){
        //truck
    }

     if(endZone == 0){
         n.ship.at(newX).at(newY) = startContainer;
    }
    else if(endZone == 2){
        n.buffer.at(newX).at(newY) = startContainer;
    }
    else if(endZone == 1){
        //truck
    }


    


}

vector<Node> expandNode(Node &n, vector<vector<int>> boxPos, bool hasBox, vector<vector<int>> craneMoves  ){

    //call cost function
    //call hurestic function
    
    vector<Node> expandedNodesList;

    //Creating nodes (expand)
    for(int i = 0; craneMoves.size(); i++){
        //Check to go

        //just crane
        Node newNode = n;
        newNode.cranePos = {craneMoves.at(i).at(0), n.cranePos.second}; //(x,y)
        newNode.craneLocation = craneMoves.at(i).at(1);

        expandedNodesList.push_back(newNode);

        // if starting position crane is able to move a box then we should.
        //Check to see if I am unloading a container that cannot be unloaded
        
        if(hasBox){
            Node newNodewithBox = n;
          
            //update buffer, ship, or truck

                int oldx = boxPos.at(0).at(0);
                int oldy = boxPos.at(0).at(1);
                int newx = craneMoves.at(i).at(0);
                int newy = FindEmptySpotInCol(n, newx, craneMoves.at(i).at(1)); 
            
                swapContainers(newNodewithBox, oldx, oldy, newx, newy, n.craneLocation, craneMoves.at(i).at(1));

                expandedNodesList.push_back(newNodewithBox);
        }

    return expandedNodesList;
}



vector<Node> expandNodeBasedOnCraneMovement(Node n){
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

        if(zone == 0){ //ship
           box = n.ship.at(boxPos.at(0).at(0)).at(boxPos.at(0).at(1));
        }
        else if(zone == 2){ //buffer
          box = n.buffer.at(boxPos.at(0).at(0)).at(boxPos.at(0).at(1));
        }
    }
        

    //Crane movemnt 
     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip );


    //Expand Nodes
    return expandNode(n, boxPos, hasBox, craneMoves);
    
    
    //if at the truck goes left buffer, right is the ship

    // store vector<postions, zones> -> Nodes

    // with: crane startCol boxes -> magic -> node -> update ship / buffer as need
    // if the box, unloadable -> truck -> update ship / buffer

}
