// V10A5.cpp
// Complex class test program.

#include <iostream>

#include "Complex.h"

using namespace std;

int main()

{

	Complex x, k, l;

	Complex y(4.3, 8.2);

	Complex z(3.3, 1.1);

	Complex m(0, 0.1);

	cin >> k;

	cout << "\nx: " << x << "\ny: " << y << "\nz: " << z << "\nk: " << k << "\nl: " << l << "\nm: " << m << '\n';

	x = y + z;

	cout << "\n\nx = y + z:" << endl << x << " = " << y << " + " << z << endl;

	x = y - z;

	cout << "\n\nx = y - z:" << endl << x << " = " << y << " - " << z << endl;

	x = y * z;

	cout << "\n\nx = y * z:" << endl << x << " = " << y << " * " << z << endl;

	x = y / z;

	cout << "\n\nx = y / z:" << endl << x << " = " << y << " / " << z << endl;

	x = y / l;

	cout << "\n\nx = y / l:" << endl << x << " = " << y << " / " << l << endl;

	x = y / m;

	cout << "\n\nx = y / m:" << endl << x << " = " << y << " / " << m << endl;

	if (x != k)

		cout << x << " != " << k << '\n';

	x = k;

	if (x == k)

		cout << x << " == " << k << '\n';
	system("PAUSE");
	return 0;


} // end main