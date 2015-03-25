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
	virtual void changeMainSubject(std::string typeName);
	virtual bool getIsProgramManager();
	virtual void changeIsProgramManager(bool isManager);
	virtual int getWorkingHours();
	virtual void changeWorkingHours(int workingHours);
	Teacher(std::string typeName, bool isManager, int wage, int workingHours, bool isProgramManager, std::string mainSubject);
	//virtual ~Teacher();
};

#endif