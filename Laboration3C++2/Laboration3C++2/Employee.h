#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include "Employment.h"

using namespace std;

class Employee
{
private:
	string name;
	int birthYear;
	Employment* position;
	Employee();
public:
	virtual string toString();
	string getName();
	void changeName(string typeName);
	int getBirthYear();
	void changeBirthYear(int newBirthYear);
	Employment* getPosition();
	void changePosition(Employment* position);

	Employee(string name, int birthYear, Employment* position);
	Employee(const Employee& other);
	void operator=(const Employee& other);
	//Employee(ifstream* in);
	~Employee();
};

#endif