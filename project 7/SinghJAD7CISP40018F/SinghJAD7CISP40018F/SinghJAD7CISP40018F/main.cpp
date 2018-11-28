//Justin Singh
//w1646765

// Manipulating a linked list.
#include <iostream>
#include <string>
#include "List.h" // List class definition
#include <random> // contains C++11 random number generation features

using namespace std;

template<typename T>
void calcRandNums(List<T>& listObject) {
	random_device rd;
	mt19937 mt(rd());
	uniform_int_distribution<int> dist(0, 200);

	//this will fill the link list up with random numbers
	for (int i = 0; i < 20; ++i) {
		listObject.insertAtBack(dist(mt));
	}


}

// display program instructions to user
template<typename T>

void instructions(List<T> & listObject) {

	listObject.print();
	cout << endl << endl;
	cout << "Please select one from of the following selection or enter -1 to exit:\n"
		<< "  1. Insert an element to the list\n"
		<< "  2. Delete an element from the list\n"
		<< "  3. Repopulate the List information\n";
}

// function to test a List
template<typename T>
void testList(List<T>& listObject, const string& typeName) {



	int choice; // store user choice
	int index; // store input value
	int value;

	do { // perform user-selected actions
		instructions(listObject); // display instructions
		cout << "? ";
		cin >> choice;

		switch (choice) {
		case 1:

			cout << "Enter the index where you want the new value to appear:\n";
			cin >> index;
			cout << "Enter the value you want added at this location: ";
			cin >> value;
			listObject.insertAnywhere(index, value);

			break;
		case 2: // insert at end
			cout << "Enter an integer to delete ";
			cin >> value;
			listObject.removeAnywhere(value);

			break;
		case 3: // remove from beginning
			cout << "Repopulating the List information";
			calcRandNums(listObject);
			break;

		}
	} while (choice != -1);

	cout << "\n**********GOODBYE*************\n";
}

int main() {
	// test List of int values
	List<int> integerList;
	calcRandNums(integerList);

	testList(integerList, "integer");
	system("PAUSE");
}

