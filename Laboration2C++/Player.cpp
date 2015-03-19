#include "Player.h"
#include <string>
#include <sstream>
#include <fstream>

std::string Player::toString()
{

	//To convert a number into a string (include sstream):
	int holder=this->numberOfMatches;
	std::string aString;
	std::string matches;
	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << bYear;      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();
	if (holder != 0 && matchDates != nullptr)
	{
		for (int i = 0; i < (holder - 1); i++)
		{
			matches = matches + matchDates[i] + ", ";
		}
		matches = matches + matchDates[(holder - 1)];
		aString = "Namn: " + fName + " " + lName + "\nFödelseår: " + result + "\nMatchdatum: " + matches + "\n";
	}
	else
	{
		aString = "Namn: " + fName + " " + lName + "\nFödelseår: " + result + "\nMatchdatum: data saknas" "\n";
	}

	return aString;
}
std::string Player::toString(int a)
{
	std::string result;                // string which will contain the result
	std::ostringstream convert;  // stream used for the conversion
	convert << a;      // insert the textual representation of 'number' in the characters in the stream
	result = convert.str();
	return result;
}

void Player::changeNumberOfMatches(int amount)
{
	this->numberOfMatches = amount;
}
void Player::addNumberOfMatches(int amount)
{
	this->numberOfMatches = amount;
	this->matchDates = new std::string[amount];
}

void Player::addMatchDate(std::string date)
{

	std::string* tmp;
	tmp = new std::string[(this->numberOfMatches + 1)];
	for (int i = 0; i < this->numberOfMatches; i++)
	{
		tmp[i] = this->matchDates[i];
	}
	delete[] this->matchDates; //med denna (2)
	tmp[this->numberOfMatches] = date; //byt plats enl assistent (tidigare 1)
	
	
	
	this->matchDates = tmp;
	//changeNumberOfMatches(this->numberOfMatches + 1);
	this->numberOfMatches++;
}

Player::Player()
{
	//this->fName = "john";
	//this->lName = "Doe";
	//this->bYear = 1944;
	this->matchDates = nullptr;
	this->numberOfMatches = 0;
	
}
Player::Player(std::string fName, std::string lName, int bYear)
{
	this->fName = fName;
	this->lName = lName;
	this->bYear = bYear;
	this->matchDates = nullptr;
	this->numberOfMatches = 0;
}

int Player::getNumberOfMatches()
{
	return this->numberOfMatches;
}

Player::~Player()
{
	delete[] matchDates;
}

Player::Player(Player& const other)
{
	this->fName = other.fName;
	this->lName = other.lName;
	this->bYear = other.bYear;
	this->matchDates = nullptr;
	this->numberOfMatches = 0;
	int tmp = other.getNumberOfMatches();
	for (int a = 0; a < tmp; a++)
	{
		this->addMatchDate(other.matchDates[a]);
	}
}

Player& Player::operator=(Player& const other)
{
	if (this != &other)
	{
		this->fName = other.fName;
		this->lName = other.lName;
		this->bYear = other.bYear;
		this->matchDates = nullptr;
		this->numberOfMatches = 0;
		int tmp = other.getNumberOfMatches();
		for (int i = 0; i < tmp; i++)
		{
			this->addMatchDate(other.matchDates[i]);
		}
	}

	return *this;
}

bool Player::operator< (Player& const other)
{
	if (this->getNumberOfMatches() < other.getNumberOfMatches())
	{
		return 1;
	}
	else
	{
		return 0;
	}
}