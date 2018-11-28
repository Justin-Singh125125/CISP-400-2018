#ifndef DATE_H
#define  DATE_H


#include <iostream>
using namespace std;
class Date
{
private:
	int month;
	int day;
	int year;
public:

	Date(int, int, int);
	friend istream &operator>>(istream &, Date &);
	friend ostream &operator<<(ostream &, Date &);
	bool operator==(Date);
};
#endif // !DATE#pragma once
