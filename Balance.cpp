#include "Balance.h"
#include <algorithm>

void Balance::setup(){
    
}

bool Balance::stateExists(Node currentState){
    for (int i = 0;i < closed.size(); i++) {
        if (closed[i] != currentState)
            return false;
    }
    return true;
}

double Balance::heuristic(){

}


// check if the total weight of all containers except the 
// one with max weight is 90% of the max weight
bool requireSift(Node initialState) {
    vector<int> weights; 

    for(int i = 0;i < initialState.ship.size();i++) {
        for(int j = 0;j < initialState.ship[0].size();j++) {
            weights.push_back(get<0>(initialState.ship[i][j]).weight);
        }
    }

    sort(weights.begin(),weights.end());

    int max = weights[0];   // get the max weight 
    int total = 0;          // get the total weight exclude the max weight
    for(int weight : weights) {
        total += weight;
    }

    return max * 0.9 > total;   // compare the max weight with the total weight
}

int Balance::balanceGoalTest() {
    Container current;
    Node myShip;
    if(shipEmpty(myShip)) {
        return 0; //Is a goal
    }
    int mid = SHIPWIDTH / 2;
    double left = 0.0;
    double right = 0.0;

    for (int i = 0; i < SHIPWIDTH; i++) {
        for (int j = 0; j < SHIPHEIGHT; j++) {
            // Accumulate weights on the left side
            if (i < mid) {
                left += get<0>(myShip.ship[j][i]).weight;
            }
            // Accumulate weights on the right side
            else {
                right += get<0>(myShip.ship[j][i]).weight;
            }
        }
    }

    if (min(right,left) / max(right,left) > 0.9)
        return 1; // Not a goal
    else  
        return 0; // Is a goal
}