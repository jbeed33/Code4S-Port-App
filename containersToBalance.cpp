#include<vector>
#include <iostream>
#include "node.hpp"
using namespace std;





vector<vector<int>> containersToBalance(Node n){

   vector<vector<int>> emptySpots;
	vector<vector<int>> boxesToMove;
	vector<vector<int>> colsToReturn; // <startCol, endCol, startZone, endZone>

 
    vector<int> wall(12,0);

    //Scan through top row and detect if there is a wall
    for(int i = 0; i < n.ship[0].size(); i++){
        if(n.ship.at(0).at(i).status != 0){
            wall.at(i) = 1; // there is a wall
        }
    }
	
	for (int i = 0; i < n.ship[0].size(); i++) 
	{ 
		for (int j = 0; j < n.ship.size(); j++) 
		{ 
		    if(n.ship.at(j).at(i).status != 0){
                //if the box is invalid it cannot move
                if(n.ship.at(j).at(i).status != -1){
                    cout << "added box" << endl;
                     boxesToMove.push_back({j,i, 0, 0});
                }
               
                if(j != 0){ // not the top row
                 cout << "added empty space" << endl;
                  emptySpots.push_back({j-1,i, 0, 0});  
                }
                break;
            } else{
                if(j == n.ship.size()-1){ // bottom row
                    emptySpots.push_back({j,i});
                }
            }
			
		}	 
		cout << endl; 
	} 

    cout << "Number of boxes: " << boxesToMove.size() << endl;
    cout << "Number of empty spaces: " << emptySpots.size() << endl;
      // Getting all possible positions
	for(int i = 0; i < boxesToMove.size(); i++){
	    for(int j = 0; j < emptySpots.size(); j++){
	        // they do not start and end at the same column
	        if(boxesToMove.at(i).at(1) != emptySpots.at(j).at(1)){

                // next have to check if there is a wall between them
                int wallsBetween = 0;
                for(int k = boxesToMove.at(i).at(1); k < emptySpots.at(j).at(1)){
                    wallsBetween += wall.at(k);

                }

                if(wallsBetween != 0) colsToReturn.push_back({boxesToMove.at(i).at(1), emptySpots.at(j).at(1), boxesToMove.at(i).at(2), emptySpots.at(j).at(3)});
	        }
	    }
	}

    return colsToReturn;

}
