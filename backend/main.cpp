#include <iostream>
#include "Balance.hpp"
#include "LoadUnload.hpp"
#include "readManifest.hpp"

using namespace std;

bool craneMovementTest1(){

    Balance b;
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 0;
    int col = 0;
    n.cranePos = {row, col};

    n.ship ={
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{s, e, e, e, e, e, e, e, e, e, e, e},
		{s, e, e, e, e, e, e, e, e, e, e, e},
		{s, e, e, e, e, e, e, e, e, e, e, e}
	};

    Node result = b.search(n.ship, row, col, 0,0, {});

	vector<vector<vector<int>>> path = result.path;
	for(int i = 0; i < path.size(); i++){
		printf("%d %d\t%d %d\n", path[i][0][0], path[i][0][1], path[i][1][0], path[i][1][1]);
	}
    return true;
}


int main(int argc, char *argv[]){
//	craneMovementTest1();
///*
	string manifestPath = argv[1];
	vector<vector<Container>> manifest = readManifest(manifestPath);

	if(argc > 2){	//Load unload
		int numToLoad = atoi(argv[2]);
		vector<string> names;
		for(int i = 3; i < argc; i++){
			names.push_back(argv[i]);
		}
		LoadUnload ai = LoadUnload();
		Node result = ai.search(manifest, 8, 1, 0, numToLoad, names);
		vector<vector<vector<int>>> path = result.path;
		writePathToFile(path);
		for(int i = 0; i < path.size(); i++){
			printf("%d %d\t%d %d\n", path[i][0][0], path[i][0][1], path[i][1][0], path[i][1][1]);
		}
	}
	else{		//Balance
		Balance ai = Balance();
		Node result = ai.search(manifest, 0, 0, 0, 0, {});
		vector<vector<vector<int>>> path = result.path;
		writePathToFile(path);
		for(int i = 0; i < path.size(); i++){
			printf("%d %d\t%d %d\n", path[i][0][0], path[i][0][1], path[i][1][0], path[i][1][1]);
		}
	}
//*/
    return 0;
}