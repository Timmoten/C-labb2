#ifndef CONTAINER_H
#define CONTAINER_H

//#include <string>
//#include "Employee.h"

class Container
{
	private:
		int nr;
		Employee** employees;
	public:
		Container();
		~Container();
		void add(Employee* bob);
		std::string toString();

};

#endif