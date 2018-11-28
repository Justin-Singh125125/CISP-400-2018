#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class Complex
{
private:
	double real;
	double imaginary;
public:
	Complex(double, double);
	friend istream &operator>>(istream &, Complex &);
	friend ostream &operator << (ostream &, Complex &);
	bool operator==(Complex);
};
#endif // !COMPLEX