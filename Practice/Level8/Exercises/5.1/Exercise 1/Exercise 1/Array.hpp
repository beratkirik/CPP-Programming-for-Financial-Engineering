//
//  Array.hpp
//  Exercise 1
//
//  Created by Changheng Chen on 2/9/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp


namespace chako
{
    namespace Containers
    {
        template <typename T> class Array;
    }
}


template <typename T>
class chako::Containers::Array
{
private:
    T *m_data;
    int m_size;
    static int d_size;                                // Default size
    
public:
    // Constructors, destructor, and assigment operator
    Array();                                          // Default constructor
    Array(int size);                                  // Constructor with size
    Array(const Array<T>& source);                    // Copy constructor
    virtual ~Array();                                 // Destructor
    Array<T>& operator = (const Array<T>& source);    // Assignment operator
    
    // Getter functions
    int Size() const;                                 // Get the size of array
    int DefaultSize() const;                          // Get the default size of the array
    T& GetElement(int index) const;                   // Get the element with index "index"
    
    // Setter functions
    void DefaultSize(int size);                       // Set the default size
    void SetElement(int index, const T& p);           // Set the element with index "index"
    
    // Operator overloading
    T& operator [] (int index);                       // Square bracket operator for accessing element
    const T& operator [] (int index) const;           // Return a constant reference to T
};

#ifndef Array_cpp 
#include "Array.cpp"
#endif

#endif /* Array_hpp */
