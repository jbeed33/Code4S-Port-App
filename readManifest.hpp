#ifndef READMANIFEST_H
#define READMANIFEST_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct Container {
    string name;
    int weight;
    pair<int,int> pos;
};

vector<vector<Container>> readManifest(string file_path) {
    vector<vector<Container>> ship;

    // read file
    ifstream manifest(file_path);

    string line;
    char bracket, comma;
    int row, col, weight;
    string name;
    vector<Container> row_of_containers = {};

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
        Container container;
        container.pos.first = row;
        container.pos.second = col;
        container.weight = weight;
        container.name = name;

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

    // close the file
    manifest.close();
    return ship;
}

int checkName(string name) {
    if (name == "NAN") return -1;       //invalid space
    if (name == "UNUSED") return 0;     // empty space
    return 2;                           // container stays on ship
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
