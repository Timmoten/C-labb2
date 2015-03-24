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
	if (employees == nullptr)
	{
		employees = new Employee*[1];
		employees[0] = bob;
		nr=nr+1;
	}
	else
	{
		Employee** tmp;
		tmp = new Employee*[nr + 1];
		for (int i = 0; i < nr; i++)
		{
			tmp[i] = this->employees[i];
		}
		delete[] employees; //med denna (2)
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