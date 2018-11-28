#include "pch.h"
//Justin Singh
//W1646765
#include "Account.h"
#include "Date.h"

#ifndef CHECKING_ACCOUNT_H
#define CHECKING_ACCOUNT_H


//checking account inherits from base class account
class CheckingAccount :public Account {
private:
	double fee;
public:
	CheckingAccount(double, double, string, string, const Date&, const Date&);
	virtual void setTransactionFee(double)override;
	virtual void print()override;
	void chargeFee();
};
#endif // !CHECKING_ACCOUNT_H
