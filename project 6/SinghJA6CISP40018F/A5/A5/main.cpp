#include<iostream>
#include<string>
#include "Complex.h"
#include "Date.h"
using namespace std;

//allows us to pass in various data types
template<class type>
bool isEqualTo(type T1, type T2)
{
	//returns a boolean, true or false 
	return (T1 == T2);
}

int main()
{
	//initalizations for the complex class
	Complex C1(10, 5);
	Complex C2(10, 5);
	Complex C3(10, 5);
	Complex C4(10, 54);
	Complex C5(10, -5);
	Complex C6(10, 5);
	Complex C7(-10, -5);
	Complex C8(-10, -5);

	//initializations for the date class
	Date D1(2, 1, 2011);
	Date D2(2, 1, 2011);
	Date D3(2, 13, 2011);
	Date D4(2, 14, 2011);
	Date D5(1, 13, 2011);
	Date D6(2, 13, 2011);
	Date D7(1, 13, 2011);
	Date D8(1, 13, 2011);

	//integers
	cout << "*** Integers Tests *** " << endl;
	cout << "Integers: 1 and 1 are " << (isEqualTo(1, 1) ? "" : "NOT") << " equal Integers: " << endl;
	cout << "Integers: 2 and 4 are " << (isEqualTo(2, 4) ? "" : "NOT") << " equal Integers: " << endl;
	cout << "Integers: -1 and 1 are " << (isEqualTo(-1, 1) ? "" : "NOT") << " equal Integers: " << endl;
	cout << "Integers: -1 and -1 are " << (isEqualTo(-1, -1) ? "" : "NOT") << " equal Integers: " << endl;
	cout << endl;

	//characters
	cout << " *** Chars Tests *** " << endl;
	cout << "Characters: a and a are " << (isEqualTo('a', 'a') ? "" : "NOT") << " equal Characters: " << endl;
	cout << "Characters: a and c are " << (isEqualTo('a', 'c') ? "" : "NOT") << " equal Characters: " << endl;
	cout << "Characters: c and a are " << (isEqualTo('c', 'a') ? "" : "NOT") << " equal Characters: " << endl;
	cout << "Characters: c and c are " << (isEqualTo('c', 'c') ? "" : "NOT") << " equal Characters: " << endl;
	cout << endl;

	//doubles
	cout << " *** Double Tests *** " << endl;
	cout << "Doubles: 2.2 and 2.2 are " << (isEqualTo(2.2, 2.2) ? "" : "NOT") << " equal Doubles: " << endl;
	cout << "Doubles: 2.2 and 2.3 are " << (isEqualTo(2.2, 2.3) ? "" : "NOT") << " equal Doubles: " << endl;
	cout << "Doubles: -2.2 and 2.2 are " << (isEqualTo(-2.2, 2.2) ? "" : "NOT") << " equal Doubles: " << endl;
	cout << "Doubles: -2.2 and -2.2 are " << (isEqualTo(-2.2, -2.2) ? "" : "NOT") << " equal Doubles: " << endl;
	cout << endl;

	//Complex
	cout << "*** Complex Tests *** " << endl;
	cout << "Class objects: " << C1 << " and " << C2 << " are " << (isEqualTo(C1, C2) ? "" : "NOT") << " equal " << endl;
	cout << "Class objects: " << C3 << " and " << C4 << " are " << (isEqualTo(C3, C4) ? "" : "NOT") << " equal " << endl;
	cout << "Class objects: " << C5 << " and " << C6 << " are " << (isEqualTo(C5, C6) ? "" : "NOT") << " equal " << endl;
	cout << "Class objects: " << C7 << " and " << C8 << " are " << (isEqualTo(C7, C8) ? "" : "NOT") << " equal " << endl;
	cout << endl;
	
	//String
	cout << "*** string Tests *** " << endl;
	cout << "String objects: abcdefg and abcdefg are " << (isEqualTo("abcdefg", "abcdefg") ? "" : "NOT") << " equal " << endl;
	cout << "String objects: abcdefg and abcdefh are " << (isEqualTo("abcdefg", "abcdefh") ? "" : "NOT") << "equal " << endl;
	cout << "String objects: -abcdefg and abcdefg are " << (isEqualTo("-abcdefg", "abcdefg") ? "" : "NOT") << " equal " << endl;
	cout << "String objects: -abcdefg and -abcdefg are " << (isEqualTo("-abcdefg", "-abcdefg") ? "" : "NOT") << " equal " << endl;
	cout << endl;
	
	//Date
	cout << "*** Date Tests *** " << endl;
	cout << "Date objects: " << D1 << " and " << D2 << " are " << (isEqualTo(D1, D2) ? "" : "NOT") << " equal " << endl;
	cout << "Date objects: " << D3 << " and " << D4 << " are " << (isEqualTo(D3, D4) ? "" : "NOT") << " equal " << endl;
	cout << "Date objects: " << D5 << " and " << D6 << " are " << (isEqualTo(D5, D6) ? "" : "NOT") << " equal " << endl;
	cout << "Date objects: " << D7 << " and " << D8 << " are " << (isEqualTo(D7, D8) ? "" : "NOT") << " equal " << endl;

	system("pause");
	return 0;
}