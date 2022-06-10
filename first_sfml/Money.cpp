#include "Money.h"

Money::Money()
{
	name = "";
	value = 0;
	nextMoney = nullptr;
}

Money::Money(std::string name) : name(name), value(0), nextMoney(nullptr), beforeMoney(nullptr)
{

}

Money::~Money()
{
	delete nextMoney;
}

void Money::setName(std::string name)
{
	this->name = name;
}

void Money::setValue(double value)
{
	this->value = value;
}

void Money::setNextMoney(Money* nextMoney)
{
	this->nextMoney = nextMoney;
}

void Money::setBeforeMoney(Money* money)
{
	this->beforeMoney = money;
}

std::string Money::getName()
{
	return name;
}

double Money::getValue()
{
	return value;
}

Money* Money::getNextMoney()
{
	return nextMoney;
}

Money* Money::getBeforeMoney()
{
	return	beforeMoney;
}

void Money::addMoney(double v)
{
	int toSend = 0;

	value += v;

	if (value >= 1000) {
		
		toSend = toSend + (value - ((int)value % 1000)) / 1000;
		value = value - (toSend*1000);
	}

	if (nextMoney != nullptr)
		nextMoney->addMoney(toSend);
}

void Money::sendToBefore(double value)
{
	int toSend = 0;
	toSend = value * 1000;
	toSend %= 1000;
	beforeMoney->setValue(getValue()+toSend);
}