// #ifndef helper_h
// #define helper_h

// #include "node.hpp"

// bool bufferEmpty(Node current) {
// 	for (int i = 0; i < BUFFERHEIGHT; i++) {
// 		for (int j = 0; j < BUFFERWIDTH; j++) {
// 			if (0 > current.buffer[i][j].status)
// 				return false;
// 		}
// 	}
// 	return true;
// }

// int findTopShip(vector<vector<Container>> ship, int col) {
// 	if(0 > col || SHIPWIDTH <= col)
// 		return -2;	//Error
// 	for (int i = 0; i < SHIPHEIGHT; i++) {
// 		if (0 < ship[i][col].status)
// 			return i;
// 	}
// 	return -1;	//Empty Column
// }

// int findTopBuffer(vector<vector<Container>> buffer, int col) {
// 	if(0 > col || BUFFERWIDTH <= col)
// 		return -2;	//Error
// 	for (int i = 0; i < BUFFERHEIGHT; i++) {
// 		if (0 < buffer[i][col].status)
// 			return i;
// 	}
// 	return -1;	//Empty Column
// }

// //Find all the walls on the ship (Columns completly filled with containers)
// //May be better to just return dockmost wall
// vector<int> findWalls(vector<vector<Container>> ship) {
// 	vector<int> walls;
// 	for (int i = 0; i < SHIPWIDTH; i++) {
// 		if (1 <= ship[SHIPHEIGHT - 1][i].status) {
// 			walls.push_back(i);
// 		}
// 	}
// 	return walls;
// }

// bool validPath(vector<vector<Container>> ship, int startCol, int endCol) {
// 	vector<int> walls = findWalls(ship);
// 	for (unsigned int i = 0; i < walls.size(); i++) {
// 		if (startCol <= walls[i] && walls[i] < endCol || endCol <= walls[i] && walls[i] < startCol)	//ship portal accessablility is not checked elsewhere (thus startCol <= walls[i])
// 			return false;
// 	}

// 	return true;
// }

// #endif