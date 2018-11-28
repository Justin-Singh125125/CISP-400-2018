#include"pch.h"

#include "Decrypt.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

Decrypt::Decrypt(int number) {
	cout << "*D* The Decrypt constructor is called\n";
	cout << "    and the passed in number is " << number << ".**" << endl << endl;
	if (number <= 0) {
		cout << "XXXXX The inputed number is less than or equal to 0.\n";
		cout << "      The number is reset to 1234. XXXXX\n\n";
		//hardcode because these will never change
		digits[4] = 1;
		digits[5] = 2;
		digits[6] = 3;
		digits[7] = 4;
		//seperation
		digits[0] = 6;
		digits[1] = 7;
		digits[2] = 4;
		digits[3] = 5;
		//call the functions
		displayOriginalData();
		displayDecryptedData();
	}
	else
	{
		storeData(number);
		displayOriginalData();
		displayDecryptedData();
	}
}
Decrypt::Decrypt(int numbers[]) {

	//we are storing the first four numbers instead here
	ostringstream convertToString;
	for (int i = 0; i < 4; i++) {
		convertToString << numbers[i];
	}
	string str(convertToString.str());
	//convert string to an integer
	int num = stoi(str);
	cout << "*D* The decrypt array constructor is called\n";
	cout << "    and the passed in number is ";
	for (int i = 0; i < 8; i++) {
		cout << numbers[i];
	}
	cout << ".**";
	cout << endl << endl;
	if (num <= 0) {
		cout << "XXXXX The inputed number is less than or equal to 0.\n";
		cout << "    The number is reset to 1234. XXXXX\n\n";
		//hardcode the numbers into the last four digits
		digits[0] = 6;
		digits[1] = 7;
		digits[2] = 4;
		digits[3] = 5;
		//hardcode the encrypted numbers because this will always be the same
		digits[4] = 1;
		digits[5] = 2;
		digits[6] = 3;
		digits[7] = 4;
		//call the function that is going to display the original data
		displayOriginalData();
		displayDecryptedData();
	}
	else
	{
		storeData(num);
		displayOriginalData();
		displayDecryptedData();
	}

}
void Decrypt::displayDecryptedData() {
	cout << "     The decrypted data is ";
	for (int i = 0; i < 4; i++) {
		cout << digits[i] << " ";
	}
	cout << "." << endl << endl;
}

void Decrypt::displayOriginalData() {
	cout << "     The original data was ";
	for (int i = 4; i < 8; i++) {
		cout << digits[i] << " ";
	}
	cout << "." << endl;
}
void Decrypt::storeData(int number) {

	//an array that will hold the 4 digits
	int changeDigits[4];
	int x = 0;
	//this for loop will store the original digits in the last four elements
	//we write the numbers in reverse so we can display the digits in the correct order
	for (int i = 7; i >= 4; i--) {
		//we take the remainder of the number divided by 10
		digits[i] = number % 10;
		//while we are running through each element, we are storing the number there
		changeDigits[x] = digits[i];
		changeDigits[x] = (changeDigits[x] + 10) - 7;
		if (changeDigits[x] >= 10) {
			changeDigits[x] = (changeDigits[x] % 10);
		}
		//we then divde the number by 10 so we can get the next to last number and so on
		number /= 10;
		x++;
	}
	//swap
	int temp = 0;
	temp = changeDigits[0];
	changeDigits[0] = changeDigits[2];
	changeDigits[2] = temp;
	temp = changeDigits[1];
	changeDigits[1] = changeDigits[3];
	changeDigits[3] = temp;
	//this for loop will store the original digits
	//we write the numbers in reverse so we can display the digits in the correct order
	int t = 0;
	for (int i = 3; i >= 0; i--) {
		//we take the remainder of the number divided by 10
		digits[t] = changeDigits[i];
		t++;
	}
}
int Decrypt::getDecryptedData()const {
	int encryptedNumber = 0;
	//convert number to a string 
	ostringstream convertToString;
	for (int i = 0; i < 4; i++) {
		convertToString << digits[i];
	}
	string str(convertToString.str());
	//convert string to an integer
	encryptedNumber = stoi(str);
	return encryptedNumber;
}