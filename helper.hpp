#ifndef helper_h
#define helper_h

#include "node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iomanip>
using namespace std;

bool bufferEmpty(Node current) {
	for (int i = 0; i < BUFFERHEIGHT; i++) {
		for (int j = 0; j < BUFFERWIDTH; j++) {
			if (0 > get<1>(current.buffer[i][j]))
				return false;
		}
	}
	return true;
}

int findTopShip(vector<vector<tuple<Container, int>>> ship, int col) {
	if(0 > col || SHIPWIDTH <= col)
		return -2;	//Error
	for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
		if (1 <= get<1>(ship[i][col]))
			return i;
	}
	return -1;	//Empty Column
}

int findTopBuffer(vector<vector<tuple<Container, int>>> buffer, int col) {
	if(0 > col || BUFFERWIDTH <= col)
		return -2;	//Error
	for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
		if (1 <= get<1>(buffer[i][col]))
			return i;
	}
	return -1;	//Empty Column
}

//Find all the walls on the ship (Columns completly filled with containers)
//May be better to just return dockmost wall
vector<int> findWalls(vector<vector<tuple<Container, int>>> ship) {
	vector<int> walls;
	for (int i = 0; i < SHIPWIDTH; i++) {
		if (1 <= get<1>(ship[SHIPHEIGHT - 1][i])) {
			walls.push_back(i);
		}
	}
	return walls;
}

bool validPath(vector<vector<tuple<Container, int>>> ship, int startCol, int endCol) {
	vector<int> walls = findWalls(ship);
	for (unsigned int i = 0; i < walls.size(); i++) {
		if (startCol <= walls[i] && walls[i] < endCol || endCol <= walls[i] && walls[i] < startCol)	//ship portal accessablility is not checked elsewhere (thus startCol <= walls[i])
			return false;
	}

	return true;
}

// return current time in the format "June 1st 2023: 00:02"
string getCurrentTime() {
    // Get the current time
    time_t now = time(nullptr);
    tm *ltm = localtime(&now);

    // Format the time (e.g., "June 1st 2023: 00:02")
    ostringstream dateStream, timeStream;
    dateStream << put_time(ltm, "%B ") << ltm->tm_mday;
    timeStream << put_time(ltm, "%Y: %H:%M");

    // Calculate the day's suffix
    int day = ltm->tm_mday;
    string suffix = (day % 10 == 1 && day != 11) ? "st" :
                        (day % 10 == 2 && day != 12) ? "nd" :
                        (day % 10 == 3 && day != 13) ? "rd" : "th";

    // Concatenate the date and the time
    string outputStr = dateStream.str() + suffix + " " + timeStream.str();

    return outputStr;
}

// add note to the log file, needs to provide the log file path and input
void addNoteToLogFile(string file_path, string input) {
    ofstream logFile(file_path, ios::app);  // Open in append mode

    // Concatenate current time with the input
    string str = getCurrentTime() + " " + input;

    // write the string to the log file
    logFile << str << endl;
    logFile.close();
}

Container setLoadedContainerInfo(string name) {
	Container container;
	container.name = name;
	container.weight = 0;
	container.status = 2;
	return container;
}

#endif