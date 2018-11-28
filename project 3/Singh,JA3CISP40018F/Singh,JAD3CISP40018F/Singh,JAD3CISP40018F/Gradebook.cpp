//Justin Singh
//w1646765



// GradeBook.cpp
// Member-function definitions for class GradeBook that
// uses a switch statement to count A, B, C, D and F grades.
#include "pch.h"
#include <iostream>
#include "GradeBook.h" // include definition of class GradeBook
#include <iomanip>
#include <array>
using namespace std;

// constructor initializes courseName with string supplied as argument;
// initializes counter data members to 0
GradeBook::GradeBook(string name)
{
	cout << "The Grade Book Constructor is called\n";
	initializeData();
	setCourseName(name);
	displayMessage();
	cout << "The Grade Book, " << getCourseName() << ", contains\n";
	displayGradeReport();


	cout << "\n*****The end of Grade Book Constructor.*****\n\n\n";
} // end GradeBook constructor

// function to set the course name; limits name to 25 or fewer characters
void GradeBook::setCourseName(string name)
{
	if (name.size() <= 30) // if name has 25 or fewer characters
		courseName = name; // store the course name in the object
	else // if name is longer than 25 characters
	{ // set courseName to first 25 characters of parameter name
		courseName = name.substr(0, 30); // select first 25 characters
		cerr << "\tName \"" << name << "\"\n\texceeds maximum length (30).\n\n"
			<< "\tLimiting courseName to first 30 characters." << endl;
	} // end if...else
} // end function setCourseName

// function to retrieve the course name
string GradeBook::getCourseName() const
{
	return courseName;
} // end function getCourseName

// display a welcome message to the GradeBook user
void GradeBook::displayMessage() const
{
	// this statement calls getCourseName to get the 
	// name of the course this GradeBook represents
	cout << "\n\tWelcome to the grade book for\n\t" << getCourseName() << "!\n"
		<< endl;
} // end function displayMessage

// input arbitrary number of grades from user; update grade counter
void GradeBook::inputGrades()
{
	int grade; // grade entered by user
	int count = 0;

	cout << "\tEnter the letter grades." << endl
		<< "\tEnter the EOF character to end input." << endl;
	cout << " \t(Use Ctl + D, or Ctl + Z)" << endl;

	// loop until user types end-of-file key sequence
	while ((grade = cin.get()) != EOF && count < letterGrades.size())
	{



		// determine which grade was entered
		switch (grade) // switch statement nested in while
		{

		case 'A': // grade was uppercase A
		case 'a': // or lowercase a
			++countGrades[0]; // increment aCount
			//stores uppercase version into leter grades
		//I use char to convert number to char value
			//I repeat this for the rest of the elements
			letterGrades[count] = char(toupper(grade));
			count++;
			displayCorrectMessage();
			break; // necessary to exit switch

		case 'B': // grade was uppercase B
		case 'b': // or lowercase b
			++countGrades[1]; // increment bCount  
			letterGrades[count] = char(toupper(grade));
			count++;
			displayCorrectMessage();
			break; // exit switch

		case 'C': // grade was uppercase C
		case 'c': // or lowercase c
			++countGrades[2]; // increment cCount 
			letterGrades[count] = char(toupper(grade));
			count++;
			displayCorrectMessage();
			break; // exit switch

		case 'D': // grade was uppercase D
		case 'd': // or lowercase d
			++countGrades[3]; // increment dCount 
			letterGrades[count] = char(toupper(grade));
			count++;
			displayCorrectMessage();
			break; // exit switch

		case 'F': // grade was uppercase F
		case 'f': // or lowercase f
			++countGrades[4]; // increment fCount  
			letterGrades[count] = char(toupper(grade));
			count++;
			displayCorrectMessage();
			break; // exit switch

		case '\n': // ignore newlines,  
		case '\t': // tabs, 
		case ' ': // and spaces in input
			break; // exit switch

		default: // catch all other characters
			cout << "\tXXXX An incorrect letter grade entered.   XXXX\n\t"
				<< "\"" << char(grade) << "\"" << " is not a proper letter grade" << endl << endl;
			letterGrades[count] = char(toupper(grade));
			count++;
			//increments number of errors
			++countGrades[5];
			displayCorrectMessage();
			break; // optional; will exit switch anyway
		} // end switch

	} // end while
} // end function inputGrades

// display a report based on the grades entered by user
void GradeBook::displayGradeReport()
{

	int totalDataEntered = 0;
	int totalDataRecieved = 0;
	double average = calculateGrade();
	//two in one for loop
	//gets total data entered and total data received
	for (int i = 0; i < countGrades.size();i++) {
		totalDataEntered += countGrades[i];
		if (i < (countGrades.size() - 1)) {
			totalDataRecieved += countGrades[i];
		}
	}

	// output summary of results

	cout << "\n\nThe total number of data entered is " << totalDataEntered << endl;
	cout << "The total number of students receive grades is " << totalDataRecieved << endl;
	cout << "Number of students who received each letter grade:"
		<< "\nA: \t" << countGrades[0] // display number of A grades
		<< "\nB: \t" << countGrades[1]  // display number of B grades
		<< "\nC: \t" << countGrades[2]  // display number of C grades 
		<< "\nD: \t" << countGrades[3]  // display number of D grades
		<< "\nF: \t" << countGrades[4]  // display number of F grades
		<< "\nError: \t" << countGrades[5]
		<< endl;

	cout << "\nThe class average is: " << fixed << setprecision(1) << average << endl;
} // end function displayGradeReport

void GradeBook::displayInputs()const {
	//this will display the format in the 4 collum way
	bool isFirstIndex = true;
	bool isFirstRow = true;
	int count = 1;
	cout << "\nThe data entered is listed at the following:\n";
	for (int i = 0; i < letterGrades.size();i++) {

		if (letterGrades[i] == '\0') {
			break;
		}
		cout << "[" << i << "] --> " << letterGrades[i] << "\t";

		if (count % 4 == 0) {
			cout << endl;
		}
		count++;
	}
}
void GradeBook::displayCorrectMessage()const {
	cout << "\tEnter the letter grades." << endl
		<< "\t-->	Or Enter the EOF character to end input." << endl;
	cout << "\t(Use Ctl + D, or Ctl + Z)" << endl << endl;
}

double GradeBook::calculateGrade() {
	double totalCredits = 0.0;
	double totalNumOfGrades = 0.0;
	for (int i = 0; i < (countGrades.size() - 1);i++) {
		if (i <= 0) {
			totalCredits += countGrades[i] * 4.0;
		}
		else if (i <= 1) {
			totalCredits += countGrades[i] * 3.0;
		}
		else if (i <= 2) {
			totalCredits += countGrades[i] * 2.0;
		}
		else if (i <= 3) {
			totalCredits += countGrades[i] * 1.0;
		}
		totalNumOfGrades += countGrades[i];

	}

	totalCredits /= totalNumOfGrades;
	//because we cant divide by zero, it will return garbage
	if (totalNumOfGrades == 0.0) {
		return 0;
	}
	else
	{
		return totalCredits;
	}


}
void GradeBook::initializeData() {
	for (int i = 0; i < countGrades.size(); i++) {
		countGrades[i] = 0;
	}
	courseName = "";
	for (int i = 0; i < letterGrades.size(); i++) {
		letterGrades[i] = '\0';
	}
}
GradeBook::~GradeBook() {
	cout << "\nDestructor is called\n";
}



