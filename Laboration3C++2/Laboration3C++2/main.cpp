#include "Teacher.h"
#include "Assistant.h"
#include "TA.h"
#include "Employee.h"
#include <string>
#include <iostream>
#include <crtdbg.h>
#include <stdlib.h>
#include "Container.h"
#include "Menu.h"

//using namespace std;
	
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Employment* t = new Teacher("Lektor", true, 40000, 1500, true, "Matte");
	cout << t->toString() << endl;
	//Employment* a = new Assistant("Labhandledare", 100, "Spelprogrammering", 98);
	//cout << a->toString() << endl;
	//Employment* ta = new TA("Vaktmästare", false, 25000, 1700, false, true);
	//cout << ta->toString() << endl;
	delete t;
	//delete a;
	//delete ta;

	//Employment* empl = new Teacher("Adjunkt",false, 35000, 1600, true, "Programmering");
	//Employee* e = new Employee("Georg Boole", 1820, empl);
	//cout << e->toString() << endl;	//delete e;	//Menu();

	getchar();
	return 0;
}
