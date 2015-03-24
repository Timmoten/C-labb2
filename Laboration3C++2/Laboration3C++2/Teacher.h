#ifndef TEACHER_H
#define TEACHER_H
#include "Employment.h"
#include <string>

class Teacher : public Employment
{
private:
	std::string mainSubject;
	bool isProgramManager;
	int workingHours;
	Teacher();
public:
	virtual std::string toString();
	virtual int getWageType();
	std::string getMainSubject();
	void changeMainSubject(std::string typeName);
	bool getIsProgramManager();
	void changeIsProgramManager(bool isManager);
	int getWorkingHours();
	void changeWorkingHours(int workingHours);
	Teacher(std::string typeName, bool isManager, int wage, int workingHours, bool isProgramManager, std::string mainSubject);
	//virtual ~Teacher();
};

#endif