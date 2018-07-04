//
//  TestDate101.cpp
//  Date101
//
//  Testing boost Data_time (large!) library
//
//  Created by Changheng Chen on 2/7/17.
//  Copyright © 2017 Changheng Chen. All rights reserved.
//

#include "boost/date_time/gregorian/gregorian.hpp"       // Types only plus I/O
#include "boost/date_time/gregorian/gregorian_types.hpp" // Types only, no I/O

#include <string>
using namespace std;
using namespace boost::gregorian;

void print(const date& myDate, const string& type = "")
{
    cout << "\nDate Information..." << type << "\n";
    cout << myDate << endl;
    cout << "Year: " << myDate.year() << ", Month: " << myDate.month() << ", Day: " << myDate.day() << endl;
    
    // Extra stuff.
    cout << "Day of week: " << myDate.day_of_week() << ", Day of year: " << myDate.day_of_year() << endl;
    cout << "End of month: " << myDate.end_of_month() << endl;
    cout << "ISO 8610 week number: " << myDate.week_number() << ", Day of year: " << myDate.julian_day() << endl;
}


int main()
{
    // Some basic constructors.
    try
    {
        date d1; print(d1); // produces not_a_date_time.
    }
    catch (bad_year& e)
    {
        cout << e.what() << endl; // Year not in valid range [1400, 10000]
    }
    
    // Create date from Gregorian year, month, and day.
    date myDate2(2011, May, 16); print(myDate2);
    
    // Copy constructor
    date myDate3(myDate2); print(myDate3);
    
    // Constructor at the 'extremes'.
    try
    {
        date myDate4(pos_infin); print(myDate4, "Positive infinity");
    }
    catch (bad_year& e)
    {
        cout << e.what() << endl;
    }
    
    try
    {
        date myDate5(neg_infin); print(myDate5, "Negative infinity");
    }
    catch (bad_year& e)
    {
        cout << e.what() << endl;
    }
    
    try
    {
        date myDate6(max_date_time); print(myDate6, "Max Date Time");
    }
    catch (bad_year& e)
    {
        cout << e.what() << endl;
    }
    
    return 0;
}
