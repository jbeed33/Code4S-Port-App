#include "LoadUnload.hpp"

void LoadUnload::setup(Node &current, vector<string> unloadNames){
	const vector<vector<Container>> ship = current.ship;


	for(unsigned int i = 0; i < unloadNames.size(); i++){
		int foundRow = -1;
		int foundCol = -1;
		int best = 256;	//Arbitrary large number
		
		string name = unloadNames[i];
		for(int row = 0; row < SHIPHEIGHT; row++){
			for(int col = 0; col < SHIPWIDTH; col++){
				if(2 == ship[row][col].status){	//Not marked yet
					if(ship[row][col].name == name){	//Can be unloaded
						int tmp = distToPortal(current, row, col);
						if(tmp < best){
							foundRow = row;
							foundCol = col;
							best = tmp;
						}
					}
				}
			}
		}
		if(-1 < foundRow){	//At least one match was found
			current.ship[foundRow][foundCol].status = 1;
		}
	}
}

bool LoadUnload::stateExists(Node currentState){
    int currRow = currentState.cranePos.first;
    int currCol = currentState.cranePos.second;
    int currZone = currentState.craneLocation;
	double currHeur = currentState.heuristic;
    bool currHasContainer = currentState.prev.at(2).at(0);

    
	for (int i = 0; i < closed.size(); i++) {
		if(currRow == closed.at(i).cranePos.first && currCol == closed.at(i).cranePos.second){
			if(currZone == closed.at(i).craneLocation && currHasContainer == closed.at(i).prev.at(2).at(0)){
				if(false == compareStateStatus(currentState.ship, closed[i].ship) && false == compareStateStatus(currentState.buffer, closed[i].buffer))
					return true;
			}
		}
	}
    return false;
}

double LoadUnload::heuristic(Node current){
	vector<vector<Container>> ship = current.ship;
	vector<vector<int>> pos;

	//Shortest time to load containers
	double heur = distBetweenPoints(0, 0, 1, current.cranePos.first, current.cranePos.second, current.craneLocation) * current.numToLoad;

	//Shortest time to unload containers
	for(int row = 0; row < ship.size(); row++){
		for(int col = 0; col < ship[0].size(); col++){
			if(1 == ship[row][col].status){	//Is removable
				heur += col + findTopShip(ship, col) - row;
				heur += PORTALTIME;
				heur += max(current.cranePos.second, col) - min(current.cranePos.second, col);
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
	//if(1 == current.craneLocation)
		//printf("cost %d\theur %f\trow %d\tcol %d\tzone %d\tjustCrane %d\n", current.cost, heur, current.cranePos.first, current.cranePos.second, current.craneLocation, current.prev[2][0]);
	return heur;
}