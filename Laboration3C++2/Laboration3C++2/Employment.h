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
		Employment(std::string typeName, bool isManager, int wage);
		Employment(const Employment& other);
		void operator=(const Employment& other);
		virtual std::string toString();
		virtual int getWageType();
		virtual std::string getTypeName();
		virtual void changeTypeName(std::string typeName);
		virtual bool getIsManager();
		virtual void changeIsManager(bool isManager);
		virtual int getWage();
		virtual void changeWage(int wage);
		
		virtual ~Employment();
};

#endif