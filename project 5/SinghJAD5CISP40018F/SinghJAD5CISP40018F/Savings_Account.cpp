//Justin Singh
//W1646765
#include "pch.h"
#include "SavingsAccount_h.h"
#include <iostream>
#include "Date.h"
using namespace std;

//this constructor initalizes all data while sending it over to the base class also
SavingsAccount::SavingsAccount(double balance, double interest, string first, string last, const Date &start, const Date& update) :Account(balance, first, last, start, update) {
	setInterestRate(interest);
}
double SavingsAccount::calculateInterest() {
	//returns the balance by current interest rate
	return (interestRate * getBalance());
}

void SavingsAccount::addInterest() {
	//calculates the interest to add 
	double holdCalcInterest = calculateInterest();
	double temp = getBalance();
	//figure out how to update the date info

	//display info 
	cout << "\n\n" << getFirstName() << " " << getLastName() << endl;
	cout << "Balance: " << getBalance() << "\tInterest rate " << interestRate << endl;
	cout << "Interest $" << holdCalcInterest << " added into balance.\n";

	//update the balance
	temp += holdCalcInterest;
	cout << "The new balance is $" << temp << endl;
	accountBalance = temp;

}
void SavingsAccount::print() {
	cout << "Savings Account:\n";
	//this is called from base class
	Account::print();
	cout << "Interest Rate: " << interestRate << "\n\n";
}
void SavingsAccount::setInterestRate(double interest) {
	if (interest < 0.0) {
		interestRate = 0.0;
		cout << "Interest Rate: $" << interestRate << endl;
		//again from base class
		print();
	}
	else {
		interestRate = interest;
	}
}