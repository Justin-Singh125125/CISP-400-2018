#include "Complex.h"
using namespace std;

Complex::Complex(double r, double i) {
	real = r;
	imaginary = i;
}
istream &operator>>(istream &input, Complex &C)
{
	input >> C.real >> C.imaginary;
	return input;
}
ostream &operator << (ostream& output, Complex &C) {
	// a trick to get the - sign to show up
	if (C.imaginary < 0) {
		C.imaginary *= -1;
		output << C.real << " - " << C.imaginary << "i";
		return output;
	}

	output << C.real << " + " << C.imaginary << "i";
	return output;
}
bool Complex::operator==(Complex C1) {
	{
		return ((C1.real == real) && (C1.imaginary == imaginary));
	}
}

