#include "Employee.h"
#include "Employment.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

Employee::Employee()
{
	this->name="John Doe";
	this->birthYear = 0;
	this->position=nullptr;
}

void Employee::changeName(string name)
{
	this->name = name;
}
string Employee::getName()
{
	return name;
}

void Employee::changeBirthYear(int birthYear)
{
	this->birthYear = birthYear;
}
int Employee::getBirthYear()
{
	return birthYear;
}

Employment* Employee::getPosition()
{
	return position;
}
void Employee::changePosition(Employment* position)
{
	this->position = position;
}

string Employee::toString()
{
	string apa;

	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << birthYear;      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();

	apa = "Namn: " + name + "\nFödelseår: " + result + "\n";

	return apa+position->toString();
}

Employee::Employee(string name, int birthYear, Employment* position)
{
	this->name = name;
	this->birthYear = birthYear;
	this->position = position;
}

Employee::Employee(const Employee& other) : position(other.position)
{
	this->name = other.name;
	this->birthYear = other.birthYear;
}

void Employee::operator=(const Employee& other)
{
	if (position == nullptr)
	{
		position = other.position;
	}
	else
	{
		*position = *other.position;
	}

	this->name = other.name;
	this->birthYear = other.birthYear;
}

Employee::~Employee()
{
	delete position;
}