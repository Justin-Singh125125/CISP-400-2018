#include "Complex.h" // Complex class definition

#include <math.h>

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

Complex Complex:: operator*(const Complex &operand2) const

{

	return Complex((real * operand2.real) - (imaginary * operand2.imaginary),

		(imaginary * operand2.imaginary) + (real * operand2.real));

}

Complex Complex:: operator/(const Complex &operand2) const

{

	if (pow(operand2.real, 2) == 0 && pow(operand2.imaginary, 2) == 0)

	{

		cout << "\n Division by zero" << endl;

		return Complex(0, 0);

	}

	else

		return Complex((real*operand2.real + imaginary * operand2.imaginary) / (pow(operand2.real, 2) + pow(operand2.imaginary, 2))

			, ((operand2.real*imaginary - real * operand2.imaginary) / (pow(operand2.real, 2) + pow(operand2.imaginary, 2))));

}

bool Complex::operator==(const Complex &operand2)

{

	if ((real == operand2.real) && (imaginary == operand2.imaginary))

		return true;

	else

		return false;

}

bool Complex:: operator!=(const Complex &operand2)

{

	if ((real == operand2.real) && (imaginary == operand2.imaginary))

		return false;

	else

		return true;

}

void Complex:: operator=(const Complex &operand2)

{

	real = operand2.real;

	imaginary = operand2.imaginary;

}

// display a Complex object in the form: (a, b)

void Complex::print() const

{

	cout << '(' << real << ", " << imaginary << ')';

} // end function print

std::ostream& operator<<(std::ostream &out, Complex &operand)

{

	out << '(' << operand.real << ", " << operand.imaginary << ')';

	return out;

}

std::istream& operator>>(std::istream &in, Complex &operand) // input in the form of (a,b)

{

	char delim;

	in >> delim >> operand.real >> delim >> operand.imaginary >> delim;

	return in;

}