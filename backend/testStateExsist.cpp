#include <iostream>
#include "Balance.hpp"

using namespace std;

//test empty frontier and closed
bool test1(){

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


    bool result = b.stateExists(n);
    bool expect = false;

    (result == expect) ? expect = true : expect = false;

    return expect;

}

//same state
bool test2(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;
    n.craneLocation = 0;

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

    
    b.frontier.push_back(n);
    bool result = b.stateExists(n);
    bool expect = true;

    (result == expect) ? expect = true : expect = false;

    return expect;

}

//Diffrent huerstic
bool test3(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;
    n.craneLocation = 0;

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

    Node nodeToAdd = n;
    nodeToAdd.heuristic = 4;
    b.frontier.push_back(nodeToAdd);
    bool result = b.stateExists(n);
    bool expect = false;

    (result == expect) ? expect = true : expect = false;

    return expect;

}

//Diffrent huerstic but same next node
bool test4(){

    Container i = {"", 0.0, -1};	//invalid space
    Container e = {"", 0.0, 0};		//empty space
    Container u = {"", 0.0, 1};		//container to unload
    Container s = {"", 3.0, 2};		//container stays on ship

    Balance b;

    Node n;

    int row = 0;
    int col = 0;
    n.craneLocation = 0;
    n.heuristic = 4;

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

    Node nodeToAdd = n;
    nodeToAdd.heuristic = 4;
    nodeToAdd.cost = 100;

    Node nodeToAdd2 = n;
    nodeToAdd2.heuristic = 4;
    
    b.frontier.push_back(nodeToAdd);
    b.frontier.push_back(nodeToAdd2);
    bool result = b.stateExists(n);
    bool expect = true;

    (result == expect) ? expect = true : expect = false;

    return expect;

}

int main(){
    cout << "Test 1" << ((test1()) ? "Passed" : "Falied") << endl;
    cout << " " << endl;
    cout << "Test 2" << ((test2()) ? "Passed" : "Falied") << endl;
    cout << " " << endl;
    cout << "Test 3" << ((test3()) ? "Passed" : "Falied") << endl;
    cout << " " << endl;
     cout << "Test 4" << ((test4()) ? "Passed" : "Falied") << endl;
    cout << " " << endl;
    return 0;
}