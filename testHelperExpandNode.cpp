
#include "expand.hpp"
using namespace std;

//Tests for getWallsForZone (S1)

//no ship has walls (S1T1)

bool S1T1(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{e,e,e},
		{e,e,e},
		{e,e,e}
	};

	vector<int> returnedValues = getWallsForZone(n, 0);

	vector<int> expectedValues = {0,0,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 

// ship has few walls (S1T2)
bool S1T2(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{e,s,e},
		{e,u,e},
		{e,u,e}
	};

	vector<int> returnedValues = getWallsForZone(n, 0);

	vector<int> expectedValues = {0,1,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 


// ship walls at the edges (S1T3)
bool S1T3(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{u,e,u},
		{s,e,s},
		{s,e,s}
	};

	vector<int> returnedValues = getWallsForZone(n, 0);

	vector<int> expectedValues = {1,0,1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 


// ship has all walls(S1T4)
bool S1T4(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{u,u,u},
		{u,u,u},
		{u,u,u}
	};

	vector<int> returnedValues = getWallsForZone(n, 0);

	vector<int> expectedValues = {1,1,1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 


//no buffer has walls (S1T5)
bool S1T5(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{e,e,e},
		{e,e,e},
		{e,e,e}
	};

	vector<int> returnedValues = getWallsForZone(n, 1);

	vector<int> expectedValues = {0,0,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 


// buffer has few walls(S1T6)
bool S1T6(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{e,s,e},
		{e,u,e},
		{e,u,e}
	};

	vector<int> returnedValues = getWallsForZone(n, 1);

	vector<int> expectedValues = {0,1,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 

// buffer walls at the edges(S1T7)
bool S1T7(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{u,e,u},
		{u,e,u},
		{u,e,u}
	};

	vector<int> returnedValues = getWallsForZone(n, 1);

	vector<int> expectedValues = {1,0,1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 

// buffer has all walls(S1T8)
bool S1T8(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{u,u,u},
		{u,u,u},
		{u,u,u}
	};

	vector<int> returnedValues = getWallsForZone(n, 1);

	vector<int> expectedValues = {1,1,1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;




} 


//Tests for getContainerDataFromCranePos (S2)

//Test for no containers in specific row (ship)
bool S2T1(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{e,e,e},
		{e,e,e},
		{e,e,e}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 1, 0);

	vector<int> expectedValues = {-1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Test for one container in row (ship)
bool S2T2(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{e,e,s},
		{e,u,s},
		{u,u,u}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 0, 0);

	vector<int> expectedValues = {2,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Test full row -- stack (ship)
bool S2T3(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{e,e,s},
		{e,u,s},
		{u,u,u}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 2, 0);

	vector<int> expectedValues = {0,2};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Test for no containers in specific row (buffer)
bool S2T4(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{e,e,e},
		{e,e,e},
		{e,e,e}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 0, 2);

	vector<int> expectedValues = {-1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Test for one container in row (buffer)
bool S2T5(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{s,e,e},
		{s,e,u},
		{s,u,u}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 1, 2);

	vector<int> expectedValues = {2,1};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Test full row -- stack (buffer)
bool S2T6(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{s,e,e},
		{s,e,u},
		{s,u,u}
	};

	vector<vector<int>> returnedValues = getContainerDataFromCranePos(n, 0, 2);

	vector<int> expectedValues = {0,0};
	for(int i = 0; i < returnedValues.size(); i++){
		if(returnedValues.at(0).at(i) != expectedValues.at(i)){
			return false;
		}
	}

	return true;
} 

//Not sure about a test for the truck


//Tests for FindEmptySpotInCol (S3)

//Test for no empty spots in specific row (ship)
bool S3T1(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{s,s,s},
		{s,s,s},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 1, 0);

	int expectedValue = 0;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}

//Test for one empty spot one from the bottom (ship)
bool S3T2(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{s,s,e},
		{s,s,e},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 2, 0);

	int expectedValue = 2;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}

//Test for one empty spot -- stack(ship)
bool S3T3(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.ship = {
		{s,e,e},
		{s,s,e},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 1, 0);

	int expectedValue = 1;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}

//Test for no empty spots in specific row (buffer)
bool S3T4(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{s,s,s},
		{s,s,s},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 1, 2);

	int expectedValue = 0;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}

//Test for one empty spot one from the bottom (buffer)
bool S3T5(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{s,s,e},
		{s,s,e},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 2, 2);

	int expectedValue = 2;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}

//Test for one empty spot -- stack(buffer)
bool S3T6(){

	Container i = {"", 0.0, -1};	//invalid space
	Container e = {"", 0.0, 0};		//empty space
	Container u = {"", 0.0, 1};		//container to unload
	Container s = {"", 0.0, 2};		//container stays on ship

	Node n;

	n.buffer = {
		{s,e,e},
		{s,s,e},
		{s,s,s}
	};

	int returnedValue = findTopContainerInCol(n, 1, 2);

	int expectedValue = 1;

	if(returnedValue != expectedValue){
		return false;
	}
	return true;
}


//Not sure about a test for the truck


	
//Tests for swapContainers


//Tests for expandNode

int main() 
{ 
	/*NEED EVERY TEST SUITE BEFORE TO PASS BEFORE MOVING ON TO THE OTHER TESTS*/

	// Tests for getWallsForZone
	cout << "Tests for getWallsForZone (S1)" << endl;
	
	(S1T1()) ? cout << "S1T1 passed" << endl : cout << "S1T1 failed" << endl;
	(S1T2()) ? cout << "S1T2 passed" << endl : cout << "S1T2 failed" << endl;
	(S1T3()) ? cout << "S1T3 passed" << endl : cout << "S1T3 failed" << endl;
	(S1T4()) ? cout << "S1T4 passed" << endl : cout << "S1T4 failed" << endl;
	(S1T5()) ? cout << "S1T5 passed" << endl : cout << "S1T5 failed" << endl;
	(S1T6()) ? cout << "S1T6 passed" << endl : cout << "S1T6 failed" << endl;
	(S1T7()) ? cout << "S1T7 passed" << endl : cout << "S1T7 failed" << endl;
	(S1T8()) ? cout << "S1T8 passed" << endl : cout << "S1T8 failed" << endl;

	cout << endl;
	cout << endl;

	cout << "Tests for getContainerDataFromCranePos (S2)" << endl;

	(S2T1()) ? cout << "S2T1 passed" << endl : cout << "S2T1 failed" << endl;
	(S2T2()) ? cout << "S2T2 passed" << endl : cout << "S2T2 failed" << endl;
	(S2T3()) ? cout << "S2T3 passed" << endl : cout << "S2T3 failed" << endl;
	(S2T4()) ? cout << "S2T4 passed" << endl : cout << "S2T4 failed" << endl;
	(S2T5()) ? cout << "S2T5 passed" << endl : cout << "S2T5 failed" << endl;
	(S2T6()) ? cout << "S2T6 passed" << endl : cout << "S2T6 failed" << endl;

	cout << endl;
	cout << endl;

	cout << "Tests for FindEmptySpotInCol (S3)" << endl;
	(S3T1()) ? cout << "S3T1 passed" << endl : cout << "S3T1 failed" << endl;
	(S3T2()) ? cout << "S3T2 passed" << endl : cout << "S3T2 failed" << endl;
	(S3T3()) ? cout << "S3T3 passed" << endl : cout << "S3T3 failed" << endl;
	(S3T4()) ? cout << "S3T4 passed" << endl : cout << "S3T4 failed" << endl;
	(S3T5()) ? cout << "S3T5 passed" << endl : cout << "S3T5 failed" << endl;
	(S3T6()) ? cout << "S3T6 passed" << endl : cout << "S3T6 failed" << endl;


	return 0;
} 




