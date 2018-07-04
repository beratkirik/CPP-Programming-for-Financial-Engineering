//
//  PointArray.cpp
//  Exercise 6
//
//  Created by Changheng Chen on 2/2/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "PointArray.hpp"
#include "SizeMismatchException.hpp"
#include "TotalLengthException.hpp"

namespace chako
{
    namespace Containers
    {
        // Default constructor
        PointArray::PointArray() : Array<CAD::Point>()
        {
            //cout << "Point Array default constructor..." << endl;
        }
        
        // Constructor with array size
        PointArray::PointArray(int size) : Array<CAD::Point>(size)
        {
            //cout << "Point Array constructor with size..." << endl;
        }
        
        // Copy constructor
        PointArray::PointArray(const PointArray& source) : Array<CAD::Point>(source)
        {
            //cout << "Point Array copy constructor..." << endl;
        }
        
        // Destructor
        PointArray::~PointArray() 
        {
            //cout << "Bye my Point Array..." << endl;
        }
        
        // Assignment operator
        PointArray& PointArray::operator = (const PointArray& source)
        {
            if (this == &source)
                return *this;
            
            Array<CAD::Point>::operator = (source);
            return *this;
        }
        
        // Total length between the points in the array
        double PointArray::Length() const
        {
            if (this->Size() < 2)
                throw TotalLengthException(this->Size()); // Arrays of size<2 have no total length!
            
            double length = 0.0;
            for (int i = 1; i < this->Size(); i++)
            {
                length += (this->GetElement(i-1)).Distance(this->GetElement(i)); //Point1.Distance(Point2)
            }
            
            return length;
        }
        
    }
}
