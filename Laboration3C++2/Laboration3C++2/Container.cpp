#include <string>
#include "Employee.h"
#include "Container.h"

Container::Container()
{
	this->nr = 0;
	this->employees = nullptr;
}

void Container::add(Employee* bob)
{
	if (nr == 0)
	{
		employees = new Employee*[1];
		employees[0] = bob;
		nr++;
	}
	else
	{
		Employee** tmp;
		tmp = new Employee*[(this->nr + 1)];
		for (int i = 0; i < this->nr; i++)
		{
			tmp[i] = this->employees[i];
		}
		delete[] this->employees; //med denna (2)
		tmp[this->nr] = bob; //byt plats enl assistent (tidigare 1)



		this->employees = tmp;
		
		this->nr++;
	}
}

string Container::toString()
{
	string apa;
	apa = "Följande personner finns i registret:\n";

	for (int i = 0; i < nr; i++)
	{
		apa = apa + employees[i]->toString() + "\n";
	}

	return apa;
}

Container::~Container()
{
	for (int i = 0; i < nr; ++i)
	{
		delete employees[i];
	}

	delete[] employees;
}