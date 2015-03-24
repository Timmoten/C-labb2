#include "Employment.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

Employment::Employment()
{
	typeName = "Default type";
	isManager = false;
	wage = 0;
}
void Employment::changeTypeName(std::string typeName)
{
	this->typeName = typeName;
}
void Employment::changeIsManager(bool isManager)
{
	this->isManager = isManager;
}
void Employment::changeWage(int wage)
{
	this->wage = wage;
}
Employment::Employment(std::string typeName, bool isManager, int wage)
{
	changeTypeName(typeName);
	changeIsManager(isManager);
	changeWage(wage);
}
std::string Employment::getTypeName()
{
	return typeName;
}
bool Employment::getIsManager()
{
	return isManager;
}
int Employment::getWage()
{
	return wage;
}
std::string Employment::toString()
{
	std::string apa;
	std::string type;
	std::string manager;
	if (getIsManager() == true)
	{
		manager = "Ja";
	}
	else
	{
		manager = "Nej";
	}

	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << getWage();      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();

	if (getWageType() == 0)
	{
		type = "/ månad";
	}
	else
		type = "/ timme";

	apa = "Tjänstetyp: " + getTypeName() + "\nLön: " + result + " " + type +"\nChefstjänst: " + manager + "\n";
	return apa;
}
int Employment::getWageType()
{
	int wageType=0;

	return wageType;
}

Employment::Employment(const Employment& other)
{
	this->typeName = other.typeName;
	this->isManager = other.isManager;
	this->wage = other.wage;
}

void Employment::operator=(const Employment& other)
{
	typeName = other.typeName;
	isManager = other.isManager;
	wage = other.wage;
}