#include "pch.h"

class Decrypt {
private:
	//an array to hold the decrypted digits
	int digits[8];

public:

	//takes in an integer
	Decrypt(int);
	//takes in an array int
	Decrypt(int[]);
	//last four digits
	void displayOriginalData();
	void storeData(int);
	void displayDecryptedData();
	int getDecryptedData()const;
};