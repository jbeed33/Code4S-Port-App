#include <iostream>
#include "Balance.hpp"

using namespace std;

//Nothing inside both buffer and ship
bool Test1(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e}
        
	};

     n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 0;

    return ((result == expect) ? true : false);
}

//Nothing inside buffer only one ship
bool Test2(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;
    n.cranePos = {row, col};
    n.prev.at(2).at(0) = 1;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, s, e, e, e, e, e, e, e}
        
	};

      n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 4;

    return ((result == expect) ? true : false);
}

//Nothing inside buffer only ship (Balance)
bool Test3(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, s, e, e, s, e, e, e, e}
        
	};

      n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 0;

    return ((result == expect) ? true : false);
}

//Nothing inside both buffer only ship (Not Balance)
bool Test4(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, s, e, e, s, e, e, s, e}
        
	};

      n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 3;

    return ((result == expect) ? true : false);
}

//Nothing inside both buffer only ship (Balanced, but crane is holding container)
bool Test5(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 5;
    n.cranePos = {row, col};
    n.prev.at(2).at(0) = 0;

     n.ship = {

		{e, e, e, e, e, s, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, s, e, e, s, e, e, s, e}
        
	};

      n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 7;

    return ((result == expect) ? true : false);
}

//Nothing inside both buffer only ship (Balanced, but crane is holding container)
bool Test6(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 8;
    int col = 5;
    n.cranePos = {row, col};
    n.prev.at(2).at(0) = 1;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, s, s, e, s, e, e, s, e}
        
	};

      n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 0;

    return ((result == expect) ? true : false);
}

//Nothing inside ship but one in buffer
bool Test7(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e}
        
	};

     n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, s},
	};

    double result = b.heuristic(n);
    int expect = 6;

    return ((result == expect) ? true : false);
}

//Nothing inside ship and buffer (Crane is buffer) -> Balanced
bool Test8(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 23;

    n.craneLocation = 2;
    n.cranePos = {row, col};

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e}
        
	};

     n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 0;

    return ((result == expect) ? true : false);
}

//Nothing inside ship and buffer (Crane is buffer and has box)
bool Test9(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 23;

    n.craneLocation = 2;
    n.cranePos = {row, col};
    n.prev.at(2).at(0) = 0;

     n.ship = {

		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e}
        
	};

     n.buffer = {

		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, s},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
		{e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
        {e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e, e},
	};

    double result = b.heuristic(n);
    int expect = 11;

    return ((result == expect) ? true : false);
}


int main(){
    cout << "Tests for Balance Heuristic" << endl;
    cout << " " << endl;
    cout << "Test 1" <<  ( (Test1()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 2" <<  ( (Test2()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 3" <<  ( (Test3()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 4" <<  ( (Test4()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 5" <<  ( (Test5()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 6" <<  ( (Test6()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 7" <<  ( (Test7()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 8" <<  ( (Test8()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    cout << "Test 9" <<  ( (Test9()) ? " Passed" : " Failed") << endl;
    cout << " " << endl;
    return 0;
} 