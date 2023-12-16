
#ifndef NODE_H
#define NODE_H
#include <utility>
#include <vector>
#include <tuple>
#include <string>

//using namespace std;
using std::vector;
using std::cout;
using std::endl;
using std::string;
using std::pair;
using std::max;
using std::min;
using std::cerr;
using std::to_string;

const int BUFFERWIDTH = 24;
const int BUFFERHEIGHT = 5;
const int SHIPHEIGHT = 9;
const int SHIPWIDTH = 12;
const int PORTALTIME = 4;
const int SINGLEMOVETIME = 1;

struct Container {
    string name;
    double weight;
    int status; //-1 structural wall 0-empty space 1-unloadable 2-do not unload
};


struct Node {

    int cost;
    double heuristic;
    double total;
	int numToLoad = 0;

    pair<int, int> cranePos;
    int craneLocation; // 0- ship, 1-truck, 2-buffer
    


    vector<string> removeList;
    vector<vector<Container>> ship;
    vector<vector<Container>> buffer;
  
	/*	startRow, startCol, startZone
	* 	endRow, endCol, endZone
	*	justCrane (0- not just moving the crane, 1 - just moving the crane )
	*/	
	vector<vector<int>> prev = {{0,0,0}, {0,0,0}, {1}};
    vector<vector<vector<int>>> path;
    vector<int> costForPaths;

    bool operator!=(const Node& b) {
        
        // compare heuristic values
        if(heuristic != b.heuristic) return true;

        //check cost
        if(cost != b.cost) return true;

        //check crane position
        if(cranePos.first != b.cranePos.first) return true;
        if(cranePos.second != b.cranePos.second) return true;


        //check zone
        if(craneLocation != b.craneLocation) return true;

        //check numToLoad
        if(numToLoad != b.numToLoad) return true; 

        //crane already has container
        if(prev.at(2).at(0) != b.prev.at(2).at(0)) return true;

        // compare ship
        for(int i = 0;i < ship.size();i++) {
            for(int j = 0;j < ship[0].size();j++) {
                if(ship[i][j].name != b.ship[i][j].name ||
                   ship[i][j].weight != b.ship[i][j].weight ||
                   ship[i][j].status != b.ship[i][j].status)
                   return true;
            }
        }

        // compare buffer
        for(int i = 0;i < buffer.size();i++) {
            for(int j = 0;j < buffer[0].size();j++) {
                if(buffer[i][j].name != b.buffer[i][j].name ||
                   buffer[i][j].weight != b.buffer[i][j].weight ||
                   buffer[i][j].status != b.buffer[i][j].status)
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