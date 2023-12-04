#include "Balance.h"

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