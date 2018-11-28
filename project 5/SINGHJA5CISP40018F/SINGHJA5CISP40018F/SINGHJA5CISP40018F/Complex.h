//Justin Singh
//w1646765
#ifndef COMPLEX_H

#define COMPLEX_H

#include <iostream>

using namespace std;

class Complex

{

public:
	explicit Complex(double = 0.0, double = 0.0); // constructor
	Complex operator+(const Complex &) const; // addition
	Complex operator-(const Complex &) const; // subtraction
	Complex operator*(const Complex &)const;
	Complex operator/(const Complex &)const;
	void operator=(const Complex &);
	friend ostream & operator <<(ostream&, Complex &);
	friend istream& operator>>(istream &, Complex &);
	bool operator!=(const Complex &);
	bool operator ==(const Complex &);
private:
	double real; // real part
	double imaginary; // imaginary part
}; // end class Complex
#endif