#include<vector>
#include "node.hpp"
using namespace std;





vector<vector<int>> containersToBalance(Node n){

    vector<vector<int>> validSpots;
    
    vector<vector<int>> boxesToMove;
    vector<vector<int>> colsToReturn;

    //Algorithm only uses the ship does not use buffer yet.
    
    int emptySpace = NULL;
    //find all avaliable spaces that are valid to move
   for(int i = 0; i < n.ship.size(); i++){
            for(int j = 0; j < n.ship.at(0).size(); j++){

                if(n.ship.at(i).at(j) == emptySpace){ // if space is empty
                    if(i ==  n.ship.size() - 1){ // the bottom row
                        validSpots.push_back({i,j});
                    }
                    else{
                        //other rows
                        if(n.ship.at(i + 1).at(j) != emptySpace) validSpots.push_back({i,j});
                    }
                }
                else if(n.ship.at(i).at(j) != emptySpace){
                    if(i == 0){ // the top row
                        boxesToMove.push_back({i,j});
                    }
                    else{ // not top row
                        //there must not be a box above it
                        if(n.ship.at(i - 1).at(j) == emptySpace) boxesToMove.push_back({i,j});
                    }
                }
            }
        }

    // get the vectors <startCol, endCol>
    for(int i = 0; i < boxesToMove.size(); i++){
        for(int j = 0; j < validSpots.size(); j++){

            //Does not put the same container in the same column.
            if(boxesToMove.at(i).at(2) != validSpots.at(j).at(2)){
                colsToReturn.push_back({boxesToMove.at(i).at(2), validSpots.at(j).at(2)});
            }

        }
    }

    
    return colsToReturn;


}