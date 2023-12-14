// #include "expand.hpp"
// #include <iostream>
// using namespace std;


// /*
//     operators
//     - move crane left
//     - move cranem right
//     - move crane left with box 
//         -(prev - had a container) prev = 0;
//         -(moving the crane down) prev = 1;
//     - move crane right with box
//         -(prev - had a container)
//         -(moving the crane down)

// */
// /*Test 1 - 6    tests for ship*/
// /*Test 7 - 12   tests for buffer*/
// /*Test 13       test for truck*/
// /*Teset 14 - 21 tests for expand starting at ship */

// /*Test Description: Move crane left, crane stays on ship; Move crane right, stays on ship*/
// bool craneMovementTest1(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,1,0},
//         {0,3,0}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 1 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 1 passed" << endl;
//     return true;
// }


// /*Test Description: Move crane left, crane goes to truck and buffer (no wall); Move crane right, stays on ship*/
// bool craneMovementTest2(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,3,2},
//         {1,0,1},
//         {0,1,0}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 2 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 2 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, crane goes to truck and buffer (wall); Move crane right, stays on ship*/
// bool craneMovementTest3(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,3,2},
//         {1,0,1},
//         {0,1,0} //should be zero
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 3 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 3 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts at last column of ship
//  crane moves right - do not expand node
//  crane moves left - stays on ship*/
// bool craneMovementTest4(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,2,0},
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 4 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 4 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts second col, row to left of it is 2 higher than the crane row positon
//  crane moves left  - crane stays on ship
//  crane moves right - stays on ship*/
// bool craneMovementTest5(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 2;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,0,0},
//         {2,2,0}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 5 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 5 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts second col, row to right of it is 2 higher than the crane row positon
//  crane moves left  - crane stays on ship
//  crane moves right - stays on ship*/
// bool craneMovementTest6(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 2;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,s,s,e},
//         {e,s,s,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {2,0,0},
//         {0,2,0}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 6 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 6 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
//  crane moves right - stays on buffer
//  crane moves left - stays on buffer*/
// bool craneMovementTest7(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts in buffer
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,3,2},
//         {0,1,2}
        
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 7 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 7 passed" << endl;
//     return true;
// }


// /*Test Description: Crane starts in last col of buffer, crane goes to truck and ship (no wall)
//  crane moves right - Goes to ship and truck
//  crane moves left - stays on buffer*/
// bool craneMovementTest8(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer = {
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,0,0},
//         {1,0,1},
//         {0,2,2}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 8 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 8 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in last col of buffer, crane goes to truck and ship (wall)
//  crane moves right - Goes to ship and truck
//  crane moves left - stays in buffer*/
// bool craneMovementTest9(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//      n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,0,0},
//         {1,0,1}, // should be 1
//         {0,2,2}
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 9 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 9 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts at first column buffer
//  crane moves right - stay on ship
//  crane moves left - do not move*/
// bool craneMovementTest10(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//      n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,1,2},
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 10 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 10 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts second col in buffer, row to left of it is 2 higher than the crane row positon
//  crane moves left  - crane stays on buffer
//  crane moves right - stays on buffer*/
// bool craneMovementTest11(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 2;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e}

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {2,2,2},
//         {0,0,2},
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 11 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 11 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts second col, row to right of it is 2 higher than the crane row positon
//  crane moves left  - crane stays on ship
//  crane moves right - stays on ship*/
// bool craneMovementTest12(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//      n.craneLocation = 2; //starts on buffer
//     int row = 2;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,s,s,e},
//         {e,s,s,e}

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,2,2},
//         {2,0,2},
        
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 12 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 12 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in truck buffer and truck has no wall
//  crane moves left  - crane stays on ship
//  crane moves right - stays on ship*/
// bool craneMovementTest13(){
//     Node n;

//     Container i = {"", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"", 0.0, 1};		//container to unload
//     Container s = {"", 0.0, 2};		//container stays on ship

//      n.craneLocation = 1; //starts on truck
//     int row = 2;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,s,s,e},
//         {e,s,s,e}

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e}

//     };

//     vector<int> avaliableColsForBuffer = getWallsForZone(n, 1);
//     vector<int> avaliableColsForShip = getWallsForZone(n, 0);

//     vector<vector<int>> craneMoves = craneMovement(n, avaliableColsForBuffer, avaliableColsForShip);

//     vector<vector<int>> expectedMoves = {
//         {0,3,2},
//         {0,0,0}
        
//     };

//     if(craneMoves.size() != expectedMoves.size()){
//         cout << "craneMoves size: " << craneMoves.size() << endl;
//         cout << "Expected Moves size: " << expectedMoves.size() << endl;
//         cout << "craneMoves size does not equal to expectedMoves size" << endl;
//         return false;
//     }
//     for(int i = 0; i < craneMoves.size(); i++){
//         int expectedEndRow = expectedMoves.at(i).at(0);
//         int expectedEndCol = expectedMoves.at(i).at(1);
//         int expectedEndZone = expectedMoves.at(i).at(2);

//         int endRow = craneMoves.at(i).at(0);
//         int endCol = craneMoves.at(i).at(1);
//         int endZone = craneMoves.at(i).at(2);

//         if(expectedEndRow != endRow || expectedEndCol != endCol || expectedEndZone != endZone){
//             cout << "Test 13 Failed" << endl;
//             return false;
//         }
//     }

//     cout << "Test 13 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, crane stays on ship; Move crane right, stays on ship
//  testing Expand node (no boxes)*/
// bool expandTest14(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest = expandNode(n);


//     //left
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 0;

//     //right
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 0;
    
//     vector<Node> expectedNodes;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 14 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, crane stays on ship; Move crane right, stays on ship
//  testing Expand node (has box)*/
// bool expandTest15(){

//     Node n;

//     n.prev.at(2).at(0) = 0; // the crane still has a container

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest = expandNode(n);

//     //left without a box
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 0;

//     //left with box
//     Node n3 = n;
//     n3.cranePos = {0,1};
//     n3.craneLocation = 0;
//     n3.ship.at(row).at(col) = e;
//     n3.ship.at(0).at(1) = s;

//     //right without a box
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 0;

//     //right with box
//     Node n4 = n;
//     n4.cranePos = {0,3};
//     n4.craneLocation = 0;
//     n4.ship.at(row).at(col) = e;
//     n4.ship.at(0).at(3) = s;
    
//     vector<Node> expectedNodes;
//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n4);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 15 passed" << endl;
//     return true;
// }


// /*Test Description: Move crane left, crane goes to truck and buffer (no wall); Move crane right, stays on ship
//  (container stays on ship -- not unloadable)*/
// bool expandTest16(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves left to buffer
//     Node n1 = n;
//     n1.craneLocation = 2;
//     n1.cranePos = {0, 3};
    
//     // crane moves left with box moves to buffer
//     Node n2 = n;
//     n2.craneLocation = 2;
//     n2.cranePos = {3,3};
//     n2.ship.at(1).at(0) = e;
//     n2.buffer.at(3).at(3) = s;

//     //crane moves left to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};

//     // crane moves right stays on ship
//     Node n4 = n;
//     n4.cranePos = {0,1};
//     n4.craneLocation = 0;


//     // crane moves right with box stays on ship
//     Node n5 = n; 
//     n5.craneLocation = 0;
//     n5.cranePos = {1,1};
//     n5.ship.at(1).at(0) = e;
//     n5.ship.at(1).at(1) = s;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 16 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, crane goes to truck and buffer (no wall); Move crane right, stays on ship
//  (container stays on ship -- unloadable)*/
// bool expandTest17(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};
//     n.numToLoad = 1;

//     n.ship ={
//         {e,e,e,e},
//         {u,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves left to buffer
//     Node n1 = n;
//     n1.craneLocation = 2;
//     n1.cranePos = {0, 3};
    
//     // crane moves left with box moves to buffer
//     Node n2 = n;
//     n2.craneLocation = 2;
//     n2.cranePos = {3,3};
//     n2.ship.at(1).at(0) = e;
//     n2.buffer.at(3).at(3) = u;

//     //crane moves left to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};

//     //crane moves left to truck with unloadable box
//     Node n4 = n;
//     n4.craneLocation = 1;
//     n4.cranePos = {1,0};
//     n4.ship.at(1).at(0) = e;

//     // crane moves right stays on ship
//     Node n5 = n;
//     n5.cranePos = {0,1};
//     n5.craneLocation = 0;


//     // crane moves right with box stays on ship
//     Node n6 = n; 
//     n6.craneLocation = 0;
//     n6.cranePos = {1,1};
//     n6.ship.at(1).at(0) = e;
//     n6.ship.at(1).at(1) = u;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);
//     expectedNodes.push_back(n6);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for number to unload
//         if(test.numToLoad != expected.numToLoad){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.numToLoad << endl;
//             cout << "Crane Location for expected: " << expected.numToLoad << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 17 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, crane goes to truck and buffer (wall); Move crane right, stays on ship
//  (container stays on ship -- not unloadable)*/
// bool expandTest18(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves left to buffer
//     Node n1 = n;
//     n1.craneLocation = 2;
//     n1.cranePos = {0, 3};

//     //crane moves left to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};

//     // crane moves right stays on ship
//     Node n4 = n;
//     n4.cranePos = {0,1};
//     n4.craneLocation = 0;


//     // crane moves right with box stays on ship
//     Node n5 = n; 
//     n5.craneLocation = 0;
//     n5.cranePos = {1,1};
//     n5.ship.at(1).at(0) = e;
//     n5.ship.at(1).at(1) = s;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 18 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, stays on ship; Move crane right, OUT OF BOUNDS -- should not expand!!!
//  (container stays on ship -- not unloadable)*/
// bool expandTest19(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,s,s},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves left
//    Node n1 = n;
//    n1.craneLocation = 0;
//    n1.cranePos = {0, 2};

//    //crane moves left with box
//    Node n2 = n;
//    n2.craneLocation = 0;
//    n2.cranePos = {2, 2};
//    n2.ship.at(1).at(3) = e;
//    n2.ship.at(2).at(2) = s;

//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);







//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 19 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, stays on ship; Move crane right stays on ship;
//  to the left has a wall; to the right does not have a wall
//  (container stays on ship -- not unloadable)*/
// bool expandTest20(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,s,e,e},
//         {e,s,e,s},
//         {e,s,e,s},
//         {e,s,s,s},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves left
//    Node n1 = n;
//    n1.craneLocation = 0;
//    n1.cranePos = {0, 1};

//    //crane moves right
//    Node n2 = n;
//    n2.craneLocation = 0;
//    n2.cranePos = {0, 3};

//    //crane moves right with box
//    Node n3 = n;
//    n3.craneLocation = 0;
//    n3.cranePos = {0, 3};
//    n3.ship.at(3).at(2) = e;
//    n3.ship.at(0).at(3) = s;

//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);
//    expectedNodes.push_back(n3);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 20 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, stays on ship; Move crane right stays on ship;
//  to the left does not have a wall; to the right does have a wall
//  (container stays on ship -- not unloadable)*/
// bool expandTest21(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,s,s},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves left
//    Node n1 = n;
//    n1.craneLocation = 0;
//    n1.cranePos = {0, 1};

//     //crane moves left with box
//    Node n2 = n;
//    n2.craneLocation = 0;
//    n2.cranePos = {3, 1};
//    n2.ship.at(3).at(2) = e;
//    n2.ship.at(3).at(1) = s;

//    //crane moves right
//    Node n3 = n;
//    n3.craneLocation = 0;
//    n3.cranePos = {0, 3};

  

//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);
//    expectedNodes.push_back(n3);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 21 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
//  Move crane left, crane stays on ship; Move crane right, stays on ship
//  testing Expand node (no containers)*/
// bool expandTest22(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest = expandNode(n);

//     //right
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 2;
    
//     //left
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 2;

  
    
//     vector<Node> expectedNodes;

//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 22 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
//  Move crane left, crane stays on ship; Move crane right, stays on ship
//  testing Expand node (has box)*/
// bool expandTest23(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest = expandNode(n);

//     //left without a box
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 2;

//     //left with box
//     Node n3 = n;
//     n3.cranePos = {3,1};
//     n3.craneLocation = 2;
//     n3.buffer.at(row).at(col) = e;
//     n3.buffer.at(row + 3).at(col - 1) = s;

//     //right without a box
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 2;

//     //right with box
//     Node n4 = n;
//     n4.cranePos = {3,3};
//     n4.craneLocation = 2;
//     n4.buffer.at(row).at(col) = e;
//     n4.buffer.at(row + 3).at(col  + 1) = s;
    
//     vector<Node> expectedNodes;
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n3);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 23 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
// Move crane left, stays in buffer.
// Move crane right, crane goes to truck and ship (no wall).
//  (container -- not unloadable)*/
// bool expandTest24(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves right to ship
//     Node n1 = n;
//     n1.craneLocation = 0;
//     n1.cranePos = {0, 0};
    
//     // crane moves right with box moves to ship
//     Node n2 = n;
//     n2.craneLocation = 0;
//     n2.cranePos = {0,0};
//     n2.buffer.at(0).at(3) = e;
//     n2.ship.at(0).at(0) = s;

//     //crane moves right to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};

//     // crane moves left stays on buffer
//     Node n4 = n;
//     n4.cranePos = {0,2};
//     n4.craneLocation = 2;


//     // crane moves left with box stays in buffer
//     Node n5 = n; 
//     n5.craneLocation = 2;
//     n5.cranePos = {3,2};
//     n5.buffer.at(0).at(3) = e;
//     n5.buffer.at(3).at(2) = s;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 24 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
// Move crane left, stays in buffer.
// Move crane right, crane goes to truck and ship (no wall).
//  (container -- is unloadable)*/
// bool expandTest25(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,u},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves right to ship
//     Node n1 = n;
//     n1.craneLocation = 0;
//     n1.cranePos = {0, 0};
    
//     // crane moves right with box moves to ship
//     Node n2 = n;
//     n2.craneLocation = 0;
//     n2.cranePos = {0,0};
//     n2.buffer.at(0).at(3) = e;
//     n2.ship.at(0).at(0) = u;

//     //crane moves right to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};
   

//     //crane moves right to truck with box
//     Node n4 = n;
//     n4.craneLocation = 1;
//     n4.cranePos = {1,0};
//     n4.buffer.at(0).at(3) = e;

//     // crane moves left stays on buffer
//     Node n5 = n;
//     n5.cranePos = {0,2};
//     n5.craneLocation = 2;


//     // crane moves left with box stays in buffer
//     Node n6 = n; 
//     n6.craneLocation = 2;
//     n6.cranePos = {3,2};
//     n6.buffer.at(0).at(3) = e;
//     n6.buffer.at(3).at(2) = u;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n2);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);
//     expectedNodes.push_back(n6);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 25 passed" << endl;
//     return true;
// }

// /*Test Description: Crane starts in buffer
// Move crane left, stays in buffer.
// Move crane right, crane goes to truck and ship (wall).
//  (container -- is unloadable)*/
// bool expandTest26(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,u},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//     // crane moves right to ship
//     Node n1 = n;
//     n1.craneLocation = 0;
//     n1.cranePos = {0, 0};
    

//     //crane moves right to truck
//     Node n3 = n;
//     n3.craneLocation = 1;
//     n3.cranePos = {1,0};
   

//     //crane moves right to truck with box
//     Node n4 = n;
//     n4.craneLocation = 1;
//     n4.cranePos = {1,0};
//     n4.buffer.at(0).at(3) = e;

//     // crane moves left stays on buffer
//     Node n5 = n;
//     n5.cranePos = {0,2};
//     n5.craneLocation = 2;


//     // crane moves left with box stays in buffer
//     Node n6 = n; 
//     n6.craneLocation = 2;
//     n6.cranePos = {3,2};
//     n6.buffer.at(0).at(3) = e;
//     n6.buffer.at(3).at(2) = u;

//     expectedNodes.push_back(n1);
//     expectedNodes.push_back(n3);
//     expectedNodes.push_back(n4);
//     expectedNodes.push_back(n5);
//     expectedNodes.push_back(n6);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 26 passed" << endl;
//     return true;
// }


// /*Test Description: Crane starts in buffer.
// Move crane left, OUT OF BOUNDS.
//  Move crane right, stays in buffer
//  (container stays on ship -- not unloadable)*/
// bool expandTest27(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,s,s},

//     };

//      n.buffer ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,e,e,e},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves right
//    Node n1 = n;
//    n1.craneLocation = 2;
//    n1.cranePos = {0, 1};

//    //crane moves right with box
//    Node n2 = n;
//    n2.craneLocation = 2;
//    n2.cranePos = {3, 1};
//    n2.buffer.at(0).at(0) = e;
//    n2.buffer.at(3).at(1) = s;

//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 27 passed" << endl;
//     return true;
// }

// /*Test Description: Move crane left, stays on ship
//  Move crane right stays on ship;
//  to the left has a wall; to the right does not have a wall
//  (container stays on buffer -- not unloadable)*/
// bool expandTest28(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,s,e,e},
//         {e,s,e,s},
//         {e,s,e,s},
//         {e,s,s,s},

//     };

//      n.ship ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves left
//    Node n1 = n;
//    n1.craneLocation = 2;
//    n1.cranePos = {0, 1};

//    //crane moves right
//    Node n2 = n;
//    n2.craneLocation = 2;
//    n2.cranePos = {0, 3};

//    //crane moves right with box
//    Node n3 = n;
//    n3.craneLocation = 2;
//    n3.cranePos = {0, 3};
//    n3.buffer.at(3).at(2) = e;
//    n3.buffer.at(0).at(3) = s;

//    expectedNodes.push_back(n2);
//    expectedNodes.push_back(n3);
//    expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 28 passed" << endl;
//     return true;
// }

// /*Test Description: 
// Crane starts in buffer
// Move crane left, stays on ship.
// Move crane right stays on ship.
// To the left does not have a wall; to the right does have a wall
//  (container stays on ship -- not unloadable)*/
// bool expandTest29(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,s,s},

//     };

//      n.ship ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //crane moves left
//    Node n1 = n;
//    n1.craneLocation = 2;
//    n1.cranePos = {0, 1};

//     //crane moves left with box
//    Node n2 = n;
//    n2.craneLocation = 2;
//    n2.cranePos = {3, 1};
//    n2.buffer.at(3).at(2) = e;
//    n2.buffer.at(3).at(1) = s;

//    //crane moves right
//    Node n3 = n;
//    n3.craneLocation = 2;
//    n3.cranePos = {0, 3};

//    expectedNodes.push_back(n3);
//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 29 passed" << endl;
//     return true;
// }

// /*Test Description: 
// Crane starts in truck (Ship does not have a wall, Buffer does not have wall) */

// bool expandTest30(){

//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 1; //starts on truck
//     int row = 1;
//     int col = 0;
//     n.numToLoad = 1;
//     n.cranePos = {row, col};

//     n.buffer ={
//         {e,e,e,e},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,s,s},   

//     };

//      n.ship ={
//         {e,e,e,e},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//     //nodes to test
//    vector<Node> nodesToTest = expandNode(n);

//    //expected nodes
//    vector<Node> expectedNodes;

//    //try crane - buffer
//    // try crane - ship
//    // try contaner - ship

//    //crane moves left
//    Node n1 = n;
//    n1.cranePos = {0,3};
//    n1.craneLocation = 2;

//    // crane moves left with a box
//    Node n2 = n;
//    n2.buffer.at(0).at(3) = s;
//    n2.cranePos = {0,3};
//    n2.craneLocation = 2;
//    n2.numToLoad = 0;

//    // crane moves right
//    Node n3 = n;
//    n3.cranePos = {0,0};
//    n3.craneLocation = 0;

//    // crane moves right wit a box
//    Node n4 = n;
//    n4.ship.at(0).at(0) = s;
//    n4.cranePos = {0,0};
//    n4.craneLocation = 0;
//    n4.numToLoad = 0;


//    expectedNodes.push_back(n1);
//    expectedNodes.push_back(n2);
//    expectedNodes.push_back(n3);
//    expectedNodes.push_back(n4);

   

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         cout << "Testing Ship..." << endl;
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: ( row: " << j  << ", col: " << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//           cout << "Testing Buffer..." << endl;
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 30 passed" << endl;
//     return true;
// }

// bool expandTest100(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    justCraneMovesLeftOrRight(n, craneMoves, 0, nodesToTest);


//     //left
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 0;

//     //right
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 0;
    
//     vector<Node> expectedNodes;

//     expectedNodes.push_back(n1);
//     // expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 100 passed" << endl;
//     return true;

// }

// bool expandTest101(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,3,0}};
//    justCraneMovesLeftOrRight(n, craneMoves, 0, nodesToTest);

//     //right
//     Node n2 = n;
//     n2.cranePos = {0,3};
//     n2.craneLocation = 0;
    
//     vector<Node> expectedNodes;
//     expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 101 passed" << endl;
//     return true;
// }

// bool expandTest102(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,-1,0}};
//    justCraneMovesLeftOrRight(n, craneMoves, 0, nodesToTest);
    
//     vector<Node> expectedNodes;

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 102 passed" << endl;
//     return true;
// }

// bool expandTest103(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,4,0}};
//    justCraneMovesLeftOrRight(n, craneMoves, 0, nodesToTest);
    
//     vector<Node> expectedNodes;

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 103 passed" << endl;
//     return true;
// }

// bool expandTest104(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 0; // crane does already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    craneMovesLeftOrRightWithBox(n, craneMoves, 0, nodesToTest);


//     //left
//     Node n1 = n;
//     n1.cranePos = {0,1};
//     n1.craneLocation = 0;
//     n1.ship.at(row).at(col) = e;
//     n1.ship.at(row).at(col - 1) = s;
    
//     vector<Node> expectedNodes;

//     expectedNodes.push_back(n1);
//     // expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 104 passed" << endl;
//     return true;

// }

// bool expandTest105(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 0; // crane does already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,3,0}};
//    craneMovesLeftOrRightWithBox(n, craneMoves, 0, nodesToTest);


//     //left
//     Node n1 = n;
//     n1.cranePos = {0,3};
//     n1.craneLocation = 0;
//     n1.ship.at(row).at(col) = e;
//     n1.ship.at(row).at(col + 1) = s;
    
//     vector<Node> expectedNodes;

//     expectedNodes.push_back(n1);
//     // expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 105 passed" << endl;
//     return true;

// }

// bool expandTest106(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 0; // crane does already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,-1,0}};
//    craneMovesLeftOrRightWithBox(n, craneMoves, 0, nodesToTest);
    
//     vector<Node> expectedNodes;

   

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 106 passed" << endl;
//     return true;

// }

// bool expandTest107(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 0; // crane does already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},
//         {e,e,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,4,0}};
//    craneMovesLeftOrRightWithBox(n, craneMoves, 0, nodesToTest);
    
//     vector<Node> expectedNodes;

   

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 107 passed" << endl;
//     return true;

// }

// bool expandTest108(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 0; // crane does already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,s,s,e},
//         {e,s,s,e},
//         {e,s,s,e},
//         {e,s,s,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,2,0}};
//    craneMovesLeftOrRightWithBox(n, craneMoves, 0, nodesToTest);
    
//     vector<Node> expectedNodes;

   

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 108 passed" << endl;
//     return true;

// }



// bool expandTest109(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    justCraneMoveUp(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     // expectedNodes.push_back(n1);
//     // expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 109 passed" << endl;
//     return true;

// }

// bool expandTest110(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,3,0}};
//    justCraneMoveUp(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.cranePos = {0,2};

//     expectedNodes.push_back(n1);
//     // expectedNodes.push_back(n2);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 110 passed" << endl;
//     return true;

// }

// bool expandTest111(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,s,e},
//         {e,e,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,3,0}};
//    craneMovesUpWithBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;
//     Node n1 = n;
//     n1.ship.at(0).at(2) = s;
//     n1.ship.at(2).at(2) = e;
//     n1.cranePos = {0,2};

//      expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 111 passed" << endl;
//     return true;

// }

// bool expandTest112(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,s,e,e},
//         {e,s,e,e},
//         {e,s,s,e},
//         {e,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    craneMovesUpWithBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.cranePos = {0,2};
//     n1.ship.at(row).at(col) = e;
//     n1.ship.at(0).at(col) = s;

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 112 passed" << endl;
//     return true;

// }

// bool expandTest113(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,s,e,e},
//         {e,s,s,e},
//         {e,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    craneMovesUpWithBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.cranePos = {0,2};
//     n1.ship.at(row).at(col) = e;
//     n1.ship.at(0).at(col) = s;

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 113 passed" << endl;
//     return true;

// }

// bool expandTest114(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,s,s,e},
//         {e,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;
//    vector<vector<int>> craneMoves = {{0,1,0}};
//    craneMovesUpWithBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 114 passed" << endl;
//     return true;

// }

// bool expandTest115(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,1}};
   
//    justCraneStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.craneLocation = 1;
//     n1.cranePos = {1,0};

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 115 passed" << endl;
//     return true;

// }

// bool expandTest116(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},
//         {e,e,e,e},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    justCraneStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.craneLocation = 2;
//     n1.cranePos = {0,3};

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 116 passed" << endl;
//     return true;

// }

// bool expandTest117(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    justCraneStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.craneLocation = 2;
//     n1.cranePos = {0,3};

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 117 passed" << endl;
//     return true;

// }

// bool expandTest118(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 1;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    justCraneStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 118 passed" << endl;
//     return true;

// }

// bool expandTest119(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {u,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,1}};
   
//    craneMovesWithBoxStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.ship.at(0).at(0) = e;
//     n1.craneLocation = 1;
//     n1.cranePos = {1,0};

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 119 passed" << endl;
//     return true;

// }

// bool expandTest120(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,e},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    craneMovesWithBoxStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.ship.at(0).at(0) = e;
//     n1.craneLocation = 2;
//     n1.cranePos = {0,3};
//     n1.buffer.at(0).at(3) = s;

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 120 passed" << endl;
//     return true;

// }

// bool expandTest121(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    craneMovesWithBoxStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 121 passed" << endl;
//     return true;

// }

// bool expandTest122(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//    craneMovesWithBoxStartPortalShip(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 122 passed" << endl;
//     return true;

// }

// bool expandTest123(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on buffer
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,1}};
   
//    justCraneStartPortalBuffer(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.craneLocation = 1;
//     n1.cranePos = {1,0};

//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 123 passed" << endl;
//     return true;

// }

// bool expandTest124(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,0}};
   
//    justCraneStartPortalBuffer(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;
//     n1.craneLocation = 0;
//     n1.cranePos = {0,0};

//     expectedNodes.push_back(n1);

//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 124 passed" << endl;
//     return true;

// }

// bool expandTest125(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 3;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,0}};
   
//    justCraneStartPortalBuffer(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 125 passed" << endl;
//     return true;

// }

// bool expandTest126(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {e,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,0}};
   
//     craneMovesWithBoxStartPortalBuffer(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;
//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {0,0};
//     n1.buffer.at(0).at(3) = e;
//     n1.ship.at(0).at(0) = s;

//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 126 passed" << endl;
//     return true;

// }

// bool expandTest127(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 2; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 3;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,0}};
   
//     craneMovesWithBoxStartPortalBuffer(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 127 passed" << endl;
//     return true;

// }

// bool expandTest128(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 1; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{1,0,2}};
   
//     justCraneStartPortalTruck(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 2;
//     n1.cranePos = {0, 3};

//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 128 passed" << endl;
//     return true;

// }

// bool expandTest129(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 1; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     craneMovesWithBoxStartPortalTruck(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 129 passed" << endl;
//     return true;

// }

// bool expandTest130(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 1; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     justCraneStartPortalTruck(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {0, 0};

//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 130 passed" << endl;
//     return true;

// }

// bool expandTest131(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 1; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 1;
//     int col = 0;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,e,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     justCraneStartPortalTruck(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {0, 0};
//     n1.ship.at(0).at(0) = s;

//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 131 passed" << endl;
//     return true;

// }

// bool expandTest132(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 2;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,e,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,s,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     craneDropsOffBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {2, 2};
//     n1.ship.at(2).at(2) = s;


//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 132 passed" << endl;
//     return true;

// }

// bool expandTest133(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,s,e},
//         {s,e,e,e},
//         {s,s,s,e},
//         {s,s,s,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     craneDropsOffBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {1, 2};
//     n1.ship.at(1).at(2) = s;
//     n1.ship.at(0).at(2) = e;


//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " dd not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 133 passed" << endl;
//     return true;

// }

// bool expandTest134(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on truck
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,s,e},
//         {s,e,s,e},
//         {s,s,s,e},
//         {s,s,s,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     cranePicksUpBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {0, 2};
//     n1.ship.at(0).at(2) = s;


//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 134 passed" << endl;
//     return true;

// }

// bool expandTest135(){
//     Node n;

//     Container i = {"s. wall", 0.0, -1};	//invalid space
//     Container e = {"", 0.0, 0};		//empty space
//     Container u = {"unload", 0.0, 1};		//container to unload
//     Container s = {"stay", 0.0, 2};		//container stays on ship

//     n.craneLocation = 0; //starts on ship
//     n.prev.at(2).at(0) == 1; // crane does not already have a container
//     int row = 0;
//     int col = 2;
//     n.cranePos = {row, col};

//     n.ship ={
//         {s,e,s,e},
//         {s,e,e,e},
//         {s,s,e,e},
//         {s,s,s,e},

//     };

//      n.buffer ={
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},
//         {e,e,e,s},

//     };

//    vector<Node> nodesToTest;

//    vector<vector<int>> craneMoves = {{0,0,0}};
   
//     cranePicksUpBox(n, craneMoves, 0, nodesToTest);

//     vector<Node> expectedNodes;

//     Node n1 = n;

//     n1.craneLocation = 0;
//     n1.cranePos = {2, 2};
//     n1.ship.at(2).at(2) = s;
//     n1.ship.at(0).at(2) = e;


//     expectedNodes.push_back(n1);


//     if(nodesToTest.size() != expectedNodes.size()){
//         cout << "nodeToTest size: " << nodesToTest.size() << endl;
//         cout << "expectedNodes size: " << expectedNodes.size() << endl;
//         cout << "nodetToTest size does not equal to expectedNodes size" << endl;
//         return false;
//     }

//     //Test all nodes
//     for(int i = 0; i < nodesToTest.size(); i++){
//         Node test = nodesToTest.at(i);
//         Node expected = expectedNodes.at(i);
        
//         //Test for crane position
//         if(test.cranePos.first != expected.cranePos.first || test.cranePos.second != expected.cranePos.second){
//             cout << "Crane position for node at index " << i << " did not match." << endl;
//             cout << "Crane position for test: ( " << test.cranePos.first << " , " << test.cranePos.second << " )" << endl;
//             cout << "Crane position for expected: ( " << expected.cranePos.first << " , " << expected.cranePos.second << " )" << endl;
//             return false;
//         }

//         //Test for current location
//         if(test.craneLocation != expected.craneLocation){
//             cout << "Crane Location for node at index " << i << " did not match." << endl;
//             cout << "Crane Location for test: " << test.craneLocation << endl;
//             cout << "Crane Location for expected: " << expected.craneLocation << endl;
//             return false;
//         }

//         //Test for state of ship
//         for(int j = 0; j < test.ship.size(); j++ ){

//             for(int k = 0; k < test.ship.at(0).size(); k++){

//                 if(test.ship.at(j).at(k).name != expected.ship.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.ship.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.ship.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.ship.at(j).at(k).status != expected.ship.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.ship.at(j).at(k).weight != expected.ship.at(j).at(k).weight){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.ship.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.ship.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }

//         //Test for state of buffer
//         for(int j = 0; j < test.buffer.size(); j++ ){

//             for(int k = 0; k < test.buffer.at(0).size(); k++){

//                 if(test.buffer.at(j).at(k).name != expected.buffer.at(j).at(k).name){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container names do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test name: " << test.buffer.at(j).at(k).name << endl;
//                     cout << "Expected name: " << expected.buffer.at(j).at(k).name << endl;
//                     return false;
//                 }

//                 //Testing for status
//                 if(test.buffer.at(j).at(k).status != expected.buffer.at(j).at(k).status){
//                     cout << "Node at index " << i << " did not match." << endl;
//                     cout << "Container status do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).status << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).status << endl;
//                     return false;
//                 }
                
//                 //Testing for weight
//                  if(test.buffer.at(j).at(k).weight != expected.buffer.at(j).at(k).weight){
//                     cout << "Node at index " << i << " dd not match." << endl;
//                     cout << "Container weight do not match at pos: (" << j  << "," << k <<")" << endl;
//                     cout << "Test status: " << test.buffer.at(j).at(k).weight << endl;
//                     cout << "Expected status: " << expected.buffer.at(j).at(k).weight << endl;
//                     return false;
//                 }

                
//             }


//         }
//     }

//     cout << "Test 135 passed" << endl;
//     return true;

// }







// int main(){
// cout << "Test suite for ship" << endl;
//     craneMovementTest1();
//     craneMovementTest2();
//     craneMovementTest3();
//     craneMovementTest4();
//     craneMovementTest5();
//     craneMovementTest6();
   

//     cout << "" << endl;
//     cout << "" << endl;

// cout << "Test suite for buffer" << endl;
//     craneMovementTest7();
//     craneMovementTest8();
//     craneMovementTest9();
//     craneMovementTest10();
//     craneMovementTest11();
//     craneMovementTest12();

//     cout << "" << endl;
//     cout << "" << endl;

// cout << "Test suite for truck" << endl;
//     craneMovementTest13();

//     cout << "" << endl;
//     cout << "" << endl;

// cout << "Test suite for expandNodeTest" << endl;

//     //tests for ship
//     expandTest14();
//     expandTest15();
//     // expandTest16();
//     // expandTest17();
//     // expandTest18();
//     // expandTest19();
//     // expandTest20();
//     // expandTest21();

//     // //tests for buffer
//     // expandTest22();
//     // expandTest23();
//     // expandTest24();
//     // expandTest25();
//     // expandTest26();
//     // expandTest27();
//     // expandTest28();
//     // expandTest29();

//     // //tests for truck
//     // expandTest30();


//     //justCraneMovesLeftOrRight
//         // move left
//         expandTest100();

//         //move right
//         expandTest101();

//         // cannot move left
//         expandTest102();

//          //cannot move right
//          expandTest103();

//     //CraneMovesLeftOrRightWithBox
//         //move left
//         expandTest104();

//         //move right
//         expandTest105();

//         //cannot move left
//         expandTest106();

//         //cannot move right
//         expandTest107();

//         //check to see if there is a wall (left)
//         expandTest108();

//     //Just crane moves up

//         //empty col next to it
//         expandTest109();

//         //col next to it is full
//         expandTest110();


//     //Crane with box crane moves up

//         //empty col next to it
//         expandTest111();

//         //col next to it is full
//         expandTest112();

//         //col next to it has some containers
//         expandTest113();

//         //col next to it is lower than crane
//         expandTest114();

//     //Just Crane start from ship

//         //moving to truck
//         expandTest115();

//         // moving to buffer
//         expandTest116();

//         // buffer portal is occupied
//         expandTest117();

//         // not at position (0,0) on ship
//         expandTest118();

//     //Crane with box starts from ship

//         //moving to truck (unloading)
//         expandTest119();

//         //moving to buffer
//         expandTest120();

//         //buffer portal is occupied
//         expandTest121();

//         //not at right start position
//         expandTest122();

//     //Just crane starts from buffer

//         //moving to truck
//         expandTest123();

//         // moving to ship
//         expandTest124();

//         // not in right position
//         expandTest125();

//     //crane moves with box starts from buffer

//         // move to ship
//         expandTest126();

//         // ship portal is occupied
//         expandTest127();

//     //Just crane start from truck

//         //move to buffer
//         expandTest128();

//         //move to ship
//         expandTest129();

//     //Crane with box starts on truck

//         // crane moves to ship (nothing to load)
//         expandTest130();

//         // crane moves to ship (loading)
//         expandTest131();

//     //crane drops off box

//         //same row as crane
//         expandTest132();

//         // diffrent row as crane
//         expandTest133();

//     //crane picks up box

//         //same row as crane
//         expandTest134();

//         // diffrent row as crane
//         expandTest135();

//     return 0;
// }

