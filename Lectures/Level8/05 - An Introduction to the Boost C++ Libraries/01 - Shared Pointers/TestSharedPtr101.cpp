// TestSharedPtr.cpp
//
// Testing shared pointers in boost
//
//	1. As private member data in classes
//	2. Storing shared pointers in STL collections
//
// (C)Datasim Education BV 2008-2011
//

#include <vector>
#include "boost/shared_ptr.hpp"
#include "Point.hpp"


// These classes are an upgrade from raw pointers to shared pointers
class C1
{ 
private:
	//double* d; OLD WAY 
	boost::shared_ptr<double> d;

public:
	C1(boost::shared_ptr<double> value) : d(value) {}
	virtual ~C1() { cout << "\nC1 destructor\n";}
	void print() const { cout << "Value " << *d; }
};

class C2
{ 
private:
	//double* d; // OLD WAY
	boost::shared_ptr<double> d;

public:
	C2(boost::shared_ptr<double> value) : d(value) {}
	virtual ~C2() { cout << "\nC2 destructor\n"; }
	void print() const { cout << "Value " << *d; }
};

class D1
{ 
private:
	boost::shared_ptr<Point> p;

public:
	D1(boost::shared_ptr<Point> value) : p(value) {}
	virtual ~D1() { cout << "\nD1 destructor\n";}
	void print() const { cout << "\nValue " << *p; }
};

class D2
{ 
private:	
	boost::shared_ptr<Point> p;

public:
	D2(boost::shared_ptr<Point> value) : p(value) {}
	virtual ~D2() { cout << "\nD2 destructor\n";}
	void print() const { cout << "\nValue " << *p; }
};

///
class Base
{ // Class with non-virtual destructor
private:
	
public:
	Base() { }
	virtual ~Base() { cout << "Base destructor\n\n"; }
	virtual void print() const = 0;
};

class Derived : public Base
{ // Derived class
private:
		
public:
	Derived() : Base() { }
	~Derived() { cout << "Derived destructor\n"; }
	void print() const { cout << "derived object\n";}
};

// Simple creator (FACTORY) function
boost::shared_ptr<Base> createBase()
{

	// In later versions return other derived types
	boost::shared_ptr<Base> result(new Derived());

	return result;
}


void doIt()
{
	{
		cout << "Built-in types\n";
		boost::shared_ptr<double> commonValue(new double (3.1415));
		cout << "Reference count: " << commonValue.use_count() << endl;

		{
			C1 object1(commonValue);
	//		object1.print();
		}

		C2 object2(commonValue);
	//	object2.print();
	}

	cout << "\nUser-defined types\n";

	// Now with user-defined types, Create dynamic memory
	boost::shared_ptr <Point> myPoint (new Point(1.0, 23.3));
	cout << "Reference count: " << myPoint.use_count() << endl;
	{
		D1 point1(myPoint);
		cout << "Reference count: " << myPoint.use_count() << endl;
		D1 point2(myPoint);
		cout << "Reference count: " << myPoint.use_count() << endl;
		//point1.print();

	}
	cout << "Reference count: " << myPoint.use_count() << endl;
	{
		D2 object3(myPoint);
		//object3.print();
		cout << "Reference count: " << myPoint.use_count() << endl;
	}
	
	cout << "Reference count: " << myPoint.use_count() << endl;


	// Use in STL containers
	typedef std::vector<boost::shared_ptr<Base> > ContainerType;
	typedef ContainerType::iterator iterator;

	// Create a vector of objects 
	ContainerType con;
	const int N = 4;
	for (int j = 0; j < N; ++j)
	{
		con.push_back(createBase());
	}

	// Now iterate and print
	iterator myIter;
	for (myIter = con.begin(); myIter != con.end(); ++myIter)
	{

		(*myIter) -> print();
	}
}

int main()
{
	doIt();

	return 0;
}
