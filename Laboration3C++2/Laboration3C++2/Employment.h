#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H

#include <string>

//using namespace std;

class Employment
{
	private:
		std::string typeName;
		bool isManager;
		int wage;
		Employment();
	public:
		virtual std::string toString();
		virtual int getWageType();
		Employment(std::string typeName, bool isManager, int wage);
		std::string getTypeName();
		void changeTypeName(std::string typeName);
		bool getIsManager();
		void changeIsManager(bool isManager);
		int getWage();
		void changeWage(int wage);
		Employment(const Employment& other);
		void operator=(const Employment& other);

};

#endif