#include "Balance.hpp"
#include <algorithm>

void Balance::setup(){
    
}

bool Balance::stateExists(Node currentState){
    for (int i = 0; i < closed.size(); i++) {
        if (closed[i] != currentState )
            return true;
    }

    for (int i = 0; i < frontier.size(); i++) {
        if (frontier[i] != currentState )
            return true;
    }
    return false;
}

double Balance::heuristic(Node n){

    double h = 0.0;

    if(balanceGoalTest(n) == true){
        cout << "passed the goal test" << endl;
        return 0.0;
    }
  
    
    //check to see if top of the ship is empty
    for(int i = 0; i < n.ship[0].size(); i++){
        if(n.ship.at(0).at(i).status > 0){
            h+= 2;
        }
    }

    //check to see if the buffers empty
    for(int i = 0; i < n.buffer[0].size(); i++){
        if(n.buffer.at(0).at(i).status > 0){
            h+=5;
        }
    }

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

}


// check if the total weight of all containers except the 
// one with max weight is 90% of the max weight
bool requireSift(Node initialState) {
    vector<int> weights; 

    for(int i = 0;i < initialState.ship.size();i++) {
        for(int j = 0;j < initialState.ship[0].size();j++) {
            weights.push_back(initialState.ship[i][j].weight);
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

bool Balance::balanceGoalTest(Node n) {
    
    //check to see if top of the ship is empty
    for(int i = 0; i < n.ship[0].size(); i++){
        if(n.ship.at(0).at(i).status > 0){
            return false;
        }
    }

    //check to see if the buffers empty
    for(int i = 0; i < n.buffer[0].size(); i++){
        if(n.buffer.at(0).at(i).status > 0){
            return false;
        }
    }

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

    if (min(right,left) / max(right,left) > 0.9)
        return true; // Is a goal
    else  
        return false; // Is not a goal
}