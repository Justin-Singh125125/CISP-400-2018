#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <string>
using namespace std;


class Employee {


private:
	//holds first names
	string firstName;
	//holds last names
	string lastName;
	//holds monthly salary's
	int monthlySalary;


public:

	//when object is created, set all private variables to what is passed into the constructor
	Employee(string first, string last, int sal)
		//initalizer list
		:firstName{ first }, lastName{ last }
	{
		setMonthlySalary(sal);
	}
	//will set the first name if called
	void setFirstName(string);
	//will set the last name if called
	void setLastName(string);
	//will set the monthly salary if called
	void setMonthlySalary(int);
	//increases the salary
	void increaseMonthlySalary(int);

	//get functions

	//will return first name if called
	string getFirstName()const;
	//will return last name if called
	string getLastName()const;
	//will return monthly salary if called
	int getMonthlySalary()const;
};
#endif //EMPLOYEE_H_h