#include "Saver.h"

void Saver::product(Resource* res, Pocket* pock)
{
	res->product(pock);
}

Saver::Saver()
{
}

Saver::~Saver()
{
}

void Saver::save(std::string name, Pocket* pock, Resource* res)
{
	std::ofstream file;
	file.open(name);
	int progress = 0;

	Money* tmp = pock->PLN();
	//zapis kieszeni
	while (tmp->getNextMoney() != nullptr) {

		file << tmp->getValue() << "\n";
		tmp = tmp->getNextMoney();
	}

	Resource* tmp_res = res;
	while (tmp_res != nullptr) {
		//zapisanie wspolczynnikow
		file << tmp_res->getLvl() << "\n";
		file << tmp_res->getFactor() << "\n";
		file << tmp_res->getProduction_time() << "\n";
		file << tmp_res->boughtStatus() << "\n";
		//zapisanie zarobku
		tmp = tmp_res->getEarnings()->PLN();
		while (tmp->getNextMoney() != nullptr) {
			file << tmp->getValue() << "\n";
			tmp = tmp->getNextMoney();
		}
		//zapisanie kosztu
		tmp = tmp_res->getCost()->PLN();
		while (tmp->getNextMoney() != nullptr) {
			file << tmp->getValue() << "\n";
			tmp = tmp->getNextMoney();
		}
		//zapisywanie progressu
		progress = tmp_res->stop();
		if (progress != 0) {
			file << 1 << "\n"; //oznacza zasob byl uzywany
			file << progress << "\n";
		}
		else {
			file << 0 << "\n";
			file << progress << "\n";
		}

		tmp_res = tmp_res->getNextResource();
	}

	file.close();
}

void Saver::upload(std::string name, Pocket* pock, Resource* res)
{
	std::ifstream file;
	file.open(name);
	Money* tmp = pock->PLN();
	std::string reader = "";
	double double_data = 0;
	int int_data = 0;

	//odczyt kieszeni
	while (tmp->getNextMoney() != nullptr) {
		file >> reader;
		tmp->setValue(std::stoi(reader));
		tmp = tmp->getNextMoney();
	}

	Resource* tmp_res = res;
	while (tmp_res != nullptr) {

		//odczyt poziomu
		file >> double_data;
		tmp_res->setLvl(double_data);
		//odczyt factor
		file >> double_data;
		tmp_res->setFactor(double_data);
		//odczyt production time
		file >> double_data;
		tmp_res->setProduction_time(double_data);
		//odczyt statusu kupienia
		file >> int_data;
		tmp_res->setBought(int_data);

		//odczyt zarobku
		tmp = tmp_res->getEarnings()->PLN();
		while (tmp->getNextMoney() != nullptr) {
			file >> reader;
			tmp->setValue(std::stoi(reader));
			tmp = tmp->getNextMoney();
		}
		//odczyt kosztow
		tmp = tmp_res->getCost()->PLN();
		while (tmp->getNextMoney() != nullptr) {
			file >> reader;
			tmp->setValue(std::stoi(reader));
			tmp = tmp->getNextMoney();
		}
		//odczytanie postepu produkcji
		file >> int_data;
		if (int_data) {
			file >> int_data;
			tmp_res->setPROGRESS(int_data);
			std::thread th(&Saver::product, this, tmp_res, pock);
			th.detach();
		}
		else {
			file >> int_data;
			tmp_res->setPROGRESS(int_data);
		}

		tmp_res = tmp_res->getNextResource();
	}

	file.close();
	std::cout << "upload done" << "\n";
}