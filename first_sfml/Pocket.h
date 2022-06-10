#pragma once
#include <iostream>
#include <math.h>
#include "Money.h"
#include "TransferBox.h"
#include "not_enough_money.h"

class Pocket
{
private:
	Money* beforeContainer = new Money(); // is using to send less money than 1PLN (we don't care  small value)
	Money* pln = new Money();
	Money* thousand = new Money();
	Money* million = new Money();
	Money* billion = new Money();
	Money* trillion = new Money();
	Money* quadrillion = new Money();
	Money* quintillion = new Money();
	Money* sextillion = new Money();
	Money* septillion = new Money();
	Money* octillion = new Money();
	Money* nonillion = new Money();

	Money* overLimit = new Money(); // is using when user exceed 1000 nonilions

	void take_from_next(Money*);
public:
	Pocket();
	~Pocket();
	//functions
	void transferMoney(TransferBox*);
	void takeMoney(TransferBox*);
	bool able_to_take(TransferBox*);
	void optimalization();
	//getters
	void getPocketStatus();
	int getPLN();
	int getThousand();
	int getMillion();
	int getBillion();
	int getTrillion();
	int getQuadrillion();
	int getQuintillion();
	int getSextillion();
	int getSeptillion();
	int getOctillion();
	int getNonillion();
	std::string namePln();
	std::string nameThousand();
	std::string nameMillion();
	std::string nameBillion();
	std::string nameTrillion();
	std::string nameQuadrillion();
	std::string nameQuintillion();
	std::string nameSextillion();
	std::string nameSeptillion();
	std::string nameOctillion();
	std::string nameNonillion();
	Money* PLN();
	Money* Thousand();
	Money* Million();
	Money* Billion();
	Money* Trillion();
	Money* Quadrillion();
	Money* Quintillion();
	Money* Sextillion();
	Money* Septillion();
	Money* Octillion();
	Money* Nonillion();
};

