#include "TransferBox.h"

TransferBox::TransferBox()
{
	pln->setNextMoney(thousand);
	thousand->setNextMoney(million);
	million->setNextMoney(billion);
	billion->setNextMoney(trillion);
	trillion->setNextMoney(quadrillion);
	quadrillion->setNextMoney(quintillion);
	quintillion->setNextMoney(sextillion);
	sextillion->setNextMoney(septillion);
	septillion->setNextMoney(octillion);
	octillion->setNextMoney(nonillion);
	nonillion->setNextMoney(over_limit);

	before->setBeforeMoney(nullptr);
	pln->setBeforeMoney(before);
	thousand->setBeforeMoney(pln);
	million->setBeforeMoney(thousand);
	billion->setBeforeMoney(million);
	trillion->setBeforeMoney(billion);
	quadrillion->setBeforeMoney(trillion);
	quintillion->setBeforeMoney(quadrillion);
	sextillion->setBeforeMoney(quintillion);
	septillion->setBeforeMoney(sextillion);
	octillion->setBeforeMoney(septillion);
	nonillion->setBeforeMoney(octillion);
}

TransferBox::~TransferBox()
{
	delete pln, thousand, million, billion, trillion, quadrillion, quintillion, sextillion, septillion, octillion, nonillion;
}

//void TransferBox::optimalization(Money* m)
//{
//	if (m->getNextMoney() != nullptr) {
//		if (m->getValue() > 1000) {
//			m->getNextMoney()->addMoney((int)m->getValue() / 1000);
//			m->setValue((int)m->getValue() % 1000);
//		}
//		optimalization(m->getNextMoney());
//	}
//}

void TransferBox::getStatus()
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

double TransferBox::getPLN()
{
	return pln->getValue();
}

double TransferBox::getThousand()
{
	return thousand->getValue();
}

double TransferBox::getMillion()
{
	return million->getValue();
}

double TransferBox::getBillion()
{
	return billion->getValue();
}

double TransferBox::getTrillion()
{
	return trillion->getValue();
}

double TransferBox::getQuadrillion()
{
	return quadrillion->getValue();
}

double TransferBox::getQuintillion()
{
	return quintillion->getValue();
}

double TransferBox::getSextillion()
{
	return sextillion->getValue();
}

double TransferBox::getSeptillion()
{
	return septillion->getValue();
}

double TransferBox::getOctillion()
{
	return octillion->getValue();
}

double TransferBox::getNonillion()
{
	return nonillion->getValue();
}

Money* TransferBox::PLN()
{
	return pln;
}

Money* TransferBox::Thousand()
{
	return thousand;
}

Money* TransferBox::Million()
{
	return million;
}

Money* TransferBox::Billion()
{
	return billion;
}

Money* TransferBox::Trillion()
{
	return trillion;
}

Money* TransferBox::Quadrillion()
{
	return quadrillion;
}

Money* TransferBox::Quintillion()
{
	return quintillion;
}

Money* TransferBox::Sextillion()
{
	return sextillion;
}

Money* TransferBox::Septillion()
{
	return septillion;
}

Money* TransferBox::Octillion()
{
	return octillion;
}

Money* TransferBox::Nonillion()
{
	return nonillion;
}

void TransferBox::setPLN(double value)
{
	pln->setValue(value);
}

void TransferBox::setThousand(double value)
{
	thousand->setValue(value);
}

void TransferBox::setMillion(double value)
{
	million->setValue(value);
}

void TransferBox::setBillion(double value)
{
	billion->setValue(value);
}

void TransferBox::setTrillion(double value)
{
	trillion->setValue(value);
}

void TransferBox::setQuadrillion(double value)
{
	quadrillion->setValue(value);
}

void TransferBox::setQuintillion(double value)
{
	quintillion->setValue(value);
}

void TransferBox::setSextillion(double value)
{
	sextillion->setValue(value);
}

void TransferBox::setSeptillion(double value)
{
	septillion->setValue(value);
}

void TransferBox::setOctillion(double value)
{
	octillion->setValue(value);
}

void TransferBox::setNonillion(double value)
{
	nonillion->setValue(value);
}
