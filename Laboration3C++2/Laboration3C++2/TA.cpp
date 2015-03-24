#include "TA.h"
#include "Employment.h"
#include <string>
#include <iostream>
#include <sstream>

void TA::changeCanCertify(bool canCertify)
{
	this->canCertify = canCertify;
}
void TA::changeHasSuperKey(bool hasSuperKey)
{
	this->hasSuperKey = hasSuperKey;
}
void TA::changeWorkingHours(int workingHours)
{
	this->workingHours = workingHours;
}

TA::TA(std::string typeName, bool isManager, int wage, int workingHours, bool canCertify, bool hasSuperKey) : Employment(typeName, isManager, wage)
{
	changeWorkingHours(workingHours);
	changeCanCertify(canCertify);
	changeHasSuperKey(hasSuperKey);
}

bool TA::getCanCertify()
{
	return canCertify;
}
bool TA::getHasSuperKey()
{
	return hasSuperKey;
}
int TA::getWorkingHours()
{
	return workingHours;
}
int TA::getWageType()
{
	int wageType=0;

	return wageType;
}


std::string TA::toString()
{
	std::string apa;
	std::string key,cert;

	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << getWorkingHours();      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();


	if (getHasSuperKey() == true)
		key = "ja";
	else
		key = "nej";
	if (getCanCertify() == true)
		cert = "ja";
	else
		cert = "nej";

	apa = "Tjänstegöringstid: " + result + " per år" + "\nAttesrätt: " + cert + "\nHar huvudnyckel: " + key + "\n";
	std::string total = Employment::toString() + apa;
	return total;
}