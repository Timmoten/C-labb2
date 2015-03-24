#ifndef TA_H
#define TA_H
#include "Employment.h"
#include <string>

class TA : public Employment
{
private:
	bool canCertify;
	bool hasSuperKey;
	int workingHours;
public:
	virtual std::string toString();
	virtual int getWageType();
	bool getCanCertify();
	void changeCanCertify(bool canCertify);
	bool getHasSuperKey();
	void changeHasSuperKey(bool hasSuperKey);
	int getWorkingHours();
	void changeWorkingHours(int workingHours);
	TA(std::string typeName, bool isManager, int wage, int workingHours, bool canCertify, bool hasSuperKey);
};

#endif