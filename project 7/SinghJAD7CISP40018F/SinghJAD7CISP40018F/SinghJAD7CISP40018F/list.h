//Justin Singh
//w1646765


// List class-template definition.
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h" // ListNode class definition
using namespace std;

template<typename NODETYPE>
class List {
public:
	// destructor
	~List() {
		if (!isEmpty()) { // List is not empty
			std::cout << "Destroying nodes ...\n";

			ListNode<NODETYPE>* currentPtr{ firstPtr };
			ListNode<NODETYPE>* tempPtr{ nullptr };

			while (currentPtr != nullptr) { // delete remaining nodes
				tempPtr = currentPtr;
				std::cout << tempPtr->data << '\n';
				currentPtr = currentPtr->nextPtr;
				delete tempPtr;
			}
		}

		std::cout << "All nodes destroyed\n\n";
	}
	void insertAnywhere(const int & index, const int & value) {

		ListNode<NODETYPE>* newPtr{ getNewNode(value) };
		ListNode<NODETYPE>* linker{ firstPtr };

		newPtr->data = value;
		if (index == 0) {
			newPtr->nextPtr = firstPtr; // point new node to old 1st node
			firstPtr = newPtr;
		}
		else {
			for (int i = 0; i < index;i++) {
				linker = linker->nextPtr;
			}
			newPtr->nextPtr = linker;
			linker = firstPtr;
			for (int i = 0; i < index - 1;i++) {
				linker = linker->nextPtr;
			}
			linker->nextPtr = newPtr;
		}

	}


	// insert node at back of list
	void insertAtBack(const NODETYPE& value) {
		ListNode<NODETYPE>* newPtr{ getNewNode(value) }; // new node

		if (isEmpty()) { // List is empty
			firstPtr = lastPtr = newPtr; // new list has only one node
		}
		else { // List is not empty
			lastPtr->nextPtr = newPtr; // update previous last node
			lastPtr = newPtr; // new last node
		}
	}
	bool removeAnywhere(const int & value) {
		if (isEmpty()) {
			return false;
		}
		else {
			ListNode<NODETYPE>*temp{ firstPtr };
			ListNode<NODETYPE> * toDelete;
			ListNode <NODETYPE>*connect;


			while ((temp->nextPtr == nullptr) || (temp->nextPtr->data != value)) {
				//special case for the first node
				if (temp->nextPtr == nullptr) {
					temp = firstPtr;
					firstPtr = firstPtr->nextPtr;
					delete temp;
					cout << value << " was deleted successfully\n";

					return true;
				}
				temp = temp->nextPtr;
			}
			toDelete = temp->nextPtr;
			connect = toDelete->nextPtr;
			delete toDelete;
			temp->nextPtr = connect;
			cout << value << " was deleted successfully\n";
			return true;
		}
	}


	bool isEmpty() const {
		return firstPtr == nullptr;
	}

	// display contents of List
	void print() const {
		if (isEmpty()) { // List is empty
			std::cout << "The list is empty\n\n";
			return;
		}

		ListNode<NODETYPE>* currentPtr{ firstPtr };

		std::cout << "The list is: \n";

		while (currentPtr != nullptr) { // get element data
			std::cout << currentPtr->data << ' ';
			currentPtr = currentPtr->nextPtr;
		}

		std::cout << "\n\n";
	}

private:
	ListNode<NODETYPE>* firstPtr{ nullptr }; // pointer to first node
	ListNode<NODETYPE>* lastPtr{ nullptr }; // pointer to last node  

	// utility function to allocate new node
	ListNode<NODETYPE>* getNewNode(const NODETYPE& value) {
		return new ListNode<NODETYPE>{ value };
	}
};

#endif

