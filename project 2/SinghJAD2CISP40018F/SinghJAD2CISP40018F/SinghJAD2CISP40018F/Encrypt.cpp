#include "pch.h"
#include "Encrypt.h"
#include <iostream>
#include <string>
//to convert string to int
#include <sstream> 

using namespace std;

//a construcot that takes in a number
Encrypt::Encrypt(int num) {
	cout << "*E* The Encrypt constructor is called\n";
	cout << "    and the passed in number is " << num << ".**" << endl << endl;
	//set the string variable equal to the num
	if (num <= 0) {
		cout << "  XXXXX The inputed number is less than or equal to 0.\n";
		cout << "        The number is reset to 9436. XXXXX\n\n";
		//hardcode the numbers into the last four digits
		digits[0] = 9;
		digits[1] = 4;
		digits[2] = 3;
		digits[3] = 6;
		//hardcode the encrypted numbers because this will always be the same
		digits[4] = 0;
		digits[5] = 3;
		digits[6] = 6;
		digits[7] = 1;
		//call the function that is going to display the original data
		displayOriginalData();
		displayEncryptedData();
		cout << endl;
	}
	else {
		//call the store data function to set everything
		storeData(num);
		displayOriginalData();
		displayEncryptedData();
		cout << endl;
	}
}
//a constructor that will take in arrays
Encrypt::Encrypt(int numbers[]) {
	ostringstream convertToString;
	for (int i = 0; i < 4; i++) {
		convertToString << numbers[i];
	}
	string str(convertToString.str());
	//convert string to an integer
	int num = stoi(str);
	cout << "*E* The Encrypt array constructor is called\n";
	cout << "    and the passed in number is ";
	for (int i = 0; i < 8; i++) {
		cout << numbers[i];
	}
	cout << ".**";
	cout << endl << endl;
	if (num <= 0) {
		cout << "XXXXX The inputed number is less than or equal to 0.\n";
		cout << "    The number is reset to 9436. XXXXX\n\n";
		//hardcode the numbers into the last four digits
		digits[0] = 9;
		digits[1] = 4;
		digits[2] = 3;
		digits[3] = 6;
		//hardcode the encrypted numbers because this will always be the same
		digits[4] = 0;
		digits[5] = 3;
		digits[6] = 6;
		digits[7] = 1;

		//call the function that is going to display the original data
		displayOriginalData();
		displayEncryptedData();
		cout << endl << endl;
	}
	else
	{
		storeData(num);
		displayOriginalData();
		displayEncryptedData();
	}

}
void Encrypt::displayEncryptedData() {
	cout << "     The encrypted data is ";
	for (int i = 4; i < 8; i++) {
		cout << digits[i] << " ";
	}
	cout << "." << endl << endl;
}
void Encrypt::displayOriginalData() {
	cout << "     The original data is ";
	for (int i = 0; i < 4; i++) {
		cout << digits[i] << " ";
	}
	cout << "." << endl;
}

void Encrypt::storeData(int number) {
	int changeDigits[4];
	//this for loop will store the original digits
	//we write the numbers in reverse so we can display the digits in the correct order
	for (int i = 3; i >= 0; i--) {
		//we take the remainder of the number divided by 10
		digits[i] = number % 10;
		//we are storing copy of the numbers in an array so we can change them for the encryption
		changeDigits[i] = digits[i];
		//change the encrypted digits
		changeDigits[i] = (changeDigits[i] + 7) % 10;
		if (changeDigits[i] >= 10) {
			changeDigits[i] = (changeDigits[i] % 10);
		}
		//we then divde the number by 10 so we can get the next to last number and so on
		number /= 10;
	}

	//swap digits
	int temp = 0;
	temp = changeDigits[0];
	changeDigits[0] = changeDigits[2];
	changeDigits[2] = temp;
	temp = changeDigits[1];
	changeDigits[1] = changeDigits[3];
	changeDigits[3] = temp;

	//now write to the last part of the digits array
	//we are going to use x to write the parts of the change digits array
	int x = 0;
	for (int i = 4; i < 8; i++) {
		digits[i] = changeDigits[x];
		x++;
	}
}
int Encrypt::getEncryptedData()const {
	int encryptedNumber = 0;
	ostringstream convertToString;
	for (int i = 4; i < 8; i++) {
		convertToString << digits[i];
	}
	string str(convertToString.str());
	//convert string to an integer
	encryptedNumber = stoi(str);
	return encryptedNumber;
}
