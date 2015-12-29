#include <iostream>
#include "LinkedList.h"
using namespace std;

// Constructor
template <class T>
LinkedList<T> :: LinkedList() {
	first = new Node<T>();
	first->next = NULL;
	size = 0;
}


// Destructor
template <class T>
LinkedList<T> :: ~LinkedList() {
}


template <class T>
void LinkedList<T> :: add(T element) {
	Node<T>* current = new Node<T>();
	Node<T>* newNode = new Node<T>();
	newNode->element = element;
	current = first;

	if(empty()) {																//create first node if empty
		first->element = element;
	}
	else{																		//add node after last available node
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
	size++;																		//increase list size after add is complete
}


template <class T>
void LinkedList<T> :: addIndex(T element, int index) {							//add node at user specified index
	Node<T>* current = new Node<T>();
	Node<T>* newNode = new Node<T>();
	newNode->element = element;
	current = first;

	if(index == 0) {															//add node to become new first node
		if(empty()) {															//set first node
			first = newNode;
		}
		else {
			newNode->next = current;											//replace first node and point it to
			first = newNode;													//the previous first node which is now 2nd node
		}
		size++;
	}
	else if(index > 0 && index < size) {										//add node before the node at specified index
		for(int i = 0; i < index-1; i++) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
		size++;
	}
	else if (index == size){													//add node after last available node
		add(element);
	}
	else {																		//don't add node if index is invalid
		cout << "Invalid index." << endl;
	}
}


template <class T>
void LinkedList<T> :: remove() {												//remove last available node
	Node<T>* current = new Node<T>();
	current = first;
	int count = 0;

	if(size > 1) {																//remove any node except the first
		Node<T>* last = new Node<T>();											//can never remove first node
		last = first;															//otherwise Linked List object doesn't exist

		while(current->next != NULL) {
			current = current->next;
			count++;
		}
		for(int i = 0; i < count-1; i++) {
			last = last->next;
		}
		last->next = NULL;
		delete current;
		size--;
	}
}


template <class T>
void LinkedList<T> :: removeIndex(int index) {									//remove node at user specified index
	Node<T>* current = new Node<T>();
	current = first;

	if(index == 0) {															//remove first node
		first = first->next;
		delete current;
		size--;
	}
	else if(index > 0 && index < size-1) {										//remove any node inbetween first and last
		for(int i = 0; i < index-1; i++) {
			current = current->next;
		}
		Node<T>* temp = new Node<T>();
		temp = current->next;
		current->next = temp->next;
		cout << temp->element << endl;
		delete temp;
		size--;
	}
	else if(index == size-1) {													//remove last node
		for(int i = 0; i < index-1; i++) {
			current = current->next;
		}
		Node<T>* last = new Node<T>();
		last = current->next;
		current->next = NULL;
		delete last;
		size--;
	}
}


template <class T>
int LinkedList<T> :: getSize() {												//getter method to access size of Linked List
	return size;
}


template <class T>
void LinkedList<T> :: print() {													//print every element in Linked List in order
	Node<T>* current = new Node<T>();											//from first to last
	current = first;

	for(int i = 0; i < size; i++) {
		if(i != size-1) {
			cout << current->element << " ";
		}
		else {
			cout << current->element;
		}
		current = current->next;
	}
}


template <class T>
bool LinkedList<T> :: empty() {													//find if list is empty or not
	if(size == 0) {
		return true;
	}
	else return false;
}


void menu() {
	cout << "\n1. Add Node\n2. Add Node at Index\n3. Remove Node\n4. Remove Node at Index\n5. Print\n6. Exit\n" << endl;
}


int main() {
	LinkedList<int>* myList = new LinkedList<int>();
	int choice;

	do {
		menu();
		cout << "Enter option number: ";
		cin >> choice;
		cout << endl;
		switch(choice) {
			case 1:	{	int nodes, element;
						cout << "\tNumber of nodes: ";
						cin >> nodes;

						for(int i = 0; i < nodes; i++) {
							cout << "\tElement for node " << i+1 << ": ";
							cin >> element;
							myList->add(element);
						}
						cout << "\tList Size: " << myList->getSize() << endl;
						break;
					}
			case 2:	{	int element, index;
						cout << "\tElement for node: ";
						cin >> element;
						cout << "\tIndex of node: ";
						cin >> index;
						if(index < 0 || index > myList->getSize()) {
							cout << "Index out of range." << endl;
						}
						else {
							myList->addIndex(element, index);
						}
						cout << "\tList Size: " << myList->getSize() << endl;
						break;
					}
			case 3:	{	if(myList->getSize() > 1) {
							myList->remove();
							cout << "\tNode removed." << endl;
						}
						else {
							cout << "\tCannot remove only node." << endl;
						}
						cout << "\tList Size: " << myList->getSize() << endl;
						break;
					}
			case 4:	{	int index;
						cout << "\tIndex of node: ";
						cin >> index;
						if(index >= 0 && index < myList->getSize()) {
							myList->removeIndex(index);
						}
						else {
							cout << "\tIndex out of range." << endl;
						}
						cout << "\tList Size: " << myList->getSize() << endl;
						break;
					}
			case 5:	{	cout << "\tLinked List: [";
						myList->print();
						cout << "]" << endl;
						cout << "\tList Size: " << myList->getSize() << endl;
						break;
					}
			case 6:		break;
			default:	cout << "\tInvalid option." << endl;
						break;
		}	
	} while(choice != 6);
	return 0;
}