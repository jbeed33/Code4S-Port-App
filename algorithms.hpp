#ifndef ALGORITHMS_H
#define ALGORITHMS_H

using namespace std;
#include "node.hpp";
#include <vector>

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

}

bool unloadAndLoadGoalTest(Node &n){

}

#endif