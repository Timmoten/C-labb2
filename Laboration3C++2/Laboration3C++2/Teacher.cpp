#include "Teacher.h"
#include "Employment.h"
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

void Teacher::changeMainSubject(std::string mainSubject)
{
	this->mainSubject = mainSubject;
}
void Teacher::changeIsProgramManager(bool isProgramManager)
{
	this->isProgramManager = isProgramManager;
}
void Teacher::changeWorkingHours(int workingHours)
{
	this->workingHours = workingHours;
}

Teacher::Teacher(std::string typeName, bool isManager, int wage, int workingHours, bool isProgramManager, std::string mainSubject) : Employment(typeName, isManager, wage)
{
	changeWorkingHours(workingHours);
	changeIsProgramManager(isProgramManager);
	changeMainSubject(mainSubject);
}

std::string Teacher::getMainSubject()
{
	return mainSubject;
}
bool Teacher::getIsProgramManager()
{
	return isProgramManager;
}
int Teacher::getWorkingHours()
{
	return workingHours;
}
int Teacher::getWageType()
{
	int wageType=0;

	return wageType;
}


std::string Teacher::toString()
{
	std::string apa;
	std::string chef;

	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << getWorkingHours();      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();

	if (getIsProgramManager() == true)
		chef = "ja";
	else
		chef = "nej";
	
	apa = "Tjänstegöringstid: " + result + " per år" + "\nHuvudämne: " + getMainSubject() + "\nProgramansvarig: " + chef + "\n";
	std::string total = Employment::toString() + apa;
	return total;
}

Teacher::~Teacher()
{
	//Does nothing
}