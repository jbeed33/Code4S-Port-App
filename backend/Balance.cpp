#include "Balance.hpp"


void Balance::setup(Node &current, vector<string> unusedInBalance){
    useSift = requireSift(current);
}


bool Balance::stateExists(Node currentState){
    int currRow = currentState.cranePos.first;
    int currCol = currentState.cranePos.second;
    int currZone = currentState.craneLocation;
	double currHeur = currentState.heuristic;
    bool currHasContainer = currentState.prev.at(2).at(0);

    
	for (int i = 0; i < closed.size(); i++) {
		if(currRow == closed.at(i).cranePos.first && currCol == closed.at(i).cranePos.second){
			if(currZone == closed.at(i).craneLocation && currHasContainer == closed.at(i).prev.at(2).at(0)){
				if(false == compareStateWeights(currentState.ship, closed[i].ship) && false == compareStateWeights(currentState.buffer, closed[i].buffer))
					return true;
			}
		}
	}
    return false;
}


/*double Balance::siftHeuristic(Node current){
	double incorrect = 0;
	vector<vector<Container>> ship = current.ship;
	//Loop Through goal state cells
	for(int goalRow = 0; goalRow < SHIPHEIGHT; goalRow++){	//Start at the bottom of the ship
		for(int goalCol = 0; goalCol < SHIPWIDTH; goalCol++){
			int weight = siftGoal[goalRow][goalCol];
			int best = 256;
			int foundRow = -1;
			int foundCol = -1;
			if(-1 < weight){	//Don't need to find distance to empty cell
				//loop through ship cells to find shortest move to valid goal cell
				for(int row = 0; row < SHIPHEIGHT; row++){
					for(int col = 0; col < SHIPWIDTH; col++){
						if(2 == ship[row][col].status){	//Not marked yet
							if(ship[row][col].weight == weight){	//Can be placed in current goal cell
								int tmp = (row - goalRow) + (col - goalCol);
								if(tmp < best){
									foundRow = row;
									foundCol = col;
									best = tmp;
								}
							}
						}
					}
				}
				if(-1 == foundRow){	//At least one match was found
					foundRow = 0;
					foundCol = 0 - PORTALTIME;
				}
				ship[foundRow][foundCol].status = 1;	//Marks the container as used	|	Doesn't change the node's ship
				incorrect += sqrt(pow(foundRow - goalRow, 2) + pow(foundCol - goalCol, 2));	//euclidean distance
			}
		}
	}
	return incorrect;
}*/

double Balance::siftHeuristic(Node current){
	
	double incorrect = 0;
	
	//incorrect += findAverageDistanceToCrane(current);
	vector<vector<Container>> ship = current.ship;
	//Loop Through goal state cells
	for(int goalRow = 0; goalRow < SHIPHEIGHT; goalRow++){	//Start at the bottom of the ship
		for(int goalCol = 0; goalCol < SHIPWIDTH; goalCol++){
			int weight = siftGoal[goalRow][goalCol];
			int best = 256;
			int foundRow = -1;
			int foundCol = -1;
			int foundZone = -1;
			if(-1 < weight){	//Don't need to find distance to empty cell
				//loop through ship cells to find shortest move to valid goal cell
				for (int j = 0; j < SHIPWIDTH; j++) {
					for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 						if (2 == current.ship[i][j].status){
							if(weight == current.ship[i][j].weight){
								int tmp = distBetweenPoints(SHIPHEIGHT / 2, SHIPWIDTH / 2, 0, i, j, 0);
								if(tmp < best){
									foundRow = i;
									foundCol = j;
									foundZone = 0;
									best = tmp;
								}
							}
						}
						else if(0 == current.ship[i][j].status){	//No more containers in column
							break;
						}
 					}
 				}
 				for (int j = 0; j < BUFFERWIDTH; j++) {
					for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
 						if (2 == current.buffer[i][j].status){
							if(weight == current.buffer[i][j].weight){
								int tmp = distBetweenPoints(BUFFERHEIGHT / 2, BUFFERWIDTH / 2, 2, i, j, 0);
								if(tmp < best){
									foundRow = i;
									foundCol = j;
									foundZone = 2;
									best = tmp;
								}
							}
						}
						else if(0 == current.buffer[i][j].status){
							break;
						}
 					}
 				}
				if(-1 < foundZone){	//At least one match was found
					if(0 == foundZone)
						ship[foundRow][foundCol].status = 1;	//Marks the container as used	|	Doesn't change the node's ship
					else{
						ship[foundRow][foundCol].status = 1;
					}
					incorrect += best;
				}
			}
		}
	}
	return incorrect;
}

double Balance::heuristic(Node n){
	if(true == useSift)
		return siftHeuristic(n);

	if(true == balanceGoalTest(n))
		return 0.0;

	double heur = 0.0;
	heur += findAverageDistanceToCrane(n);
	heur += findDistanceToBalanced(n);
	return heur;
}

/*double Balance::heuristic(Node n){
	if(true == useSift){
		return siftHeuristic(n);
	}
	int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    double h = 0.0;

    if(balanceGoalTest(n) == true){
        return 0.0;
    }
    else{
         h+=1;
    }
    
    //check to see if top of the ship is empty
    for(int i = 0; i < n.ship[0].size(); i++){
        if(n.ship.at(0).at(i).status > 0){
            h+= 2;
        }
    }

    //check to see if the buffers empty
    for(int i = 0; i < n.buffer.size(); i++){
        for(int j = 0; j < n.buffer[0].size(); j++){
             if(n.buffer.at(i).at(j).status > 0){
                h+=5;
                
            }
        }
       
    }
    //check to see if the crane is still holding a box on ship
    if(startZone == 0 && n.ship.at(startRow).at(startCol).status > 0){
        if(startRow + 1 < SHIPHEIGHT){
            if(n.ship.at(startRow + 1).at(startCol).status < 1){
                h += 2;
            }
        }
    }

    //checking to see if crane is holding a box in the buffer zone.
    if(startZone == 2 && n.buffer.at(startRow).at(startCol).status > 0){
        if(startRow + 1 < BUFFERHEIGHT){
            if(n.buffer.at(startRow + 1).at(startCol).status < 1){
                h += PORTALTIME * 100;
            }
        }
    }
    
    if(n.prev.at(2).at(0) == 0) h+= 1;

    //check for balance
    int mid = n.ship[0].size() / 2;
    double left = 0.0;
    double right = 0.0;

    for (int i = 0; i < n.ship[0].size(); i++) {
        for (int j = 0; j < n.ship.size(); j++) {
            // Accumulate weights on the left side
            if (i < mid) {
                left += n.ship[j][i].weight;
            }
            // Accumulate weights on the right side
            else {
                right += n.ship[j][i].weight;
            }
        }
    }

    if( min(right,left) > 0){
         h += (1  / ( min(right,left) / max(right,left)));
         
    }else{
        (left == 0 && right == 0) ? h += 0 :  h += max(right,left); 
       
    };
    
    return h;

}*/

void Balance::setSiftGoal(vector<int> weights){
	int left = 5;
	int right = 6;
	int row = SHIPHEIGHT - 1;
	bool placeLeft = true;
	vector<vector<int>> goal;
	vector<int> tmpRow;
	for(int i = 0; i < SHIPWIDTH; i++){
		tmpRow.push_back(-1);	//Initialize all spaces to -1
	}
	for(int i = 0; i < SHIPHEIGHT; i++){
		goal.push_back(tmpRow);
	}
	for(int i = weights.size() - 1; i >= 0; i--){
		if(0 > left)
			left = 5;
		if(SHIPWIDTH <= right){
			right = 6;
			row--;
		}
		if(true == placeLeft){
			goal[row][left--] = weights[i];
		}
		else{
			goal[row][right++] = weights[i];
		}
		placeLeft = !placeLeft;
	}

	siftGoal = goal;
}

// check if the total weight of all containers except the 
// one with max weight is 90% of the max weight
bool Balance::requireSift(Node n) {
    vector<int> weights; 

	int totalWeight = 0;
    for(int i = 0;i < n.ship.size();i++) {
        for(int j = 0;j < n.ship[0].size();j++) {
			if(2 == n.ship[i][j].status){
	            weights.push_back(n.ship[i][j].weight);
				totalWeight += n.ship[i][j].weight;
			}
        }
    }

    sort(weights.begin(),weights.end());
	setSiftGoal(weights);



	for(int i = 0; i < weights.size(); i++){
		if(true == getPermutations(weights, 0, i + 1, 0, totalWeight))
			return false;
	}
	
    return true; 
}

bool Balance::balanceGoalTest(Node n) {
    int startRow = n.cranePos.first;
	int startCol = n.cranePos.second;
	int startZone = n.craneLocation;

    //check to see if top of the ship is empty
    for(int i = 0; i < SHIPWIDTH; i++){
        if(n.ship.at(0).at(i).status > 0){
            return false;
        }
    }
    //check to see if the buffers empty
    if(false == bufferEmpty(n))
		return false;

    //check to see if the crane is still holding a container
    if(0 == n.prev[2][0])
		return false;
    //crane still has a container
    if(n.prev.at(2).at(0) == 0) return false;

    //check for balance
    int mid = n.ship[0].size() / 2;
    double left = 0.0;
    double right = 0.0;

    for (int i = 0; i < n.ship[0].size(); i++) {
        for (int j = 0; j < n.ship.size(); j++) {
            // Accumulate weights on the left side
            if (i < mid) {
                left += n.ship[j][i].weight;
            }
            // Accumulate weights on the right side
            else {
                right += n.ship[j][i].weight;
            }
        }
    }
    

    if (min(right,left) / max(right,left) > 0.9 || left == 0 && right == 0){
         
           return true; // Is a goal
    }  
    else {
        
        
        return false; // Is not a goal
    } 
        
}