
#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
#include <tuple>
#include <string>

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

    vector<vector<tuple<Container, int>>> ship;
    vector<vector<tuple<Container, int>>> buffer;
    vector<string> removeList;
  
	/*	startRow, startCol, startZone
	* 	endRow, endCol, endZone
	*	justCrane
	*/	
	vector<vector<int>> prev;
    vector<vector<vector<int>>> path;

    bool operator!=(const Node& b) {
        // compare heuristic values
        if(heuristic != b.heuristic) return true;

        // compare ship
        for(int i = 0;i < ship.size();i++) {
            for(int j = 0;j < ship[0].size();j++) {
                if(get<0>(ship[i][j]).name != get<0>(b.ship[i][j]).name ||
                   get<0>(ship[i][j]).weight != get<0>(b.ship[i][j]).weight ||
                   get<0>(ship[i][j]).status != get<0>(b.ship[i][j]).status)
                   return true;
            }
        }

        // compare buffer
        for(int i = 0;i < buffer.size();i++) {
            for(int j = 0;j < buffer[0].size();j++) {
                if(get<0>(buffer[i][j]).name != get<0>(b.buffer[i][j]).name ||
                   get<0>(buffer[i][j]).weight != get<0>(b.buffer[i][j]).weight ||
                   get<0>(buffer[i][j]).status != get<0>(b.buffer[i][j]).status)
                   return true;
            }
        }

        return false;
    }

    void removeContainerNameFromRemoveList(string name) {
        for(int i = 0;i < removeList.size();i++) {
            if(removeList[i] == name) {
                removeList[i] = removeList.back();
                removeList.pop_back();
                break;
            }
        }
    }

    void addContainerNameToRemoveList(string name) {
        removeList.push_back(name);
    }
};

#endif