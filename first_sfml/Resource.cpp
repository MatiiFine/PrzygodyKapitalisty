#include "Resource.h"

void Resource::earnings_up(double f)
{
	earnings->setPLN(earnings->getPLN() * f);
	earnings->setThousand(earnings->getThousand() * f);
	earnings->setMillion(earnings->getMillion() * f);
	earnings->setBillion(earnings->getBillion() * f);
	earnings->setTrillion(earnings->getTrillion() * f);
	earnings->setQuadrillion(earnings->getQuadrillion() * f);
	earnings->setQuintillion(earnings->getQuintillion() * f);
	earnings->setSextillion(earnings->getSextillion() * f);
	earnings->setSeptillion(earnings->getSeptillion() * f);
	earnings->setOctillion(earnings->getOctillion() * f);
	earnings->setNonillion(earnings->getNonillion() * f);
	optimalization1(earnings->PLN());
	optimalization2(earnings->Nonillion());
}

void Resource::cost_up(double f)
{
	cost->setPLN(cost->getPLN() * f);
	cost->setThousand(cost->getThousand() * f);
	cost->setMillion(cost->getMillion() * f);
	cost->setBillion(cost->getBillion() * f);
	cost->setTrillion(cost->getTrillion() * f);
	cost->setQuadrillion(cost->getQuadrillion() * f);
	cost->setQuintillion(cost->getQuintillion() * f);
	cost->setSextillion(cost->getSextillion() * f);
	cost->setSeptillion(cost->getSeptillion() * f);
	cost->setOctillion(cost->getOctillion() * f);
	cost->setNonillion(cost->getNonillion() * f);
	optimalization1(cost->PLN());
	optimalization2(cost->Nonillion());
}

void Resource::wait(int time, Pocket* pocket)
{
	std::cout << "production time: " << production_time << "time: " << time << "\n";
	try {
		for (int i = PROGRESS; i < time; i++) {
			//std::cout << "i: " << i << "\n";
			if (TERMINATED) {
				PROGRESS = i;
				producting_status_change();
				Sleep(100);
				PROGRESS = 0;
				throw thread_terminated();
			}
			current_time = production_time - (i * 0.1);
			std::cout << current_time << '\n';
			Sleep(100);
		}
		PROGRESS = 0;
		producting_status_change();
		current_time = production_time;
		pocket->transferMoney(earnings);
		pocket->optimalization();
		pocket->getPocketStatus();
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

void Resource::optimalization1(Money* m)
{
	Money* tmp = m;
	int toSend = 0;
	double toDelete = 0;
	while (tmp->getNextMoney() != nullptr) {
		if (tmp->getValue() > 1000) {
			toSend = (int)tmp->getValue() / 1000;
			toDelete = toSend * 1000;
			tmp->setValue(tmp->getValue() - toDelete);
			tmp->getNextMoney()->addMoney(toSend);
		}
		tmp = tmp->getNextMoney();
	}
}

void Resource::optimalization2(Money* m)
{
	Money* tmp = m;
	double mtmp = 0;
	double toSend = 0;
	double toSubstruct = 0;
	while (tmp->getBeforeMoney()->getName() != "before") {
		toSubstruct = tmp->getValue() - (int)tmp->getValue();
		mtmp = tmp->getValue() * 100;
		toSend = (int)mtmp % 100;
		tmp->getBeforeMoney()->addMoney(toSend*10);
		tmp->setValue(tmp->getValue() - toSubstruct);
		tmp = tmp->getBeforeMoney();
	}
}

Resource::Resource()
{
}

Resource::~Resource()
{
}

void Resource::setLvl(double x)
{
	lvl = x;
}

void Resource::setNextResource(Resource* res)
{
	next = res;
}

void Resource::setFactor(double x)
{
	factor = x;
}

void Resource::setProduction_time(double x)
{
	current_time = x;
	production_time = x;
}

bool Resource::producting_status()
{
	return PRODUCTING;
}

double Resource::getLvl()
{
	return lvl;
}

double Resource::getFactor()
{
	return factor;
}

double Resource::getProduction_time()
{
	return production_time;
}

void Resource::setPROGRESS(int x)
{
	PROGRESS = x;
}

void Resource::setBought(bool status)
{
	BOUGHT = status;
}

void Resource::setName(std::string name)
{
	this->name = name;
}

TransferBox* Resource::getEarnings()
{
	return earnings;
}

TransferBox* Resource::getCost()
{
	return cost;
}

void Resource::lvl_up(Pocket* pocket)
{
	try {
		if (!pocket->able_to_take(getCost()))
			throw not_enough_money();
		pocket->takeMoney(getCost());
		lvl++;
		if (production_time > 1 and lvl > 0)
			production_time = production_time - (production_time * (factor - 1));
		else if(lvl > 0)
			production_time = 1;
		earnings_up(factor);
		cost_up(factor);
		std::cout << "LVL UP >> " << getLvl() << "! \n";
		pocket->getPocketStatus();
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

Resource* Resource::getNextResource()
{
	return next;
}

bool Resource::boughtStatus()
{
	return BOUGHT;
}

std::string Resource::getName()
{
	return name;
}

double Resource::getCurrentTime()
{
	return current_time;
}

void Resource::producting_status_change()
{
	PRODUCTING == true ? PRODUCTING = false : PRODUCTING = true;
}

void Resource::product(Pocket* pocket)
{
	try {
		if (PRODUCTING)
			throw thread_is_running();
		producting_status_change();
		int time = production_time * 10;
		std::thread th(&Resource::wait, this, time, pocket);
		th.detach();
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

int Resource::stop()
{
	TERMINATED = true;
	Sleep(100);
	TERMINATED = false;
	return PROGRESS;
}
