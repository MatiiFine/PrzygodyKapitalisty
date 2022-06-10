#pragma once
#include <iostream>

class Money
{
private:
	std::string name;
	double value;
	Money* nextMoney;
	Money* beforeMoney;
public:
	Money();
	Money(std::string);
	~Money();

	void setName(std::string);
	void setValue(double);
	void setNextMoney(Money*);
	void setBeforeMoney(Money*);

	std::string getName();
	double getValue();
	Money* getNextMoney();
	Money* getBeforeMoney();

	void addMoney(double);
	void sendToBefore(double);
};