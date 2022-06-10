#include "ResInfo.h"

std::string ResInfo::moneyToStr(TransferBox* tb)
{
	std::string str = "";
	Money* tmp = tb->Nonillion();
	bool found = false;
	std::string suffix = " ";

	while (tmp->getBeforeMoney() != nullptr) {
		if (tmp->getValue() > 0) {
			found = true;
			str += setValue(tmp);
			suffix += tmp->getName();
			if (tmp->getBeforeMoney() != nullptr) {
				tmp = tmp->getBeforeMoney();
				if (tmp->getValue() > 0 and tmp->getValue() < 10) {
					str += ".00";
					str += setValue(tmp);
				}
				else if (tmp->getValue() > 0 and tmp->getValue() < 100) {
					str += ".0";
					str += setValue(tmp);
				}
				else {
					if (tmp->getName() != "before") {
						str += ".";
						str += setValue(tmp);
					}
				}
				break;
			}
		}
		
		tmp = tmp->getBeforeMoney();
	}

	if (!found) {
		str += "0";
		suffix += "PLN";
	}

	return (str + suffix);
}

std::string ResInfo::doubleToStr(double value) 
{
	std::string str = "";
	str = std::to_string((int)value);
	str += ",";
	int dec = (int)(value *= 10);
	str += std::to_string(dec % 10);
	return str;
}

std::string ResInfo::setValue(Money* m)
{
	std::string str = "";
	double value = 0;
	int x = 0;
	if (m->getName() == "PLN") {
		value = m->getValue();
		value *= 100;
		x = (int)value;
		str = std::to_string(x / 100);
		if (x % 100 > 0) {
			str += ",";
			str += std::to_string(x % 100);
		}
	}
	else
		str = std::to_string((int)m->getValue());
	return str;
}

ResInfo::ResInfo()
{
	resource = nullptr;
	font_size = 0;
	name_t = "";
	earnings_t = "";
	cost_t = "";
	time_t = "";

	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Font loading failed" << "\n";

	name.setFont(font);
	earnings.setFont(font);
	cost.setFont(font);
	time.setFont(font);

	font_size = 15;
	name.setCharacterSize(font_size);
	earnings.setCharacterSize(font_size);
	cost.setCharacterSize(font_size);
	time.setCharacterSize(font_size);

	name.setFillColor(sf::Color(0, 102, 255, 255));
	earnings.setFillColor(sf::Color(6, 124, 5, 255));
	cost.setFillColor(sf::Color(204, 0, 0, 255));
	time.setFillColor(sf::Color(255, 204, 0, 255));
}

ResInfo::~ResInfo()
{
}

void ResInfo::update()
{
	earnings_t = "Zysk: " + moneyToStr(resource->getEarnings());
	cost_t = "Koszt LVL up: " + moneyToStr(resource->getCost());
	time_t = "Czas produkcji: " + doubleToStr(resource->getCurrentTime());

	name.setString(name_t);
	earnings.setString(earnings_t);
	cost.setString(cost_t);
	time.setString(time_t);
}

void ResInfo::load(Resource* resource, sf::Vector2f position)
{
	this->resource = resource;
	this->position_name = position;
	std::cout << this->position_name.x << " " << this->position_name.y << "\n";
	position_earnings = sf::Vector2f(position_name.x, position_name.y + 30);
	position_cost = sf::Vector2f(position_earnings.x, position_earnings.y + 30);
	position_time = sf::Vector2f(position_cost.x, position_cost.y + 30);

	name.setPosition(position_name);
	earnings.setPosition(position_earnings);
	cost.setPosition(position_cost);
	time.setPosition(position_time);

	name_t = resource->getName();
	earnings_t = "Zysk: " + moneyToStr(resource->getEarnings());
	cost_t = "Koszt LVL up: " + moneyToStr(resource->getCost());
	time_t = "Czas produkcji: " + doubleToStr(resource->getCurrentTime());

	name.setString(name_t);
	earnings.setString(earnings_t);
	cost.setString(cost_t);
	time.setString(time_t);
}

sf::Text ResInfo::getName()
{
	return name;
}

sf::Text ResInfo::getEarnings()
{
	return earnings;
}

sf::Text ResInfo::getCost()
{
	return cost;
}

sf::Text ResInfo::getTime()
{
	return time;
}
