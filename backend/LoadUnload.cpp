#include "LoadUnload.hpp"

void LoadUnload::setup(){

}

bool LoadUnload::stateExists(Node currentState){
    for (int i = 0;i < closed.size(); i++) {
        if (closed[i] != currentState)
            return false;
    }
    return true;
}

double LoadUnload::heuristic(Node current){
	vector<vector<Container>> ship = current.ship;
	vector<vector<int>> pos;

	//Shortest time to load containers
	double heur = numToLoad * PORTALTIME;

	//Shortest time to unload containers
	for(int row = 0; row < ship.size(); row++){
		for(int col = 0; col < ship[0].size(); col++){
			if(1 == ship[row][col].status){	//Is removable
				heur += findTopShip(ship, col) - row;
				heur += PORTALTIME;
			}
		}
	}

	//Shortest time to unload buffer
	vector<vector<Container>> buffer = current.buffer;
	for(int row = 0; row < buffer.size(); row++)
		for(int col = 0; col < buffer[0].size(); col++){
			if(0 < buffer[row][col].status){
				heur += PORTALTIME;
			}
		}

	return heur;
}