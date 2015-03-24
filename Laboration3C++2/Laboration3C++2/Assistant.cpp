#include "Assistant.h"
#include "Employment.h"
#include <string>
#include <iostream>
#include <sstream>

void Assistant::changeStudyProgram(std::string studyProgram)
{
	this->studyProgram = studyProgram;
}

void Assistant::changePointsTaken(int pointsTaken)
{
	this->pointsTaken = pointsTaken;
}

Assistant::Assistant(std::string typeName, int wage, std::string studyProgram, int pointsTaken) : Employment(typeName, 0, wage)
{
	changeStudyProgram(studyProgram);
	changePointsTaken(pointsTaken);
}

std::string Assistant::getStudyProgram()
{
	return studyProgram;
}

int Assistant::getPointsTaken()
{
	return pointsTaken;
}
int Assistant::getWageType()
{
	int wageType=1;

	return wageType;
}


std::string Assistant::toString()
{
	std::string apa;
	std::string chef;

	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << getPointsTaken();      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();

	apa = "Utbildningsprogram: " + getStudyProgram() +"\nAvklarade poäng: " + result + "\n";
	std::string total = Employment::toString() + apa;
	return total;
}

