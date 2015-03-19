#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include <string>;
#include <iostream>;//onödig?
#include <vector>; //onödig?

class Player
{
public:
	std::string fName;
	std::string lName;
	int bYear;
	std::string* matchDates;

	std::string toString();
	std::string toString(int a);
	void addMatchDate(std::string date);
	Player();
	Player(std::string fName, std::string lName, int bYear);
	//Player(Player const &other);
	//~Player();
	//void save(std::ofstream* out);
	void changeNumberOfMatches(int amount);
	void addNumberOfMatches(int amount);
	int getNumberOfMatches();
	~Player();
	Player(Player& const other);
	Player& Player::operator=(Player& const other);
	bool Player::operator<(Player& const other);
	//bool Player::operator>(Player& const a, Player& const b);

private:
	int numberOfMatches;

};




#endif