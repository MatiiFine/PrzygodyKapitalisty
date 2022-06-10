#include "Pocket.h"

bool Pocket::able_to_take(TransferBox* tf)
{
	int n = 0;
	int toTake = 0;
	int owned = 0;
	Money* tmp = tf->PLN();
	Money* tmp2 = pln;
	while (tmp->getNextMoney() != nullptr) {
		if (tmp->getValue() != tmp2->getValue()) {
			if (tmp2->getValue() > tmp->getValue()) {
				owned += pow(2, n);
			}
			else if (tmp->getValue() > tmp2->getValue()) {
				toTake += pow(2, n);
			}
		}
		n++;
		tmp = tmp->getNextMoney();
		tmp2 = tmp2->getNextMoney();
	}
	if (owned > toTake or owned == toTake)return true;
	else return false;
}

void Pocket::optimalization()
{
	Money* tmp = nonillion;
	double mtmp = 0;
	double toSend = 0;
	double toSubstruct = 0;
	while (tmp->getBeforeMoney()->getName() != "before") {
		toSubstruct = tmp->getValue() - (int)tmp->getValue();
		mtmp = tmp->getValue() * 100;
		toSend = (int)mtmp % 100;
		tmp->getBeforeMoney()->addMoney(toSend);
		tmp->setValue(tmp->getValue() - toSubstruct);
		tmp = tmp->getBeforeMoney();
	}
}

void Pocket::take_from_next(Money* money)
{
	if (money->getNextMoney() != nullptr)
		if (money->getNextMoney()->getValue() - 1 < 0)
			take_from_next(money->getNextMoney());
	money->getNextMoney()->setValue(money->getNextMoney()->getValue() - 1);
	money->setValue(money->getValue() + 1000);
}

Pocket::Pocket()
{
	beforeContainer->setName("before");
	beforeContainer->setValue(0);
	pln->setName("PLN");
	pln->setValue(0);
	pln->setNextMoney(thousand);
	pln->setBeforeMoney(beforeContainer);
	thousand->setName("thousand");
	thousand->setValue(0);
	thousand->setNextMoney(million);
	thousand->setBeforeMoney(pln);
	million->setName("milion");
	million->setValue(0);
	million->setNextMoney(billion);
	million->setBeforeMoney(thousand);
	billion->setName("billion");
	billion->setValue(0);
	billion->setNextMoney(trillion);
	billion->setBeforeMoney(million);
	trillion->setName("trilion");
	trillion->setValue(0);
	trillion->setNextMoney(quadrillion);
	trillion->setBeforeMoney(billion);
	quadrillion->setName("quadrilion");
	quadrillion->setValue(0);
	quadrillion->setNextMoney(quintillion);
	quadrillion->setBeforeMoney(trillion);
	quintillion->setName("quintillion");
	quintillion->setValue(0);
	quintillion->setNextMoney(sextillion);
	quintillion->setBeforeMoney(quadrillion);
	sextillion->setName("sextilion");
	sextillion->setValue(0);
	sextillion->setNextMoney(septillion);
	sextillion->setBeforeMoney(quintillion);
	septillion->setName("septilion");
	septillion->setValue(0);
	septillion->setNextMoney(octillion);
	septillion->setBeforeMoney(quintillion);
	octillion->setName("octilion");
	octillion->setValue(0);
	octillion->setNextMoney(nonillion);
	octillion->setBeforeMoney(septillion);
	nonillion->setName("nonilion");
	nonillion->setValue(0);
	nonillion->setNextMoney(overLimit);
	nonillion->setBeforeMoney(octillion);
	overLimit->setName("overLimit");
	overLimit->setValue(0);
	overLimit->setBeforeMoney(nonillion);
}

Pocket::~Pocket()
{
	delete pln, thousand, million, billion, trillion, quadrillion, quintillion, sextillion, septillion, octillion, nonillion;
}

void Pocket::transferMoney(TransferBox* transferBox)
{
	pln->addMoney(transferBox->getPLN());
	thousand->addMoney(transferBox->getThousand());
	million->addMoney(transferBox->getMillion());
	billion->addMoney(transferBox->getBillion());
	trillion->addMoney(transferBox->getTrillion());
	quadrillion->addMoney(transferBox->getQuadrillion());
	quintillion->addMoney(transferBox->getQuintillion());
	sextillion->addMoney(transferBox->getSextillion());
	septillion->addMoney(transferBox->getSeptillion());
	octillion->addMoney(transferBox->getOctillion());
	nonillion->addMoney(transferBox->getNonillion());
}

void Pocket::takeMoney(TransferBox* transferBox)
{
	try {
		if (!able_to_take(transferBox))
			throw not_enough_money();
		Money* tmp = transferBox->PLN();
		Money* tmp2 = pln;
		while (tmp != nullptr)
		{
			if (tmp2->getValue() - tmp->getValue() < 0)
				take_from_next(tmp2);
			tmp2->setValue(tmp2->getValue() - tmp->getValue());
			tmp = tmp->getNextMoney();
			tmp2 = tmp2->getNextMoney();
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
}

void Pocket::getPocketStatus()
{
	std::cout << pln->getValue() << " " << pln->getName() << " "
		<< thousand->getValue() << " " << thousand->getName() << " "
		<< million->getValue() << " " << million->getName() << " "
		<< billion->getValue() << " " << billion->getName() << " "
		<< trillion->getValue() << " " << trillion->getName() << " "
		<< quadrillion->getValue() << " " << quadrillion->getName() << " "
		<< quintillion->getValue() << " " << quintillion->getName() << " "
		<< sextillion->getValue() << " " << sextillion->getName() << " "
		<< septillion->getValue() << " " << septillion->getName() << " "
		<< octillion->getValue() << " " << octillion->getName() << " "
		<< nonillion->getValue() << " " << nonillion->getName() << "\n";
}

int Pocket::getPLN()
{
	return pln->getValue();
}

int Pocket::getThousand()
{
	return thousand->getValue();
}

int Pocket::getMillion()
{
	return million->getValue();
}

int Pocket::getBillion()
{
	return billion->getValue();
}

int Pocket::getTrillion()
{
	return trillion->getValue();
}

int Pocket::getQuadrillion()
{
	return quadrillion->getValue();
}

int Pocket::getQuintillion()
{
	return quintillion->getValue();
}

int Pocket::getSextillion()
{
	return sextillion->getValue();
}

int Pocket::getSeptillion()
{
	return septillion->getValue();
}

int Pocket::getOctillion()
{
	return octillion->getValue();
}

int Pocket::getNonillion()
{
	return nonillion->getValue();
}

std::string Pocket::namePln()
{
	return pln->getName();
}

std::string Pocket::nameThousand()
{
	return thousand->getName();
}

std::string Pocket::nameMillion()
{
	return million->getName();
}

std::string Pocket::nameBillion()
{
	return billion->getName();
}

std::string Pocket::nameTrillion()
{
	return trillion->getName();
}

std::string Pocket::nameQuadrillion()
{
	return quadrillion->getName();
}

std::string Pocket::nameQuintillion()
{
	return quintillion->getName();
}

std::string Pocket::nameSextillion()
{
	return sextillion->getName();
}

std::string Pocket::nameSeptillion()
{
	return septillion->getName();
}

std::string Pocket::nameOctillion()
{
	return octillion->getName();
}

std::string Pocket::nameNonillion()
{
	return nonillion->getName();
}

Money* Pocket::PLN()
{
	return pln;
}

Money* Pocket::Thousand()
{
	return thousand;
}

Money* Pocket::Million()
{
	return million;
}

Money* Pocket::Billion()
{
	return billion;
}

Money* Pocket::Trillion()
{
	return trillion;
}

Money* Pocket::Quadrillion()
{
	return quadrillion;
}

Money* Pocket::Quintillion()
{
	return quintillion;
}

Money* Pocket::Sextillion()
{
	return sextillion;
}

Money* Pocket::Septillion()
{
	return septillion;
}

Money* Pocket::Octillion()
{
	return octillion;
}

Money* Pocket::Nonillion()
{
	return nonillion;
}