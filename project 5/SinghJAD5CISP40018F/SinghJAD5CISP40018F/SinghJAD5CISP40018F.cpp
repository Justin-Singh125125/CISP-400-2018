//Justin Singh
//W1646765
#include "pch.h"
#include <iostream>
#include "Account.h"
#include "Date.h"
#include "checkingAccount.h"
#include "SavingsAccount_h.h"
#include <array>
#include <string>
#include <typeinfo>

using namespace std;

int main()
{
	//create a pointer array that can point to account objects, I have it set to null for now
	array<Account*, 10>accountPtr;

	//create savings and checking objects

	SavingsAccount savingsOne(25.0, .03, "Susan", "Baker", Date(1, 1, 2015), Date(2, 19, 2016));
	SavingsAccount savingsTwo(100, .04, "Chao", "Zulueta", Date(5, 31, 2016), Date(2, 14, 2017));

	CheckingAccount checkingOne(80.0, 1.0, "Robert", "Jones", Date(2, 29, 2017), Date(3, 19, 2017));
	CheckingAccount checkingTwo(250.0, 2.0, "Kenneth", "Ramirez", Date(6, 6, 2016), Date(1, 12, 2017));

	SavingsAccount savingsThree(125, .02, "Vue", "Thomas", Date(11, 30, 2016), Date(2, 24, 2017));

	CheckingAccount checkingThree(180.0, 3.0, "Angela", "Wilma", Date(2, 27, 2017), Date(3, 19, 2017));

	SavingsAccount savingsFour(600, .04, "Romeo", "Turner", Date(11, 19, 2016), Date(1, 19, 2017));
	SavingsAccount savingsFive(95, .02, "Oscar ", "Udonkanga", Date(10, 10, 2016), Date(2, 6, 2017));

	CheckingAccount checkingFour(255.0, 3.0, "Jimmy ", "Untalasco", Date(7, 32, 2016), Date(7, 32, 2016));
	CheckingAccount checkingFive(80.0, 1.0, "Terrence", "Trocino", Date(11, 16, 2016), Date(2, 4, 2017));

	//fill the array
	accountPtr[0] = &savingsOne;
	accountPtr[1] = &savingsTwo;
	accountPtr[2] = &checkingOne;
	accountPtr[3] = &checkingTwo;
	accountPtr[4] = &savingsThree;
	accountPtr[5] = &checkingThree;
	accountPtr[6] = &savingsFour;
	accountPtr[7] = &savingsFive;
	accountPtr[8] = &checkingFour;
	accountPtr[9] = &checkingFive;

	//I used virtual functions and overriding to allow 
	//derived class functions to be invoked by base class pointer
	cout << "\n\n***Initial Accounts information***\n\n";
	for (int i = 0; i < 10;i++) {
		accountPtr[i]->print();
	}

	cout << "\nOn 3/25/2017 accounts adjusted based on the following schedule:\n";
	accountPtr[0]->update("1. Susan Baker had a $40 debit.");
	accountPtr[1]->update("2. Chao Zulueta had a $30 credit.");
	accountPtr[2]->update("3. Robert Jones had a $40 debit.");
	accountPtr[3]->update("4. Kenneth Ramirez had a $50 credit.");
	accountPtr[4]->update("5. Vue Thomas had an accrued interest for a period.");
	accountPtr[5]->update("6. Angela Wilma had a transaction fee charged.");
	accountPtr[6]->update("7. Romeo Turner had an accrued interest for a period.");
	accountPtr[7]->update("8. Oscar Udonkanga had a $60 debit.");
	accountPtr[8]->update("9. Jimmy  Untalasco had a transaction fee charged.");
	accountPtr[9]->update("10. Trocino Terrence had a $100 debit.");

	savingsOne.debit(40);
	savingsOne.updateDate(3, 25, 2017);
	//since transaction went through, charge fee
	checkingOne.debit(40);
	checkingOne.chargeFee();
	checkingOne.updateDate(3, 25, 2017);

	savingsTwo.credit(30);
	savingsTwo.updateDate(3, 25, 2017);

	checkingTwo.credit(50);
	checkingTwo.updateDate(3, 25, 2017);

	savingsThree.addInterest();
	savingsThree.updateDate(3, 25, 2017);

	checkingThree.chargeFee();
	checkingThree.updateDate(3, 25, 2017);

	savingsFour.addInterest();
	savingsFour.updateDate(3, 25, 2017);

	checkingFour.chargeFee();
	checkingFour.updateDate(3, 25, 2017);

	savingsFive.debit(60);
	savingsFive.updateDate(3, 25, 2017);

	checkingFive.debit(100);
	checkingFive.updateDate(3, 25, 2017);

	cout << "\n\n***After the 3/25/2017 update, the Accounts information***\n\n";
	for (int i = 0; i < 10;i++) {
		accountPtr[i]->print();
	}

	cout << "\n\nOn 4/8/2017 all the saving used the same interest rate(0.05)\nand all the checking used the same transaction fee($5).\n\n";


	cout << "\n\n***After the 4/8/2017 update, the Accounts information***\n\n";

	//this whole process uses virtual functions and overriding to let the compiler decide which function to choose for the right class
	accountPtr[0]->setInterestRate(0.05);
	accountPtr[0]->updateDate(4, 8, 2017);

	accountPtr[1]->setInterestRate(0.05);
	accountPtr[1]->updateDate(4, 8, 2017);


	accountPtr[2]->setTransactionFee(5);
	accountPtr[2]->updateDate(4, 8, 2017);


	accountPtr[3]->setInterestRate(0.05);
	accountPtr[3]->updateDate(4, 8, 2017);


	accountPtr[4]->setInterestRate(0.05);
	accountPtr[4]->updateDate(4, 8, 2017);

	accountPtr[5]->setTransactionFee(5);
	accountPtr[5]->updateDate(4, 8, 2017);

	accountPtr[6]->setInterestRate(0.05);
	accountPtr[6]->updateDate(4, 8, 2017);

	accountPtr[7]->setInterestRate(0.05);
	accountPtr[7]->updateDate(4, 8, 2017);

	accountPtr[8]->setTransactionFee(5);
	accountPtr[8]->updateDate(4, 8, 2017);

	accountPtr[9]->setTransactionFee(5);
	accountPtr[9]->updateDate(4, 8, 2017);

	for (int i = 0; i < 10; i++) {
		accountPtr[i]->print();
	}




	system("PAUSE");
	return 0;
}

