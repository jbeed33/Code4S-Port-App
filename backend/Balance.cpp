#include "Balance.hpp"
#include <algorithm>

void Balance::setup(){
    
}


bool Balance::stateExists(Node currentState){
    int currRow = currentState.cranePos.first;
    int currCol = currentState.cranePos.second;
    int currZone = currentState.craneLocation;
    bool currHasContainer = currentState.prev.at(2).at(0);

    if(currZone == 0){ // ship
         for (int i = 0; i < closed.size(); i++) {
        if(currRow == closed.at(i).cranePos.first && currCol == closed.at(i).cranePos.second){
            if(currZone == closed.at(i).craneLocation && currHasContainer == closed.at(i).prev.at(2).at(0) ){
                bool diffFound = false;
                for(int row = 0; row < currentState.ship.size(); row++){
                    for(int col = 0; col < currentState.ship[0].size(); col++){
                        if(currentState.ship.at(row).at(col).weight != closed.at(i).ship.at(row).at(col).weight){
                            diffFound = true;
                            break;
                        }
                    }
                    if(diffFound) break;
                }

                if(!diffFound) return true;
            }
            
        }
        
           
    }

     for (int i = 0; i < frontier.size(); i++) {
        if(currRow == frontier.at(i).cranePos.first && currCol == frontier.at(i).cranePos.second){
            if(currZone == frontier.at(i).craneLocation && currHasContainer == frontier.at(i).prev.at(2).at(0) ){
                bool diffFound = false;
                for(int row = 0; row < currentState.ship.size(); row++){
                    for(int col = 0; col < currentState.ship[0].size(); col++){
                        if(currentState.ship.at(row).at(col).weight != frontier.at(i).ship.at(row).at(col).weight){
                            diffFound = true;
                            break;
                        }
                    }

                    if(diffFound) break;
                }

                 if(!diffFound) return true;
            }
            
        }
        
           
    }
    }
    else if( currZone == 2){ //buffer
        for (int i = 0; i < closed.size(); i++) {
        if(currRow == closed.at(i).cranePos.first && currCol == closed.at(i).cranePos.second){
            if(currZone == closed.at(i).craneLocation && currHasContainer == closed.at(i).prev.at(2).at(0) ){
                bool diffFound = false;
                for(int row = 0; row < currentState.buffer.size(); row++){
                    for(int col = 0; col < currentState.buffer[0].size(); col++){
                        if(currentState.buffer.at(row).at(col).weight != closed.at(i).buffer.at(row).at(col).weight){
                            diffFound = true;
                            break;
                        }
                    }
                    if(diffFound) break;
                }

                if(!diffFound) return true;
            }
            
        }
        
           
    }

     for (int i = 0; i < frontier.size(); i++) {
        if(currRow == frontier.at(i).cranePos.first && currCol == frontier.at(i).cranePos.second){
            if(currZone == frontier.at(i).craneLocation && currHasContainer == frontier.at(i).prev.at(2).at(0) ){
                bool diffFound = false;
                for(int row = 0; row < currentState.buffer.size(); row++){
                    for(int col = 0; col < currentState.buffer[0].size(); col++){
                        if(currentState.buffer.at(row).at(col).weight != frontier.at(i).buffer.at(row).at(col).weight){
                            diffFound = true;
                            break;
                        }
                    }

                    if(diffFound) break;
                }

                 if(!diffFound) return true;
            }
            
        }
        
           
    }
    }
    else{
        //truck
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

    //check to see if the crane is still holding a box on ship
   

    // cout << "Status at crane: " <<  n.ship.at(n.cranePos.first).at(n.cranePos.second).status << endl;
    if(n.craneLocation == 0 && n.ship.at(n.cranePos.first).at(n.cranePos.second).status > 0){
        if(n.cranePos.first + 1 < n.ship.size()){
            //cout << "Status below crane: " <<  n.ship.at(n.cranePos.first + 1).at(n.cranePos.second).status << endl;
            if(n.ship.at(n.cranePos.first + 1).at(n.cranePos.second).status < 1){
                cout << "made it here" << endl;
                h += 2;
            }
        }
    }

    //checking to see if crane is holding a box in the buffer zone.
    if(n.craneLocation == 2 && n.buffer.at(n.cranePos.first).at(n.cranePos.second).status > 0){
        if(n.cranePos.first + 1 < n.buffer.size()){
            //cout << "Status below crane: " <<  n.ship.at(n.cranePos.first + 1).at(n.cranePos.second).status << endl;
            if(n.buffer.at(n.cranePos.first + 1).at(n.cranePos.second).status < 1){
                cout << "made it here" << endl;
                h += PORTALTIME;
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
         cout << "huerstic for h: " << h << endl;
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


    //check to see if the crane is still holding a box on ship
    cout << "Status at crane: " <<  n.ship.at(n.cranePos.first).at(n.cranePos.second).status << endl;
    if(n.ship.at(n.cranePos.first).at(n.cranePos.second).status > 0){
        if(n.cranePos.first + 1 < n.ship.size()){
            cout << "Status below crane: " <<  n.ship.at(n.cranePos.first + 1).at(n.cranePos.second).status << endl;
            if(n.ship.at(n.cranePos.first + 1).at(n.cranePos.second).status < 1){
                cout << "Not passing because floating box" << endl;
                return false;
            }
        }
        
    }

    //crane still has a container
    if(n.prev.at(2).at(0) == 0) return false;

    //check for balance
    int mid = n.ship[0].size() / 2;
    double left = 0.0;
    double right = 0.0;

    cout << "Mid: " << mid << endl;

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
    cout << "Right: " << right << endl;
    cout << "Left: " << left << endl;

    if (min(right,left) / max(right,left) > 0.9){
         
           return true; // Is a goal
    }  
    else {
        cout << "Fails goal test" <<  endl;
        cout << min(right,left) / max(right,left) << endl;
        return false; // Is not a goal
    } 
        
}