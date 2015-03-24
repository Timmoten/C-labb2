#ifndef EMPLOYMENT_H
#define EMPLOYMENT_H
#include <string>
using namespace std;

class Employment
{
	private:
		string typeName;
		bool isManager;
		int wage;
		Employment();
	public:
		virtual string toString();
		virtual int getWageType();
		Employment(string typeName,bool isManager, int wage);
		string getTypeName();
		void changeTypeName(string typeName);
		bool getIsManager();
		void changeIsManager(bool isManager);
		int getWage();
		void changeWage(int wage);
		Employment(const Employment& other);
		void operator=(const Employment& other);

};

#endif