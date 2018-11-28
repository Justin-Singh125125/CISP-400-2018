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

	Complex operator*(const Complex &) const; // multiplication

	Complex operator/(const Complex &) const; // division

	bool operator==(const Complex &); // equals

	bool operator!=(const Complex &); // not equals

	void operator=(const Complex &); // assignment

	void print() const; // output

	friend ostream& operator<<(ostream &, Complex &);

	friend istream& operator>>(istream &, Complex &);

private:

	double real; // real part

	double imaginary; // imaginary part

}; // end class Complex
#endif