//Maxwell Petersen J00733630

#include "Car.h"

using namespace std;

Car::Car() {
	
	setMake("");
	setModel("");
	setYear(0);

}



Car::Car(string Make, string Model, int Year) {
	setMake(Make);
	setModel(Model);
	setYear(Year);
}


string Car::getMake() const
{
	return make;
}

string Car::getModel() const
{
	return model;
}

int Car::getYear() const
{
	return year;
}

void Car::setMake(string Make)
{
	make = Make;
}

void Car::setModel(string Model)
{
	model = Model;
}

void Car::setYear(int Year)
{
	if (Year < 1886) // 1886 is the year of the first production car
	{
		year = 0;
	}
	else
	{
		year = Year;
	}
}

void Car::print()
{
	cout << make << " " << model << " " << year;
}

ostream& operator<<(ostream& out, const Car& mycar)
{
	out << mycar.year << " " << mycar.make << " " << mycar.model;
	return out;
}

