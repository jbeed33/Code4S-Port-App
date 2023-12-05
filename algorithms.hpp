#ifndef ALGORITHMS_H
#define ALGORITHMS_H

using namespace std;
#include "node.hpp";
#include <vector>
#include <algorithm>

void balanceAlgo(){
    vector<Node> st;
    vector<Node> visited;

    Node start = Node();

    //need to read in manifest from node

    //put start node in stack
    st.push_back(start);

    // do this while the stack is not empty
    while(!st.empty()){

        Node curr = st.at(0);

         // check to see if current point is the goal
        if(balaceGoalTest(curr) == true)
        {
            // read path into designated file (filesystem)
        } 

        // take current point and expand in all directions if only valid (add to st)
          curr.expand(visited);
            
        
         // add explored node to visited 
            visited.push_back(curr);
    }
};


void unloadAndLoadAlgo(){
   vector<Node> st;
   vector<Node> visited;
   vector<Node> containersToLoad;
   vector<Node> containersToUnload;

   //NEED TO FIGURE OUT A WAY TO PASS LOAD AND UNLOAD INTO RESPECTIVE VECTORS

    Node start = Node();

    //need to read in manifest from node

    //put start node in stack
    st.push_back(start);

    // do this while the stack is not empty
    while(!st.empty()){

        Node curr = st.at(0);

         // check to see if current point is the goal
        if(unloadAndLoadGoalTest(curr) == true)
        {
            // read path into designated file (filesystem)
        } 

        // take current point and expand in all directions if only valid (add to st)
          curr.expand(visited);
            
        
         // add explored node to visited 
            visited.push_back(curr);
    }
}

bool balaceGoalTest(Node& n){
    Container current;
    vector<Node> st;
    if(st.empty()) {
        return 0; //Is a goal
    }
    int mid = SHIPWIDTH / 2;
    double left = 0.0;
    double right = 0.0;

    for (int i = 0; i < SHIPWIDTH; i++) {
        for (int j = 0; j < SHIPHEIGHT; j++) {
            // Accumulate weights on the left side
            if (i < mid) {
                left += current.pos[i].weight;
            }
            // Accumulate weights on the right side
            else {
                right += current.pos[i].weight;
            }
        }
    }

    if (min(right,left) / max(right,left) > 0.9)
        return 1; // Not a goal
    else  
        return 0; // Is a goal
}

bool unloadAndLoadGoalTest(Node &n){

}

#endif