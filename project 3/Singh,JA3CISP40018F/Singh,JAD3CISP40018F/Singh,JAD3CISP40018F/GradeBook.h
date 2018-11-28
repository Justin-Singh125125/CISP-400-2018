//Justin Singh
//w1646765


//  GradeBook.h
// GradeBook class definition that counts letter grades.
// Member functions are defined in GradeBook.cpp
#include "pch.h"
#include <array>
#include <string> // program uses C++ standard string class
using namespace std;
// GradeBook class definition
class GradeBook
{
public:
	explicit GradeBook(std::string); // initialize course name
	void setCourseName(std::string); // set the course name
	std::string getCourseName() const; // retrieve the course name
	void displayMessage() const; // display a welcome message
	void inputGrades(); // input arbitrary number of grades from user
	void displayGradeReport();  // display report based on user input
	void displayInputs() const;
	void displayCorrectMessage()const;
	double calculateGrade();
	void initializeData();
	~GradeBook();

private:
	std::string courseName; // course name for this GradeBook
	//i am deleting the grade count variables and replacing them with the 6 element array
	array<int, 6>countGrades;
	//character array which will hold every character entered
	array<char, 100>letterGrades;
}; // end class GradeBook  