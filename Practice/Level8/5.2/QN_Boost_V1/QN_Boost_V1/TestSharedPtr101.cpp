//
//  TestSharedPtr101.cpp
//  QN_Boost_V1
//
//  Created by Changheng Chen on 2/8/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include <vector>
#include <boost/shared_ptr.hpp>
#include "Point.hpp"

// These classes are an upgrade from raw pointers to shared pointers
class C1
{
private:
    // double* d; OLD WAY
    boost::shared_ptr<double> d;
public:
    C1(boost::shared_ptr<double> value) : d(value) {}
    virtual ~C1() { cout << "\nC1 destructor\n" ;}
    void print() const { cout << "Value " << *d; }
};

class C2
{
private:
    // double* d; // OLD WAY
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
    virtual ~D1() { cout << "\nD1 destructor\n"; }
    void print() const { cout << "\nValue " << *p; }
};

class D2
{
private:
    boost::shared_ptr<Point> p;
public:
    D2(boost::shared_ptr<Point> value) : p(value) {}
    virtual ~D2() { cout << "\nD2 destructor\n"; }
    void print() const { cout << "\nValue " << *p; }
};

///
class Base
{ // Class with non-virtual destructor
private:
    
public:
    Base() {}
    virtual ~Base() { cout << "Base destructor\n\n"; }
    virtual void print() const = 0;
};

class Derived : public Base
{ // Derived class
private:
    
public:
    Derived() : Base() {}
    ~Derived() { cout << "Derived destructor\n"; }
    void print() const {cout << "derived object\n";}
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
        cout << "Reference count: " << commonValue.use_count() << endl; // 1
        
        {
            C1 object1(commonValue); // 2
            //object1.print();
        }
        
        // 1
        C2 object2(commonValue); // 2
        //object2.print();
    }
    
    // 0
    
    cout << "\nUser-defined types\n";
    
    // Now with user-defined types, Create dynamic memory
    boost::shared_ptr<Point> myPoint (new Point(1.0, 23.3));
    cout << "Reference count: " << myPoint.use_count() << endl; // 1
    {
        D1 point1(myPoint);
        cout << "Reference count: " << myPoint.use_count() << endl;
        D1 point2(myPoint);
        cout << "Reference count: " << myPoint.use_count() << endl;
        //point1.print()
        // 3
    }
    
    // 1
    
    cout << "Reference count: " << myPoint.use_count() << endl;
    {
        D2 object3(myPoint); // 2
        //object3.print();
        cout << "Reference count: " << myPoint.use_count() << endl;
    }
    
    cout << "Reference count: " << myPoint.use_count() << endl;
    
    
    
    // Use in STL constainers
    typedef std::vector< boost::shared_ptr<Base> > ContainerType;
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
