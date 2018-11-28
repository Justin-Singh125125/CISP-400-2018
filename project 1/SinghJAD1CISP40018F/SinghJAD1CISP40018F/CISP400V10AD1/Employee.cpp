#include "pch.h"

#include "Employee.h"
#include <iostream>

using namespace std;

//sets first name if called
void Employee::setFirstName(string first) {
	firstName = first;
}

//sets last name if called
void Employee::setLastName(string last) {
	lastName = last;
}

void Employee::setMonthlySalary(int sal) {

	if (sal <= 0) {
		monthlySalary = 1000;
		cout << "XX Employee: " << firstName << " " << lastName << "'s inputted monthly salary is " << monthlySalary << endl;
		cout << "** The salary is set too " << monthlySalary << " **" << endl;
	}
	else
	{
		monthlySalary = sal;
	}
}

void Employee::increaseMonthlySalary(int percent) {
	cout << "--- Employee: " << firstName << " " << lastName << " has a salary adjusted of " << percent << "%" << endl;
	cout << "The original monthly salary is $" << monthlySalary << endl;

	//converts percent to a float 
	float decimal = static_cast<float>(percent) / 100;
	//this is going to store the percentage of the monthly salary
	int numberToAddToBalance = (monthlySalary* decimal);
	//add to original balance, if negative it accounts for that
	monthlySalary += numberToAddToBalance;
	cout << "The new monthly salary is $" << monthlySalary << endl;
	cout << endl;
}

string Employee::getFirstName()const {
	return firstName;
}

string Employee::getLastName()const {
	return lastName;
}

int Employee::getMonthlySalary()const {
	return monthlySalary;
}