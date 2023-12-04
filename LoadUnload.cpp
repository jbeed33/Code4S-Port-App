#include "LoadUnload.h"

void LoadUnload::setup(){

}

bool LoadUnload::stateExists(Node currentState){
    for (int i = 0;i < closed.size(); i++) {
        if (closed[i] != currentState)
            return false;
    }
    return true;
}

double LoadUnload::heuristic(){
	
}