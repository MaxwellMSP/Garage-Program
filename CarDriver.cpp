//Maxwell Petersen J00733630
#include <iostream>
#include <string>
#include <conio.h>
#include <limits>

#include "Car.h"
#include "CarList.h"

using namespace std;

void pressAnyKey();
void getUserInput(string& make, string& model, int& year);


int main()
{
	doublyLL carList;

	carList.addFront(Car("Mini", "Cooper Countryman", 2014));
	carList.addFront(Car("Porche", "911", 2022));
	carList.addBack(Car("Toyota", "Supra", 2023));
	carList.addBack(Car("Nissan", "GTR", 2023));


	// Display menu for user choice.
	int choice = 0;
	bool keepGoing = true;
	while (keepGoing) {
		cout << endl
			<< "Maxwell Petersen J00733630\n"
			<< "---------------------------------------------------------------------\n"
			<< " Select an option from the menu below\n"
			<< " by entering the number of the choice\n"
			<< "---------------------------------------------------------------------\n"
			<< "\t1\tAdd car to the front of the list\n"
			<< "\t2\tAdd car to the back of the list\n"
			<< "\t3\tRemove a car in the list\n"
			<< "\t4\tEdit a car in the list\n"
			<< "\t5\tSearch for a car by make, model, and year\n"
			<< "\t6\tDisplay all cars in list\n"
			<< "\t7\tDisplay all cars in list (reversed)\n"
			<< "\t8\tDisplay the first car in the list\n"
			<< "\t9\tEnd program\n"
			<< "---------------------------------------------------------------------\n\n"
			<< "Enter your choice : ";


		// Get user choice and process.
		cin >> choice;
		// check for bad input
		if (cin.fail()) {
			cin.clear();
			cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
			cout << "\n\n\tOnly integer input please!. \n";
			pressAnyKey();
			continue;   // display the menu again
		}

		// remove newline character in case we call getline()
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		switch (choice) {
			// selections 2,3,4 and 8  are not implemented
			// aka Under Construction
		case 1:
		{  // added insert node at head for demonstration --ccd
			string make, model;
			int year;
			getUserInput(make, model, year);
			carList.addFront(Car(make, model, year));
			pressAnyKey();
			break;
		}
		case 2:  // add to the back of the list
		{
			string make, model;
			int year;
			getUserInput(make, model, year);
			carList.addBack(Car(make, model, year));
			pressAnyKey();
			break;
		}
		case 3: // remove a car in the list
		{
			string make, model;
			int year;
			cout << "\n Insert the car you'd like to remove:\n";
			getUserInput(make, model, year);
			carList.removeCar(make,model, year);
			pressAnyKey();
			break;
		}
		case 4: //edit a car in the list
		{
			cout << "\nInsert the car you'd like to alter:\n";
			string make, model;
			int year;
			getUserInput(make, model, year);
			carList.editList(make, model, year);
			pressAnyKey();
			break;

		}
		case 5: // search by model and year
		{
			string make, model;
			int year;
			getUserInput(make, model, year);
			carList.searchList(make, model, year);
			pressAnyKey();
			break;
		}

		case 6:	// Display car list.
		{
			carList.displayList();
			pressAnyKey();
			break;
		}
		case 7: // Display car list in reverse
		{
			carList.displayRevList();
			pressAnyKey();
			break;
		}
		case 8:
		{
			cout << carList.front() << endl;
			pressAnyKey();
			break;
		}
		case 9: // Quit program.
		{
			keepGoing = false;		// Exit from menu loop and program.
			cout << "The program is now ending.\n";
			pressAnyKey();
			break;
		}
		default: // Catch all respones that are currently not ready.
		{
			cout << "That option is currently not available\n";
			pressAnyKey();
			break;
		}
		} // end switch
	} // end while

	return 0;
} // end main


// Press any key to continue.
void pressAnyKey() {
	char ch = '\0';
	cout << "Press any key to continue" << endl << endl;
	ch = _getch();		// Waits and gets next character entered.	
	system("cls");	       // clear the screen on Windows... system("clear") on linux
	return;
}



void getUserInput(string& make, string& model, int& year) {
	

	cout << "\n Make: ";
	getline(std::cin, make);
	cout << "\n Model: ";
	getline(std::cin, model);
	cout << "\n Year: ";
	cin >> year;
	return;
}

