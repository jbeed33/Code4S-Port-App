
#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
#include<string>

using namespace std;

const int BUFFERWIDTH = 24;
const int BUFFERHEIGHT = 5;
const int SHIPHEIGHT = 9;
const int SHIPWIDTH = 12;
const int PORTALTIME = 4;
const int SINGLEMOVETIME = 1;

struct Container {
    string name;
    int weight;
    int status;
};


struct Node {

    double cost;
    double heuristic;
    double total;
	int numToLoad;

    pair<int, int> cranePos;
    int craneLocation; // 0- ship, 1-truck, 2-buffer
    

    vector<vector<Container>> ship;
    vector<vector<Container>> buffer;
  
	/*	startRow, startCol, startZone
	* 	endRow, endCol, endZone
	*	justCrane
	*/	
	vector<vector<int>> prev;
    vector<vector<vector<int>>> path;
};

#endif