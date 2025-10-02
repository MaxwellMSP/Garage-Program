//Maxwell Petersen J00733630
#pragma once
#include "CarNode.h"
#include "Car.h"

class doublyLL
{
public:
	doublyLL(); // constructor 
	~doublyLL(); // destructor
	bool empty() const; // is list empty
	const Car& front() const; // get front element 
	void addFront(const Car& myCar); // add to front
	void addBack(const Car& mycar);
	void removeFront(); // remove front item
	void removeBack(); // remove back item
	void removeCar(string keyMake, string keyModel, int keyYear); // remove a specific car
	void displayList() const; // display list
	void displayRevList() const; // display list reversed
	void searchList(string keyMake,string keyModel,int keyYear); // search the list
	void editList(string keyMake, string keyModel, int keyYear); //edit an item in the list
	void getUserInput(string& kmake, string& kmodel, int& kyear); //helper function to get user input
private: 
	carNode* head, *tail; // Pointer to the head and a pointer to the tail

};