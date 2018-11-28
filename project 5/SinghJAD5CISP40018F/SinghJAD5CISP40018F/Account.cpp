//Justin Singh
//W1646765
#include "pch.h"
#include "Account.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;


//a constructor
Account::Account(double balance, string first, string last, const Date &start, const  Date &update) :
	accountBalance{ balance }, firstName{ first }, lastName{ last }, startDate{ start }, updatedDate{ update }
{

	if (balance <= 0.0) {
		accountBalance = 0.0;
		cout << "ERROR: Initial balance was invalid, default balance was set to 0.0";
	}
}

//add to current balance
void Account::credit(double add) {
	//if the parameter passed in is above 0.0, increase account balance
	if (add > 0.0) {

		accountBalance += add;
	}
}
//subtract from current balance
void Account::debit(double subtract) {

	//create a temp variable that will check if account balance goes beyond negative
	double temp = accountBalance;
	temp -= subtract;

	if (temp < 0.0) {
		cout << "\n" << getFirstName() << " " << getLastName() << endl;
		cout << "Balance is $" << getBalance() << " and debit amount is $" << subtract << endl;
		cout << "Debit amount exceeded account balance. The request is returned.\n\n";
	}
	else {

		accountBalance -= subtract;
		//we now need to update the date for account update
	}
}
//prints the current data
void Account::print() {
	cout << firstName << " " << lastName << "\n";
	cout << "A/C Open Date: ";
	startDate.print();
	cout << "\nA/C Update Date: ";
	updatedDate.print();
	cout << "\nA/C Balance: " << fixed << setprecision(2) << accountBalance << "\n";
}

//gives the current account balance
double Account::getBalance()const {
	return accountBalance;
}

string Account::getFirstName()const {
	return firstName;
}
string Account::getLastName()const {
	return lastName;
}
void Account::update(string update) {
	cout << update << endl;
}
void Account::updateDate(int d, int m, int y) {
	updatedDate.setDate(m, d, y);
}
void Account::setInterestRate(double) {

}
void Account::setTransactionFee(double) {

}