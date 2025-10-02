//Maxwell Petersen j00733630
#include "CarList.h"
using namespace std;




// Constructor
doublyLL::doublyLL()
	:head(NULL), tail(NULL) {
}

// Desrtructor 
doublyLL::~doublyLL()
{
	while (!empty())
	{
		removeFront(); // calls function to remove element and release memory
	}
}

bool doublyLL::empty() const
{
	return (head == NULL);
}

// Get front node.
const Car& doublyLL::front() const
{
	return head->car;
}

// Add to the front of the list
void doublyLL::addFront(const Car& myCar) 
{
	carNode* temp = new carNode;
	temp->car = myCar;
	temp->next = head;
	temp->prev = NULL;

	if (head == NULL)
	{
		tail = temp;
	}
	else {
		head->prev = temp;
	}

	head = temp;
	
}


// remove from front of the list
void doublyLL::removeFront()
{
	if (!empty())
	{
		carNode* temp = head;
		head = temp->next;
		delete temp;
	}
}

// Add to the back of the list
void doublyLL::addBack(const Car& mycar) {
	carNode* temp = new carNode;
	temp->car = mycar;
	temp->prev = tail;
	temp->next = NULL;

	if (tail == NULL)
	{
		head = temp;
	}
	else {
		tail->next = temp;
	}

	tail = temp;

}

// Remove from the back of the list
void doublyLL::removeBack() {
	if (!empty())
	{
		carNode* temp = tail;
		tail = temp->prev;
		delete temp;
	}
}

//prints list
void doublyLL::displayList() const
{
	if (!empty())
	{
		cout << "The following cars are in this list:\n";
		carNode* temp = head;
		while (temp)	        // temp evaluates to true if it is not NULL.
		{
			cout << temp->car << endl;
			temp = temp->next;	// Move to the next node, which if it's NULL
		}						     // will cause the loop to terminate.	   
		cout << endl;
	}
	else
	{
		cout << "There are no cars in this list.\n";
	}
}

//prints list backwards
void doublyLL::displayRevList() const
{
	if (!empty())
	{
		cout << "The following cars are in this list:\n";
		carNode* temp = tail;
		while (temp)	        // temp evaluates to true if it is not NULL.
		{
			cout << temp->car << endl;
			temp = temp->prev;	// Move to the next node, which if it's NULL
		}						     // will cause the loop to terminate.	   
		cout << endl;
	}
	else
	{
		cout << "There are no cars in this list.\n";
	}
}

// search the list
void doublyLL::searchList(string keyMake,string keyModel, int keyYear)  
{
	carNode* temp = head;
	if (!empty())
	{
		while (temp != NULL)
		{
			if (temp->car.getMake() == keyMake)
			{
				if (temp->car.getModel() == keyModel)
				{
					if (temp->car.getYear() == keyYear)
					{
						temp->car.print(); // call classes print method
						cout << endl;
						return;
					}
				}
			}
		temp = temp->next; // move to next node and exit loop if NULL
		}
	}
	else
	{
		cout << "There are no cars in this list.\n";
		return;
	}
	cout << "Car not found. Search unsuccessful.\t";
	return;
}

void doublyLL::editList(string keyMake, string keyModel, int keyYear) //edit an item in the list
{
	{
		cout << "Insert the edited car:\n";
		string kmake;
		string kmodel;
		int kyear;
		carNode* temp = head;
		if (!empty())
		{
			while (temp != NULL)
			{
				if (temp->car.getMake() == keyMake)
				{
					if (temp->car.getModel() == keyModel)
					{
						if (temp->car.getYear() == keyYear)
						{
							getUserInput(kmake, kmodel, kyear);
							temp->car.setMake(kmake);
							temp->car.setModel(kmodel);
							temp->car.setYear(kyear);
							return;
						}
					}
				}
				temp = temp->next; // move to next node and exit loop if NULL
			}
		}
		else
		{
			cout << "There are no cars in this list.\n";
			return;
		}
		cout << "Car not found. Search unsuccessful.\t";
		return;
	}
}

//remove a specific car from the list I referenced some code from https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
void doublyLL::removeCar(string keyMake, string keyModel, int keyYear)
{
	carNode* del = head;
	
	if (!empty())
	{
		while (del != NULL)
		{
			if (del->car.getMake() == keyMake)
			{
				if (del->car.getModel() == keyModel)
				{
					if (del->car.getYear() == keyYear)
					{
						if (del->prev == NULL) // I had a weird memory leak here so I had to manualy set adjust head and tail
						{
							removeFront();
							del = NULL;
							head->prev = NULL;
							delete del;
							return;
						}
						else if (del->next == NULL)
						{
							removeBack();
							del = NULL;
							tail->next = NULL;
							delete del;
							return;
						}
						else
						{
							del->prev->next = del->next;
							del->next->prev = del->prev;
							delete del;
							return;
							
						}
					}
				}
			}
			del = del->next; // move to next node and exit loop if NULL
		}
	}
	else
	{
		cout << "There are no cars in this list.\n";
		return;
	}
	cout << "Car not found. Search unsuccessful.\t";
	return;
}



void doublyLL::getUserInput(string& kmake, string& kmodel, int& kyear) {
	
	getline(std::cin, kmodel);
	cout << "\n Make: ";
	getline(std::cin, kmake);
	cout << "\n Model: ";
	getline(std::cin, kmodel);
	cout << "\n Year: ";
	cin >> kyear;
	return;
}



