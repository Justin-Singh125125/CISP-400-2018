//Justin Singh
//W1646765
#include "pch.h"
#include "checkingAccount.h"
#include <iostream>
#include <iomanip>
using namespace std;

CheckingAccount::CheckingAccount(double balance, double fees, string first, string last, const Date &start, const Date &update) :Account(balance, first, last, start, update) {
	setTransactionFee(fees);
}
void CheckingAccount::setTransactionFee(double fees) {
	if (fees < 0.0) {
		fee = 0.0;
		print();
		cout << "Transaction Fee: $" << fee;
	}
	else {
		fee = fees;
	}
}
void CheckingAccount::print() {
	cout << "Checking Account:\n";
	//base class print
	Account::print();
	cout << "Transaction Fee: $" << fee << "\n\n";
}
void CheckingAccount::chargeFee() {
	accountBalance -= fee;
	cout << "\n" << getFirstName() << " " << getLastName() << endl;
	cout << "$ " << fee << " transaction fee charged.";
}

