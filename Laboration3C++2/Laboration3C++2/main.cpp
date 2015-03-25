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

int Meny()
{
	int check = 0;
	int a;
	std::string name, type, main, awnser, awnser2, awnser3;
	int bY, wage, time;
	bool chef, pa, key;
	Container team;
	do
	{
		cout << "\nMeny\n0 Avsluta\n1 Ny Lärare\n2 Ny Assistent\n3 Ny TA-personal\n4 Skriv ut alla\n" << endl;
		cout << "Ditt val: ";
		cin >> a;
		if (a < 0 || a>4)
		{
			cout << "Felaktigt val";
		}
		else
		{
			//cout << "Ditt val: " + a;

			switch (a)
			{
			case 0:
			{
				cout << "Programmet avslutas..." << endl;
				check = 1;
				break;
			}
			case 1: //ny lärare
			{
				//Employee
				cout << "\nNamn: ";
				//cin >> name; //hanterar inte mellanslag
				cin.ignore();
				getline(cin, name);
				cout << "\nFödelseår: ";
				cin >> bY;

				//Employment
				cout << "\nTjänstetyp: ";
				cin >> type;
				cout << "\nLön: ";
				cin >> wage;
				cout << "\nChef(j/n): ";
				cin >> awnser;
				if (awnser == "j" || awnser == "y")
				{
					chef = true;
				}
				else
					chef = false;

				//teacher
				cout << "\nTjänstegöringstid: ";
				cin >> time;
				cout << "\nHuvudämne: ";
				cin >> main;
				cout << "\nProgramansvarig(j/n): ";
				cin >> awnser2;
				if (awnser2 == "j" || awnser2 == "y")
				{
					pa = true;
				}
				else
					pa = false;
				//Make an object here
				Employment* emp = new Teacher(type, chef, wage, time, pa, main);
				Employee* e = new Employee(name, bY, emp);
				team.add(e);
				//delete emp;
				//delete e;

				break;
			}
			case 2: //assistent
			{
				//Employee
				cout << "\nNamn: ";
				//cin >> name;
				cin.ignore();
				getline(cin, name);
				cout << "\nFödelseår: ";
				cin >> bY;

				//Employment
				cout << "\nTjänstetyp: ";
				cin >> type;
				cout << "\nLön: ";
				cin >> wage;
				/*cout << "\nChef(j/n): "; //inte aktuellt för assistent
				cin >> awnser;
				if (awnser == "j" || awnser == "y")
				{
				chef == true;
				}
				else
				chef = false;*/

				//Assistent
				cout << "\nUtbildningsprogram: ";
				cin >> main;
				cout << "\nAvklarade poäng: ";
				cin >> time;

				//Make an object here
				Employment* emp = new Assistant(type, wage, main, time);
				Employee* e = new Employee(name, bY, emp);
				team.add(e);
				//delete emp;
				//delete e;

				break;
			}
			case 3: //TA
			{
				//Employee
				cout << "\nNamn: ";
				//cin >> name;
				cin.ignore();
				getline(cin, name);
				cout << "\nFödelseår: ";
				cin >> bY;

				//Employment
				cout << "\nTjänstetyp: ";
				cin >> type;
				cout << "\nLön: ";
				cin >> wage;
				cout << "\nChef(j/n): ";
				cin >> awnser;
				if (awnser == "j" || awnser == "y")
				{
					chef = true;
				}
				else
					chef = false;

				//TA
				cout << "\nTjänstegöringstid: ";
				cin >> time;
				cout << "\nAttesrätt(j/n): ";
				cin >> awnser2;
				if (awnser2 == "j" || awnser2 == "y")
				{
					pa = true;
				}
				else
					pa = false;
				cout << "\nHar huvudnyckel(j/n): ";
				cin >> awnser3;
				if (awnser3 == "j" || awnser3 == "y")
				{
					key = true;
				}
				else
					key = false;
				//Make an object here
				Employment* emp = new TA(type, chef, wage, time, pa, key);
				Employee* e = new Employee(name, bY, emp);
				team.add(e);
				//delete emp;
				//delete e;

				break;
			}
			case 4:
			{
				cout << team.toString();
				break;
			}
			default:
			{
				cout << "\nshit went down" << endl;
				break;
			}

			}

		}

	} while (check == 0);
	return 0;
}



int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Employment* t = new Teacher("Lektor", true, 40000, 1500, true, "Matte");
	//cout << t->toString() << endl;
	//Employment* a = new Assistant("Labhandledare", 100, "Spelprogrammering", 98);
	//cout << a->toString() << endl;
	//Employment* ta = new TA("Vaktmästare", false, 25000, 1700, false, true);
	//cout << ta->toString() << endl;
	//delete t;
	//delete a;
	//delete ta;

	//Employment* empl = new Teacher("Adjunkt",false, 35000, 1600, true, "Programmering");
	//Employee* e = new Employee("Georg Boole", 1820, empl);
	//cout << e->toString() << endl;	//delete e;	Menu();	//Menu menyn;	//int apa=menyn.Meny();

	getchar();
	return 0;
}
