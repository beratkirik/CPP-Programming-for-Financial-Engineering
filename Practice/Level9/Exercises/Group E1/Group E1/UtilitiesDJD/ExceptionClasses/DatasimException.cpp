// DatasimException.cpp
//
//
// Last Modification Dates:
//
// 2005-12-16 DD Kick-off
//
// (C) Datasim Education BV 2005-2006
//

#include "DatasimException.hpp"

DatasimException::DatasimException()
{
		mess = meth = why = string();
		result = vector<string>(3);	
		result[0] = mess;
		result[1] = meth;
		result[2] = why;

}

DatasimException::DatasimException (const string& message, const string& method,
									const string& extraInfo)
{
		mess = message;
		meth = method;
		why = extraInfo;
		result = vector<string>(3);	
		
		result[0] = mess;
		result[1] = meth;
		result[2] = why;

}

string DatasimException::Message() const 
{ 
	return mess; 
}

string DatasimException::rationale() const 
{ 
	return why; 
}

string DatasimException::Method() const 
{ 
	return meth; 
}

vector<string> DatasimException::MessageDump() const
{ // Full message
	
	return result;
}
	
void DatasimException::print() const
{ 

	// Variant part
	vector<string> r = MessageDump();

	cout << endl << r[0] << endl;
	// Invariant part
	for (int j = 1; j < r.size(); j++)
	{
		cout << '\t' << r[j] << endl;
	}
}

