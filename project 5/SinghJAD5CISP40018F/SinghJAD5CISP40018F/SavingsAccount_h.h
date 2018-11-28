//Justin Singh
//W1646765
#include "pch.h"
#ifndef SAVINGS_ACCOUNT_H
#define SAVINGS_ACCOUNT_H

//include the base class
#include "Account.h"
#include "Date.h"

//savings account is inheriting from the account class 
class SavingsAccount :public Account {
private:
	double interestRate;
public:
	SavingsAccount(double, double, string, string, const  Date&, const Date&);
	double calculateInterest();
	void addInterest();
	virtual void print()override;
	virtual void setInterestRate(double)override;
};
#endif // !SAVINGS_ACCOUNT_H
