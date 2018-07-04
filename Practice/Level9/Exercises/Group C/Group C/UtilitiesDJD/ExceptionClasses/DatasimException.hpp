// DatasimExceptions.hpp
//
// Ubiquitous class for basic exception handling
//
// (C) Datasim Education BV 2005 - 2006
//

#ifndef DatasimExceptions_HPP
#define DatasimExceptions_HPP

#include <string>
#include <vector>
using namespace std;
#include <iostream>

class DatasimException
{ // Base class for my current exceptions
private:
		string mess;			// The error message
		string meth;			// The method that threw the exception
		string why;				// More info on message

		// Redundant data
		vector<string> result;

public:
		DatasimException();
	
		DatasimException (const string& message, const string& method,
							const string& extraInfo);
		

		string Message() const;		// The message itself
		string rationale() const;	// Extra information
		string Method() const;		// In which method?

		// Al information in one packet
		vector<string> MessageDump() const;	// Length 3
	
		// Print the full packet
		virtual void print() const;
	
};


#endif