//Justin Singh
//w1646765
// Complex.cpp
// Complex class member-function definitions.
#include <iostream>
#include "Complex.h" // Complex class definition
#include <math.h>
using namespace std;

// Constructor
Complex::Complex(double realPart, double imaginaryPart)
	: real(realPart),
	imaginary(imaginaryPart)
{
	// empty body
} // end Complex constructor

// addition operator
Complex Complex::operator+(const Complex &operand2) const
{
	return Complex(real + operand2.real,
		imaginary + operand2.imaginary);
} // end function operator+

// subtraction operator
Complex Complex::operator-(const Complex &operand2) const
{
	return Complex(real - operand2.real,
		imaginary - operand2.imaginary);
} // end function operator-


istream & operator >>(istream &input, Complex & operand) {
	//create a variable that will store the excess material such as the parenthesis
	char temp;
	input >> temp >> operand.real >> temp >> operand.imaginary >> temp;
	return input;
}

ostream & operator << (ostream & output, Complex & operand) {
	output << "( " << operand.real << ", " << operand.imaginary << ")";
	return output;
}
Complex Complex::operator*(const Complex &operand)const {

	return Complex(((real * operand.real) - (imaginary * operand.imaginary)), ((real* operand.imaginary) + (imaginary* operand.real)));
}
void Complex::operator=(const Complex & operand) {
	real = operand.real;
	imaginary = operand.imaginary;
}
Complex Complex::operator/(const Complex & operand)const {
	if (pow(operand.real, 2) == 0 && pow(operand.imaginary, 2) == 0)
	{
		return Complex(0, 0);
	}
	return Complex((real*operand.real + imaginary * operand.imaginary) / (pow(operand.real, 2) + pow(operand.imaginary, 2))
		, ((operand.real*imaginary - real * operand.imaginary) / (pow(operand.real, 2) + pow(operand.imaginary, 2))));
}
bool Complex::operator!=(const Complex & operand) {
	if ((real == operand.real) && (imaginary == operand.imaginary)) {
		return false;
	}
	return true;
}
bool Complex::operator==(const Complex & operand) {
	if ((real == operand.real) && (imaginary == operand.imaginary)) {
		return true;
	}
	return false;
}
