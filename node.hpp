
#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
#include<string>

using namespace std;

struct Container {
    string name;
    int weight;
    pair<int, int> pos;

};


struct Node {

    double cost;
    double heuristic;
    double total;

    pair<int, int> cranePos;
    int craneLocation; // 0- ship, 1-truck, 2-buffer

    vector<vector<tuple<Container, int>>> ship;
    vector<vector<tuple<Container, int>>> buffer;
  

    vector<vector<vector<int>>> path;

    //functions
    void expand(vector<Node>& visited, vector<Node> &st);

    //helper functions for expand, each function should produce a new Node unless its invalid.
    void containerToBuffer();
    void containerToShip();
    void containerWithinShip();
    void loadContainerOntoShip();
    void containerToTruck();
    void moveCraneToShip();
    void moveCraneToBuffer();


};

#endif