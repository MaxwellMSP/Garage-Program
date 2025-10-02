// Maxwell Petersen J00733630

#pragma once
#include<iostream>
#include<string>

//using namespace std; // don't do this ... ccd
using std::string;
using std::cout;
using std::endl;
using std::ostream;

class Car
{
	friend ostream& operator << (ostream& out, const Car& mycar);

public: 

	Car();

	Car(std::string Make, string Model, int Year); // constructor

	string getMake() const;
	string getModel() const;
	int getYear() const;

	void setMake(string Make);
	void setModel(string Model);
	void setYear(int Year);

	void print();

private:

	string make;
	string model;
	int year;



};



