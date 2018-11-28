#include "pch.h"
#include "string"
using namespace std;

class Encrypt {


private:
	//an array that will hold 8 integer elements
	int digits[8];
public:
	//a constructor for regular numbers
	Encrypt(int);
	//a constructor to take in arrays
	Encrypt(int []);
	//displays the original number entered, displays the first four elements of digits
	void displayOriginalData();
	//stores the last four digits of the passed in integer to the first 4 elements of digits
	void storeData(int);
	//displays the last four elements in digits
	void displayEncryptedData();
	//returns the 4 digit encrypted integer
	int getEncryptedData()const;
	


};