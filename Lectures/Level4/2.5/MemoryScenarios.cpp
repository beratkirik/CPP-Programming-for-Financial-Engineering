// MemoryScenarios.cpp
//
// Lifecycle management on the heap. Normal 
// scenarios.
//
// Some exceptions:
//
//	1. No memory allocated for a ptr
//	2. Accessing null/undefined ptr
//	3. Ptr goes out of scope but pointee (memory has been cleaned up)
//	4. 'Double' delete
//

#include <iostream>
using namespace std;

struct A
{ // Simple class

	int k;
	
	// Note colon syntax in constructors!!!!!
	A(int val = 0): k(val) {}
	A(const A& source) : k(source.k + 2) {}

	~A() { cout << "Bye object of class A, value: " << k << endl;}
};


int main()
{
	{
		A* a = new A();
		delete a;
	}
	cout << "Phase 1\n";

	{
		A* a = new A();

		
	//	delete a;
	}
	cout << "Phase 2\n";

	{
		A* a = new A();
		delete a;
		//delete a; // RT error
	}
	cout << "Phase 3\n";

	// Arrays
	{
		int N = 4;
		A* arr = new A[N];
		delete [] arr;
	}
	cout << "Phase 4\n";

	{
		int N = 4;
		A* arr = new A[N];
		
		// 1st element deleted, then RT error
		// delete arr;
	}
	cout << "Phase 4A\n";

	{
		int N = 2000000;
		A* arr = new A[N];
	}
	cout << "Phase 4B\n";

	{
		A* a = new A();
		A* b = a;
		delete a;
	}
	cout << "Phase 7\n";

	{
		A* a = new A(1);
		A b(*a);
		delete a;
	}
	cout << "Phase 8\n";

	{
		A* a = new A();
		A b(*a);
		//delete a;
	}
	cout << "Phase 9\n";

	{
		A* a = new A();
		A* b = a;
		//delete a;
	}
	cout << "Phase 10\n";

	int* pi;

	pi = NULL;
	pi = new int;
	*pi = 100;
	cout << *pi << endl;
	//pi = NULL;

	delete pi;
	//delete pi;

	return 0;
}

