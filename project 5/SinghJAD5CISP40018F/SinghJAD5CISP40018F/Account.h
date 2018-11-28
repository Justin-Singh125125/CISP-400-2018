//Justin Singh
//W1646765
#include "pch.h"
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include "Date.h"
using namespace std;

class Account {
protected:
	//holds the account balance
	double accountBalance;
	//hold first and last name
	string firstName;
	string lastName;

	//create date objects as composition
	Date startDate;
	Date updatedDate;
public:
	// a constructor
	Account(double, string, string, const Date&, const Date&);
	//add to current balance
	void credit(double);
	//subtract from current balance
	void debit(double);
	//prints the current information
	virtual void print();

	//stores in updated text
	void update(string);

	//get balance
	double getBalance()const;
	string getFirstName()const;
	string getLastName()const;

	void updateDate(int, int, int);

	virtual void setTransactionFee(double);
	virtual void setInterestRate(double);
};
#endif // !ACCOUNT_H
