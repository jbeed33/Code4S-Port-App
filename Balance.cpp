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