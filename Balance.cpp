#include "Balance.h"
#include <algorithm>

void Balance::setup(){
    
}

bool Balance::stateExists(){

}

double Balance::heuristic(){

}

int balanceGoalTest() {
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