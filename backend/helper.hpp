 #ifndef helper_h
 #define helper_h
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <windows.h>
 #include <shlobj.h>
 #include "node.hpp"

 inline void trimPath(Node &current){
	vector<vector<vector<int>>> path = current.path;
	int start = -1;
	vector<vector<vector<int>>> newPath;
	for(int i = 0; i < path.size(); i++){
		if(-1 == start && 0 == path[i][2][0]){	//Picking up container
			start = i;
		}
		else if(-1 < start && 1 == path[i][2][0]){	//Setting down container
			vector<vector<int>> move = {
				path[start][1],
				path[i][1],
				{1}
			};
			newPath.push_back(move);
			start = -1;
		}
	}
	if(-1 < start){		//if the last move doesn't set down the container, do so here
		int row = path[path.size() - 1][1][0];
		int col = path[path.size() - 1][1][1];
		for(int i = row + 1; i < current.ship.size(); i++){
			if(0 == current.ship[i][col].status){
				row = i;
			}
		}
		vector<vector<int>> move = {
			path[start][1],
			{row, col, 0},
			{1}
		};
		newPath.push_back(move);
	}
	current.path = newPath;
 }

inline bool getPermutations(vector<int> weights, int startPos, int numToChoose, int left, int remainingWeight){
	if(0 == numToChoose){
		if(0 >= max(left, remainingWeight)){
			return true;
		}
		double bal = ((double)min(left, remainingWeight) / (double)max(left, remainingWeight));
		return (bal > 0.9);
	}
	
	if(numToChoose < weights.size() - startPos){
		if(true == getPermutations(weights, startPos + 1, numToChoose, left, remainingWeight)){
			return true;
		}
	}
	bool tmp = getPermutations(weights, startPos + 1, numToChoose - 1, left + weights[startPos], remainingWeight - weights[startPos]);
	return tmp;
}

 inline bool bufferEmpty(Node current) {
 	for (int i = 0; i < BUFFERHEIGHT; i++) {
 		for (int j = 0; j < BUFFERWIDTH; j++) {
 			if (0 < current.buffer[i][j].status)
 				return false;
 		}
 	}
 	return true;
 }

 inline int findTopShip(vector<vector<Container>> ship, int col) {
 	if(0 > col || SHIPWIDTH <= col)
 		return -2;	//Error
 	for (int i = 0; i < SHIPHEIGHT; i++) {
 		if (0 < ship[i][col].status)
 			return i;
 	}
 	return -1;	//Empty Column
 }

 inline int findTopBuffer(vector<vector<Container>> buffer, int col) {
 	if(0 > col || BUFFERWIDTH <= col)
 		return -2;	//Error
 	for (int i = 0; i < BUFFERHEIGHT; i++) {
 		if (0 < buffer[i][col].status)
 			return i;
 	}
 	return -1;	//Empty Column
 }

 //Find all the walls on the ship (Columns completly filled with containers)
 //May be better to just return dockmost wall
 inline vector<int> findWalls(vector<vector<Container>> ship) {
 	vector<int> walls;
 	for (int i = 0; i < SHIPWIDTH; i++) {
 		if (1 <= ship[SHIPHEIGHT - 1][i].status) {
 			walls.push_back(i);
 		}
 	}
 	return walls;
 }

 inline bool validPath(vector<vector<Container>> ship, int startCol, int endCol) {
 	vector<int> walls = findWalls(ship);
 	for (unsigned int i = 0; i < walls.size(); i++) {
 		if (startCol <= walls[i] && walls[i] < endCol || endCol <= walls[i] && walls[i] < startCol)	//ship portal accessablility is not checked elsewhere (thus startCol <= walls[i])
 			return false;
 	}

 	return true;
 }


 inline int distToPortal(Node current, int startRow, int startCol){
	int dist = startCol + startRow;
	int topOfCol = findTopShip(current.ship, startCol);
	int movesToUncover = 1;
	dist += movesToUncover * topOfCol - startRow;	//Distance to unbury the container
	return dist;
 }

/*
// utility function for getAppDataPath
inline string convertWcharToString(const wchar_t* wide) {
    int bufferLength = WideCharToMultiByte(CP_UTF8, 0, wide, -1, NULL, 0, NULL, NULL);
    string path(bufferLength, 0);
    WideCharToMultiByte(CP_UTF8, 0, wide, -1, &path[0], bufferLength, NULL, NULL);
    path.pop_back();
    return path;
}*/

inline string convertWcharToString(const char* path) {
    return string(path);
}

// get appdata path
inline string getAppDataPath() {
    TCHAR szPath[MAX_PATH];
    if (SUCCEEDED(SHGetFolderPath(NULL, CSIDL_APPDATA, NULL, 0, szPath))) {
        return convertWcharToString((const char*)szPath);
    } else {
        cerr << "Failed to retrieve the AppData path." << endl;
        return "";
    }
}

// write a given string to the file
inline void writeToFile(const string& fileName, const string& content) {
    string filePath = getAppDataPath();
    filePath += "\\shippingAi\\" + fileName;

    std::ofstream file(filePath);

    if (file.is_open()) {
        file << content;
        file.close();
        cout << "File written successfully to " << filePath << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
}

inline void writePathToFile(vector<vector<vector<int>>> path){
	string name = "path.txt";
	for(int i = 0; i < path.size(); i++){
		string content = to_string(path[i][0][0]) + " " + to_string(path[i][0][1]) + " " + to_string(path[i][0][2]) + " " + to_string(path[i][1][0]) + " " + to_string(path[i][1][1]) + " " + to_string(path[i][1][2]);
		cout << content << endl;
		writeToFile(name, content);
	}
}

 #endif