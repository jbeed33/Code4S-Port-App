#include "Balance.hpp"
#include <iostream>

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
    int col = 2;
    n.cranePos = {row, col};
    n.prev.at(2).at(0) = 1;

    n.ship ={
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, s, e, e, e, e, e, e},
		{e, e, e, e, e, s, e, e, e, e, e, e}
	};

    b.search(n.ship, 0, 0, 0,0, {});

    // vector<vector<int>> expectedMoves = {
    //     {0,1,0},
    //     {0,3,0},
    //     {1,2,1}
    // };

    // if(b.frontier.size() != expectedMoves.size()){
    //     cout << "craneMoves size: " << b.frontier.size() << endl;
    //     cout << "Expected Moves size: " << expectedMoves.size() << endl;
    //     cout << "craneMoves size does not equal to expectedMoves size" << endl;
    //     return false;
    // }
    // for(int i = 0; i < b.frontier.size(); i++){
    //     int expectedEndRow = expectedMoves.at(i).at(0);
    //     int expectedEndCol = expectedMoves.at(i).at(1);
    //     int expectedEndZone = expectedMoves.at(i).at(2);

    //     int endRow = b.frontier.at(i).prev.at(1).at(0);
    //     int endCol = b.frontier.at(i).prev.at(1).at(1);
    //     int endZone = b.frontier.at(i).prev.at(1).at(2);

    //     if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
    //         cout << "Test 1 Failed" << endl;
    //         return false;
    //     }

    //     cout << "Node cost at index " << i << " : " << b.frontier.at(i).cost << endl;
    //     cout << "Node hurerstic at index " << i << " : " << b.frontier.at(i).heuristic << endl;
    // }

    // cout << "Test 1 passed" << endl;
    return true;
}


int main(){
    craneMovementTest1();
    
    return 0;
}