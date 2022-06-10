#pragma once
#include "Money.h"

/*
10^6 milion
10^9 bilion
10^12 trillion
10^15 quadrilion
10^18 quintillion
10^21 sextillion
10^24 septilion
10^27 octilion
10^30 nonillion
*/

class TransferBox
{
private:
	Money* before = new Money("before");
	Money* pln = new Money("PLN");
	Money* thousand = new Money("thousand");
	Money* million = new Money("million");
	Money* billion = new Money("billion");
	Money* trillion = new Money("trillion");
	Money* quadrillion = new Money("quadrillion");
	Money* quintillion = new Money("quintillion");
	Money* sextillion = new Money("sextillion");
	Money* septillion = new Money("septillion");
	Money* octillion = new Money("octillion");
	Money* nonillion = new Money("nonillion");
	Money* over_limit = new Money("over_limit");
public:
	TransferBox();
	~TransferBox();
	//function
	//void optimalization(Money*);
	void getStatus();
	//getters
	double getPLN();
	double getThousand();
	double getMillion();
	double getBillion();
	double getTrillion();
	double getQuadrillion();
	double getQuintillion();
	double getSextillion();
	double getSeptillion();
	double getOctillion();
	double getNonillion();

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
	//setters
	void setPLN(double);
	void setThousand(double);
	void setMillion(double);
	void setBillion(double);
	void setTrillion(double);
	void setQuadrillion(double);
	void setQuintillion(double);
	void setSextillion(double);
	void setSeptillion(double);
	void setOctillion(double);
	void setNonillion(double);
};

