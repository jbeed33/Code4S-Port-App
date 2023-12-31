 #ifndef helper_h
 #define helper_h
 #include <iostream>
 #include <fstream>
 #include <string>
 #include <windows.h>
 #include <shlobj.h>
 #include "node.hpp"

 inline bool compareStateWeights(vector<vector<Container>> currentState, vector<vector<Container>> closed){
	bool diffFound = false;
    for(int row = 0; row < currentState.size(); row++){
	    for(int col = 0; col < currentState[0].size(); col++){
        	if(currentState.at(row).at(col).weight != closed.at(row).at(col).weight){
	            diffFound = true;
            	break;
        	}
    	}
    	if(diffFound)
			break;
    }
	return diffFound;
 }
 
 inline bool compareStateStatus(vector<vector<Container>> currentState, vector<vector<Container>> closed){
	bool diffFound = false;
    for(int row = 0; row < currentState.size(); row++){
	    for(int col = 0; col < currentState[0].size(); col++){
        	if(currentState.at(row).at(col).status != closed.at(row).at(col).status){
	            diffFound = true;
            	break;
        	}
    	}
    	if(diffFound)
			break;
    }
	return diffFound;
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

 inline int distBetweenPoints(int startRow, int startCol, int startZone, int endRow, int endCol, int endZone){
	int tmpRow = startRow;
	int tmpCol = startCol;

	int dist = 0;
	
	if(startZone != endZone){
		dist += PORTALTIME;
		dist += tmpRow;
		tmpRow = 0;
		if(0 == endZone){
			dist += tmpCol;
			tmpCol = 0;
		}
		if(2 == endZone){
			dist += (BUFFERWIDTH - 1) - tmpCol;
			tmpCol = BUFFERWIDTH - 1;
		}
	}

	dist += max(tmpCol, endCol) - min(tmpCol, endCol);
	dist += max(tmpRow, endRow) - min(tmpRow, endRow);

	return dist;
 }

 inline void trimPath(Node &current){
	vector<vector<vector<int>>> path = current.path;
	path.push_back(current.prev);
	int cost = 0;
	int cr = 0, cc = 0, cz = 0;
	int start = -1;
	vector<vector<vector<int>>> newPath;
	for(int i = 0; i < path.size(); i++){
		if(-1 == start && 0 == path[i][2][0]){	//Picking up container
			start = i;
			cost = distBetweenPoints(cr, cc, cz, path[i][1][0], path[i][1][1], path[i][1][2]);
		}
		else if(-1 < start && 1 == path[i][2][0]){	//Setting down container
		   cost += distBetweenPoints(path[start][1][0], path[start][1][1], path[start][1][2], path[i][1][0], path[i][1][1], path[i][1][2]);
		   cr = path[i][1][0];
		   cc = path[i][1][1];
		   cz = path[i][1][2];


			vector<vector<int>> move = {
				path[start][1],
				path[i][1],
				{1},
				{cost}
			};
			newPath.push_back(move);
			start = -1;
		}
	}
	
	current.path = newPath;
 }

 /*inline double findDistanceToBalanced(Node current){
	int numContainers = 0;
	int totalWeight = 0;
	int numInBuffer = 0;
	int bufferWeight = 0;
	int leftWeight = 0;
	int numInLeft = 0;

	for (int j = 0; j < SHIPWIDTH; j++) {
		for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.ship[i][j].status){
				totalWeight += current.ship[i][j].weight;
				numContainers++;
			}
			else if(0 == current.ship[i][j].status){	//No more containers in column
				break;
			}
 		}
 	}
 	for (int j = 0; j < BUFFERWIDTH; j++) {
		for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.buffer[i][j].status){	//No more containers in column
				totalWeight += current.buffer[i][j].weight;
				numContainers++;
				numInBuffer++;
				bufferWeight += current.buffer[i][j].weight;
			}
			else if(0 == current.buffer[i][j].status){
				break;
			}
 		}
 	}
	for (int j = 0; j < SHIPWIDTH / 2; j++) {
		for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.ship[i][j].status){
				leftWeight += current.ship[i][j].weight;
				numInLeft++;
			}
			else if(0 == current.ship[i][j].status){	//No more containers in column
				break;
			}
 		}
 	}
	int numInShip = numContainers - numInBuffer;
	int shipWeight = totalWeight - (leftWeight + bufferWeight);
	int rightWeight = shipWeight - leftWeight;
	int numInRight = numInShip - numInLeft;

	double bufferAvg = (double)bufferWeight / (double)numInBuffer;
	double totalAvg = 
	double leftAvg = (double)leftWeight / (double)numInLeft;

	if(0 == numContainers)
		return 0.0;
	return ((double)totalDist / (double)numContainers);
 }*/

inline double findDistanceToBalanced(Node current){
	double dist = 0.0;
	for (int j = 0; j < SHIPWIDTH; j++) {
		for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.ship[i][j].status){
				dist += distBetweenPoints(SHIPHEIGHT / 2, SHIPWIDTH / 2, 0, i, j, 0);
			}
			else if(0 == current.ship[i][j].status){	//No more containers in column
				break;
			}
 		}
 	}
 	for (int j = 0; j < BUFFERWIDTH; j++) {
		for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.buffer[i][j].status){	//No more containers in column
				dist += distBetweenPoints(BUFFERHEIGHT / 2, BUFFERWIDTH / 2, 0, i, j, 2);
			}
			else if(0 == current.buffer[i][j].status){
				break;
			}
 		}
 	}

	return dist;
 }

 inline double findAverageDistanceToCrane(Node current){
	int numContainers = 0;
	int totalDist = 0;

	int craneRow = current.cranePos.first;
	int craneCol = current.cranePos.second;
	int craneZone = current.craneLocation;

	for (int j = 0; j < SHIPWIDTH; j++) {
		for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.ship[i][j].status){
				int tmp = distBetweenPoints(i, j, 0, craneRow, craneCol, craneZone);
				totalDist += tmp;
				numContainers++;
			}
			else if(0 == current.ship[i][j].status){	//No more containers in column
				break;
			}
 		}
 	}
 	for (int j = 0; j < BUFFERWIDTH; j++) {
		for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.buffer[i][j].status){	//No more containers in column
				int tmp = distBetweenPoints(i, j, 2, craneRow, craneCol, craneZone);
				totalDist += tmp;
				numContainers++;
			}
			else if(0 == current.buffer[i][j].status){
				break;
			}
 		}
 	}
	if(0 == numContainers)
		return 0.0;
	return ((double)totalDist / (double)numContainers);
 }

 inline vector<int> findFarthest(Node current){
	int left = -1;
	int lZone = -1;
	int right = -1;
	int rZone = -1;
	if(0 < current.numToLoad){
		left = BUFFERWIDTH - 1;
		lZone = 2;
	}
 	for (int j = 0; j < SHIPWIDTH; j++) {
		for (int i = SHIPHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.ship[i][j].status){
				if(-1 == left){
					left = j;
					lZone = 0;
				}
				right = j;
				rZone = 0;
				break;
			}
 		}
 	}
 	for (int j = 0; j < BUFFERWIDTH; j++) {
		for (int i = BUFFERHEIGHT - 1; i >= 0; i--) {
 			if (0 < current.buffer[i][j].status){
				if(-1 == right){
					right = j;
					rZone = 2;
				}
				left = j;
				lZone = 0;
				break;
			}
 		}
 	}
	return {left, lZone, right, rZone};
 }

 inline bool shipEmpty(Node current) {
	for (int i = 0; i < SHIPHEIGHT; i++) {
 		for (int j = 0; j < SHIPWIDTH; j++) {
 			if (0 < current.ship[i][j].status)
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


// utility function for getAppDataPath
// inline string convertWcharToString(const wchar_t* wide) {
//     int bufferLength = WideCharToMultiByte(CP_UTF8, 0, wide, -1, NULL, 0, NULL, NULL);
//     string path(bufferLength, 0);
//     WideCharToMultiByte(CP_UTF8, 0, wide, -1, &path[0], bufferLength, NULL, NULL);
//     path.pop_back();
//     return path;
// }

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
inline void writeToFile(const string& filePath, const string& content) {
    std::ofstream file(filePath, std::ios_base::app);

    if (file.is_open()) {
        file << content << '\n';
        file.close();
        cout << "File written successfully to " << filePath << endl;
    } else {
        cerr << "Unable to open file." << endl;
    }
}

inline void writePathToFile(vector<vector<vector<int>>> path){
	string filePath = getAppDataPath();
    filePath += "\\shippingAi\\path.txt";
	std::ofstream file(filePath);
	file.close();
	for(int i = 0; i < path.size(); i++){
		string content = to_string(path[i][0][0]) + " " + to_string(path[i][0][1]) + " " + to_string(path[i][0][2]) + " " + to_string(path[i][1][0]) + " " + to_string(path[i][1][1]) + " " + to_string(path[i][1][2]) + " " + to_string(path[i][3][0]);
		cout << content << endl;
		writeToFile(filePath, content);
	}
}

 #endif



