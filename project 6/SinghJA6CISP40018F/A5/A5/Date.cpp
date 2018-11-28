#include "Date.h"

#include <string>
using namespace std;


Date::Date(int m = 1, int d = 1, int y = 1)
{
	month = m;
	day = d;
	year = y;
}

ostream &operator<<(ostream &output, Date &D)
{
	//it was easier to create an array of all the months and then just access them
	string months[] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	
	//decrease month by one to access the right  indexed month
	output << months[D.month - 1] << " " << D.day << "," << " " << D.year;
	return output;
}
istream &operator>>(istream &input, Date &D)
{
	input >> D.month >> D.day >> D.year;
	return input;
}

bool Date::operator==(Date D1)
{
	//returns true or false, true if all values are conditions are true
	return ((D1.month == month) && (D1.day == day) && (D1.year == year));
}