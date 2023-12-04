#include "expand.hpp"
#include <iostream>
using namespace std;

/*Test 1 - 6 tests for ship*/
/*Test 7 - 12 tests for buffer*/
/*Test 13 - test for truck*/

/*Test Description: Move crane left, crane stays on ship; Move crane right, stays on ship*/
bool craneMovementTest1(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 0;
    int col = 2 ;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,1,0},
        {0,3,0}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 1 Failed" << endl;
            return false;
        }
    }

    cout << "Test 1 passed" << endl;
    return true;
}


/*Test Description: Move crane left, crane goes to truck and buffer (no wall); Move crane right, stays on ship*/
bool craneMovementTest2(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 0;
    int col = 0;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,3,2},
        {1,0,1},
        {0,1,0}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 2 Failed" << endl;
            return false;
        }
    }

    cout << "Test 2 passed" << endl;
    return true;
}

/*Test Description: Move crane left, crane goes to truck and buffer (wall); Move crane right, stays on ship*/
bool craneMovementTest3(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 0;
    int col = 0;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer ={
        {e,e,e,s},
        {e,e,e,s},
        {e,e,e,s},
        {e,e,e,s}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,3,2},
        {1,0,1},
        {0,1,0} //should be zero
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 3 Failed" << endl;
            return false;
        }
    }

    cout << "Test 3 passed" << endl;
    return true;
}

/*Test Description: Crane starts at last column of ship
 crane moves right - do not expand node
 crane moves left - stays on ship*/
bool craneMovementTest4(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 0;
    int col = 3;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,2,0},
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 4 Failed" << endl;
            return false;
        }
    }

    cout << "Test 4 passed" << endl;
    return true;
}

/*Test Description: Crane starts second col, row to left of it is 2 higher than the crane row positon
 crane moves left  - crane stays on ship
 crane moves right - stays on ship*/
bool craneMovementTest5(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 2;
    int col = 1;
    n.cranePos = {row, col};

    n.ship ={
        {s,e,e,e},
        {s,e,e,e},
        {s,s,e,e},
        {s,s,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,0,0},
        {2,2,0}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 5 Failed" << endl;
            return false;
        }
    }

    cout << "Test 5 passed" << endl;
    return true;
}

/*Test Description: Crane starts second col, row to right of it is 2 higher than the crane row positon
 crane moves left  - crane stays on ship
 crane moves right - stays on ship*/
bool craneMovementTest6(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 0; //starts on ship
    int row = 2;
    int col = 1;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,s,e},
        {e,e,s,e},
        {e,s,s,e},
        {e,s,s,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {2,0,0},
        {0,2,0}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 6 Failed" << endl;
            return false;
        }
    }

    cout << "Test 6 passed" << endl;
    return true;
}

/*Test Description: Crane starts in buffer
 crane moves right - stays on buffer
 crane moves left - stays on buffer*/
bool craneMovementTest7(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 2; //starts in buffer
    int row = 0;
    int col = 2;
    n.cranePos = {row, col};

    n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,3,2},
        {0,1,2}
        
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 7 Failed" << endl;
            return false;
        }
    }

    cout << "Test 7 passed" << endl;
    return true;
}


/*Test Description: Crane starts in last col of buffer, crane goes to truck and ship (no wall)
 crane moves right - Goes to ship and truck
 crane moves left - stays on buffer*/
bool craneMovementTest8(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 2; //starts on buffer
    int row = 0;
    int col = 3;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer = {
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,0,0},
        {1,0,1},
        {0,2,2}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 8 Failed" << endl;
            return false;
        }
    }

    cout << "Test 8 passed" << endl;
    return true;
}

/*Test Description: Crane starts in last col of buffer, crane goes to truck and ship (wall)
 crane moves right - Goes to ship and truck
 crane moves left - stays in buffer*/
bool craneMovementTest9(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

     n.craneLocation = 2; //starts on buffer
    int row = 0;
    int col = 3;
    n.cranePos = {row, col};

    n.ship ={
        {s,e,e,e},
        {s,e,e,e},
        {s,e,e,e},
        {s,e,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,0,0},
        {1,0,1}, // should be 1
        {0,2,2}
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 9 Failed" << endl;
            return false;
        }
    }

    cout << "Test 9 passed" << endl;
    return true;
}

/*Test Description: Crane starts at first column buffer
 crane moves right - stay on ship
 crane moves left - do not move*/
bool craneMovementTest10(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

     n.craneLocation = 2; //starts on buffer
    int row = 0;
    int col = 0;
    n.cranePos = {row, col};

    n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

     n.buffer ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,1,2},
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 10 Failed" << endl;
            return false;
        }
    }

    cout << "Test 10 passed" << endl;
    return true;
}

/*Test Description: Crane starts second col in buffer, row to left of it is 2 higher than the crane row positon
 crane moves left  - crane stays on buffer
 crane moves right - stays on buffer*/
bool craneMovementTest11(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

    n.craneLocation = 2; //starts on buffer
    int row = 2;
    int col = 1;
    n.cranePos = {row, col};

    n.buffer ={
        {s,e,e,e},
        {s,e,e,e},
        {s,s,e,e},
        {s,s,e,e}

    };

     n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {2,2,2},
        {0,0,2},
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 11 Failed" << endl;
            return false;
        }
    }

    cout << "Test 11 passed" << endl;
    return true;
}

/*Test Description: Crane starts second col, row to right of it is 2 higher than the crane row positon
 crane moves left  - crane stays on ship
 crane moves right - stays on ship*/
bool craneMovementTest12(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

     n.craneLocation = 2; //starts on buffer
    int row = 2;
    int col = 1;
    n.cranePos = {row, col};

    n.buffer ={
        {e,e,s,e},
        {e,e,s,e},
        {e,s,s,e},
        {e,s,s,e}

    };

     n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,2,2},
        {2,0,2},
        
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 12 Failed" << endl;
            return false;
        }
    }

    cout << "Test 12 passed" << endl;
    return true;
}

/*Test Description: Crane starts in truck buffer and truck has no wall
 crane moves left  - crane stays on ship
 crane moves right - stays on ship*/
bool craneMovementTest13(){
    Node n;

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 0.0, 2};		//container stays on ship

     n.craneLocation = 1; //starts on truck
    int row = 2;
    int col = 1;
    n.cranePos = {row, col};

    n.buffer ={
        {e,e,s,e},
        {e,e,s,e},
        {e,s,s,e},
        {e,s,s,e}

    };

     n.ship ={
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e},
        {e,e,e,e}

    };

    vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
    vector<int> avaliableColsForShip = getWallsForZone(n, 0);

    vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

    vector<vector<int>> expectedMoves = {
        {0,3,2},
        {0,0,0}
        
    };

    if(craneMoves.size() != expectedMoves.size()){
        cout << "craneMoves size: " << craneMoves.size() << endl;
        cout << "Expected Moves size: " << expectedMoves.size() << endl;
        cout << "craneMoves size does not equal to expectedMoves size" << endl;
        return false;
    }
    for(int i = 0; i < craneMoves.size(); i++){
        int expectedEndRow = expectedMoves.at(i).at(0);
        int expectedEndCol = expectedMoves.at(i).at(1);
        int expectedEndZone = expectedMoves.at(i).at(2);

        int endRow = craneMoves.at(i).at(0);
        int endCol = craneMoves.at(i).at(1);
        int endZone = craneMoves.at(i).at(2);

        if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
            cout << "Test 13 Failed" << endl;
            return false;
        }
    }

    cout << "Test 13 passed" << endl;
    return true;
}



int main(){
cout << "Test suite for ship" << endl;
    craneMovementTest1();
    craneMovementTest2();
    craneMovementTest3();
    craneMovementTest4();
    craneMovementTest5();
    craneMovementTest6();
   

    cout << "" << endl;
    cout << "" << endl;

cout << "Test suite for buffer" << endl;
    craneMovementTest7();
    craneMovementTest8();
    craneMovementTest9();
    craneMovementTest10();
    craneMovementTest11();
    craneMovementTest12();

    cout << "" << endl;
    cout << "" << endl;

cout << "Test suite for truck" << endl;
    craneMovementTest13();
    return 0;
}