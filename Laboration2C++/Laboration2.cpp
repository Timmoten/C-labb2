#include <iostream>
#include <crtdbg.h>
#include <string>
#include "Player.h"
#include <fstream>

using namespace std;

void menu(Player *team, int nr)
{
	int a = 0;
	string datum;
	do
	{
		cout << endl << "1. Avsluta" << endl << "2. Skriv ut hela laget" << endl << "3. Lägg till matchdatum" << endl << "4. Spara i filen" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			cout << "programmet avslutas...";
			break;
		case 2:
		{
			//skriv ut laget
			for (int i = 0; i < nr; i++)
			{
				cout << "Player nr." << i+1 << endl;
				cout << team[i].toString() << endl;
			}
			break;
		}
		case 3:
		{
			//lägg till datum
			cout << "Vilket är nästa matchdatum du vill lägga till? Formen 20150515 " << endl;
			cin >> datum;
			for (int c = 0; c < nr; c++)
			{
				team[c].addMatchDate(datum);
			}
			break;
		}
		case 4:
		{
			//spara
			ofstream dataOut;
			dataOut.open("Players2.txt");
			if (dataOut.is_open())
			{
				/*
				cout << "Namn? ";
				string aName;
				getline(cin, aName); //även mellanslag
				dataOut << aName;
				cout << "Årtal? ";
				int year;
				cin >> year; cin.ignore();
				*/
				
				dataOut << team->toString(nr) << endl;
				for (int i = 0; i < nr; i++)
				{
					dataOut << team[i].fName << endl << team[i].lName << endl << team->toString(team[i].bYear) << endl;
					dataOut << team[i].getNumberOfMatches() << endl;
					for (int b = 0; b < team[i].getNumberOfMatches(); b++)
					{
						dataOut << team[i].matchDates[b] << endl;
					}
				}
				dataOut.close();
				break;
			}
			else
			{
				cout << "Problem att öppna filen" << endl;
				break;
			}

		}
		default:
		{
			cout << "error i switchen!!";
			break;
		}
			
		}

	} while (a != 1);
}

Player* getTeam(int& nrOfPlayers, char* fileName)
{
	Player* team;
	int numberOfMatches, numberOfPlayers;
	cout << "Vad heter filen? ";
	ifstream dataIn;
	dataIn.open(fileName); //parametern ska vara char*
	if (dataIn.is_open())
	{
		string aLine;
		//read ahead
		dataIn >> aLine;
		int i = stoi(aLine);
		numberOfPlayers = i;
		nrOfPlayers = i;
		team = new Player[i];
		//dataIn >> aLine; //inte här

		for (int x = 0; x < i; x++)
		{
			while (!dataIn.fail())
			{
				dataIn >> aLine; //enligt assistent ska vara här
				if (dataIn.fail()) // va tvungen att lägga till detta eftersom att while inte kolla under tiden bara i slutet om vilkoret fortfarande stämmer.
				{
					break; // do while så hade jag sluppit denna.
				}
				team[x].fName = aLine;
				dataIn >> aLine;
				team[x].lName = aLine;

				dataIn >> aLine;
				team[x].bYear = stoi(aLine);

				dataIn >> aLine;

				numberOfMatches = stoi(aLine);

				for (int y = 0; y < numberOfMatches; y++) //fick hjälp med kommentera bort dataline innnan
				{
					dataIn >> aLine;
					team[x].addMatchDate(aLine);
				}

				x++;
			}
		}

	}
	else
		cout << "Problem att öppna filen" << endl;

	return team;
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	string fileName;
	//string fName, lName;
	Player* team;
	//int bYear;
	int numberOfMatches, numberOfPlayers;
	/*cout << "Vad heter filen? ";
	getline(cin, fileName);
	ifstream dataIn;
	dataIn.open(fileName.c_str()); //parametern ska vara char*
	if (dataIn.is_open())
	{
		string aLine;
		//read ahead
		dataIn >> aLine;
		int i = stoi(aLine);
		numberOfPlayers = i;
		team = new Player[i];
		//dataIn >> aLine; //inte här
		
		for (int x = 0; x < i; x++)
		{
			while (!dataIn.fail())
			{
				dataIn >> aLine; //enligt assistent ska vara här
				if (dataIn.fail()) // va tvungen att lägga till detta eftersom att while inte kolla under tiden bara i slutet om vilkoret fortfarande stämmer.
				{
					break; // do while så hade jag sluppit denna.
				}
				//fName = aLine;
				team[x].fName = aLine;
				//team->fName = aLine;
				
				dataIn >> aLine;
				//lName = aLine;
				team[x].lName = aLine;
				
				dataIn >> aLine;
				//bYear = stoi(aLine);
				team[x].bYear = stoi(aLine);
				//Player* aPlayer = new Player(fName, lName, bYear);
				//cout << aPlayer->toString();

				dataIn >> aLine;

				numberOfMatches = stoi(aLine);
				//team[x].changeNumberOfMatches(stoi(aLine));
				//aPlayer->changeNumberOfMatches(numberOfMatches);
				//dataIn >> aLine;
				for (int y = 0; y < numberOfMatches; y++) //fick hjälp med kommentera bort dataline innnan
				{
					dataIn >> aLine;
					team[x].addMatchDate(aLine);			
				}
				/*for (int y = 0; y < team[x].getNumberOfMatches(); y++)
				{
					team[x].addMatchDate(aLine);
					dataIn >> aLine;
				}*/
				/*for (int y = 0; y < numberOfMatches; y++)
				{
					aPlayer->addMatchDate(aLine);
					dataIn >> aLine;
				}*/
				//cout << team[x].toString(); //skriv ut laget
				//delete[] aPlayer->matchDates;
				//delete aPlayer;
				/*x++;
			}
		}
		
	}
	else
		cout << "Problem att öppna filen" << endl;*/

	/*for (int slut = 0; slut < numberOfPlayers; slut++)
	{
		delete[] team[slut].matchDates;
	}*/

	//cout << "Vad heter filen? ";
	//getline(cin, fileName);

	team = getTeam(numberOfPlayers, "Players2.txt");

	//menu(team, numberOfPlayers);

	Player newPlayer = team[0];
	cout << team[0].toString();
	newPlayer.fName = "Kalle";
	newPlayer.lName = "Svensson";
	newPlayer.bYear = 1929;
	cout << newPlayer.toString();
	newPlayer.addMatchDate("tst");
	cout << newPlayer.toString();
	//cout << team[0].toString()<<endl;

	Player newPlayer2("", "", 0);
	cout << newPlayer2.toString();

	newPlayer2 = newPlayer;
	cout << newPlayer2.toString();
	newPlayer2.fName = "Marta";
	newPlayer2.lName = "Viera";

	newPlayer2.addMatchDate("2014-12-31");

	cout << newPlayer2.toString();
	cout << newPlayer.toString();

	if (team[3] < team[0])
	{
		cout << "det fungerar tror jag" << endl;
	}
	else
	{
		cout << "nope" << endl;
	}



	delete[] team;

	fflush(stdin);
	getchar();
	return 0;
}



/*

Player* getTeam(int& nrOfPlayers, char* fileName)
{
//string fileName;
//string fName, lName;
Player* team;
//int bYear;
int numberOfMatches, numberOfPlayers;
cout << "Vad heter filen? ";
//getline(cin, fileName);
ifstream dataIn;
dataIn.open(fileName); //parametern ska vara char*
if (dataIn.is_open())
{
string aLine;
//read ahead
dataIn >> aLine;
int i = stoi(aLine);
numberOfPlayers = i;
nrOfPlayers = i;
team = new Player[i];
//dataIn >> aLine; //inte här

for (int x = 0; x < i; x++)
{
while (!dataIn.fail())
{
dataIn >> aLine; //enligt assistent ska vara här
if (dataIn.fail()) // va tvungen att lägga till detta eftersom att while inte kolla under tiden bara i slutet om vilkoret fortfarande stämmer.
{
break; // do while så hade jag sluppit denna.
}
//fName = aLine;
team[x].fName = aLine;
//team->fName = aLine;

dataIn >> aLine;
//lName = aLine;
team[x].lName = aLine;

dataIn >> aLine;
//bYear = stoi(aLine);
team[x].bYear = stoi(aLine);
//Player* aPlayer = new Player(fName, lName, bYear);
//cout << aPlayer->toString();

dataIn >> aLine;

numberOfMatches = stoi(aLine);
//team[x].changeNumberOfMatches(stoi(aLine));
//aPlayer->changeNumberOfMatches(numberOfMatches);
//dataIn >> aLine;
for (int y = 0; y < numberOfMatches; y++) //fick hjälp med kommentera bort dataline innnan
{
dataIn >> aLine;
team[x].addMatchDate(aLine);
}
/*for (int y = 0; y < team[x].getNumberOfMatches(); y++)
{
team[x].addMatchDate(aLine);
dataIn >> aLine;
}*/
/*for (int y = 0; y < numberOfMatches; y++)
{
aPlayer->addMatchDate(aLine);
dataIn >> aLine;
}*/
//cout << team[x].toString(); //skriv ut laget
//delete[] aPlayer->matchDates;
//delete aPlayer;
/*x++;
			}
		}

	}
	else
		cout << "Problem att öppna filen" << endl;

		return team;
}

*/