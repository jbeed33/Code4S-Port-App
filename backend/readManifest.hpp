#ifndef READMANIFEST_H
#define READMANIFEST_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "node.hpp"
using namespace std;

struct tmp {
    string name;
    int weight;
    pair<int,int> pos;
    int status;
};

int checkName(string name) {
    if (name == "NAN") return -1;       //invalid space
    if (name == "UNUSED") return 0;     // empty space
    return 2;                           // container stays on ship
}

vector<vector<Container>> readManifest(string file_path) {
    vector<vector<tmp>> ship;

    // read file
    ifstream manifest(file_path);

    string line;
    char bracket, comma;
    int row, col, weight;
    string name;
    vector<tmp> row_of_containers = {};

    // read each line and parse the information
    while (getline(manifest, line)) {
        stringstream ss(line);

        // parse position
        ss >> bracket >> row >> comma >> col >> bracket >> comma;

        // parse weight
        ss >> bracket >> weight >> bracket >> comma;

        // parse name and remove the leading whitespace
        getline(ss >> ws, name);

        // create a container with these information
        tmp container;
        container.pos.first = row;
        container.pos.second = col;
        container.weight = weight;
        container.name = name;
        container.status = checkName(name);

        // add the container to the 2D vector
        if (row_of_containers.empty()) row_of_containers.push_back(container);
        else {
            if (container.pos.first > row_of_containers[0].pos.first) {
                ship.push_back(row_of_containers);
                row_of_containers.clear();
            }
            row_of_containers.push_back(container);
        }
    }
	if(false == row_of_containers.empty())	//Add the last row if it's not empty
		ship.push_back(row_of_containers);

    // close the file
    manifest.close();
	vector<vector<Container>> finished;
	if(false == ship.empty()){
		vector<Container> rowContainer;
		for(int i = 0; i < ship[0].size(); i++){
			rowContainer.push_back({"UNUSED", 0, 0});
		}
		finished.push_back(rowContainer);
	}	
	for(int row = ship.size() - 1; row >= 0; row--){
		vector<Container> rowContainer;
		for(int col = 0; col < ship[0].size(); col++){
			Container cont;
			tmp old = ship[row][col];
			cont.name = old.name;
			cont.status = old.status;
			cont.weight = old.weight;
			rowContainer.push_back(cont);
		}
		finished.push_back(rowContainer);
	}
    return finished;
}

// prints the 2D vector upside down to match to actual grid
void print(vector<vector<Container>>& ship) {
    for(int i = ship.size()-1;i >= 0;i--) {
        for(int j = 0;j < ship[0].size();j++) {
            cout << checkName(ship[i][j].name) << " ";
        }
        cout << endl;
    }
}
#endif // READMANIFEST_H
