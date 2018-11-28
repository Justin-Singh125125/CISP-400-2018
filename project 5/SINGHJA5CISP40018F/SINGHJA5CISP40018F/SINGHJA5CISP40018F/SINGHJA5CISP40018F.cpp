//Justin Singh
//w1646765
#include <iostream>
#include "Complex.h"
using namespace std;

int main()
{
	Complex x;
	Complex y(4.3, 8.2);
	Complex z(3.3, 1.1);
	Complex m(0, 0.1);
	//this is what the user is going to create
	Complex k;
	Complex l;
	//user built
	cout << "Enter a complex number in the form: (a, b) for Complex object k.";
	cout << "\n(Performing >> operator overloading.)\n?";
	cin >> k;
	cout << "The existing Complex objects are: \n(Performing << operator overloading.)\n\n";
	cout << "x: " << x;
	cout << "\ny: " << y;
	cout << "\nz: " << z;
	cout << "\nk: " << k;
	cout << "\nl: " << l;
	cout << "\nm: " << m;

	cout << "\n\nPerforming +, = and << operators overloading.\n";
	x = y + z;
	cout << "x = y + z:" << endl;
	cout << x << " = " << y << " + " << z;

	cout << "\n\nPerforming -, = and << operators overloading.\n";
	x = y - z;
	cout << "x = y - z:" << endl;
	cout << x << " = " << y << " - " << z;

	cout << "\n\nPerforming *, = and << operators overloading.\n";
	x = y * z;
	cout << "x = y * z:" << endl;
	cout << x << " = " << y << " * " << z;

	cout << "\n\nPerforming /, = and << operators overloading.\n";
	x = y / z;
	cout << "x = y / z:" << endl;
	cout << x << " = " << y << " / " << z;

	cout << "\n\nPerforming /, = and << operators overloading with divisor is (0, 0).\n";
	x = y / l;
	cout << "x = y / l:" << endl;
	cout << "infinite" << " = " << y << " / " << l;

	cout << "\n\nPerforming /, = and << operators overloading with divisor is (0, 0).\n";
	x = y / m;
	cout << "x = y / m:" << endl;
	cout << x << " = " << y << " / " << m;

	cout << "\n\nPerforming != and << operators overloading.\n";
	cout << "check x != k\n";
	if (x != k) {
		cout << x << " != " << k << endl;
	}

	cout << "\n\nPerforming =, == and << operators overloading.\ncheck k = x\n";
	x = k;
	if (x == k) {
		cout << x << " == " << k << endl;
	}
	system("PAUSE");
} // end main
