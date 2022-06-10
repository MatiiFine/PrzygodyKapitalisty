#include "PocketDisplay.h"

std::string PocketDisplay::setValue(Money* m)
{
	std::string str = "";
	double value = 0;
	int x = 0;
	if(m->getName()=="PLN"){
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

PocketDisplay::PocketDisplay()
{
	pocket = nullptr;
	if (!font.loadFromFile("arial.ttf"))
		std::cout << "Font loading failed" << "\n";
	txt.setFont(font);
	txt.setCharacterSize(46);
	txt.setFillColor(sf::Color(38,166,59,255));
	txt.setOutlineColor(sf::Color::Green);
	txt.setString("super napis");
	txt.setStyle(sf::Text::Bold);
}

PocketDisplay::~PocketDisplay()
{
}

void PocketDisplay::setPosition(sf::Vector2f position)
{
	this->position = position;
}

void PocketDisplay::setPocket(Pocket* pocket)
{
	this->pocket = pocket;
}

sf::Text PocketDisplay::getText()
{
	return txt;
}

void PocketDisplay::update()
{
	std::string str = "Money: ";
	std::string suffix = " ";
	Money* tmp = pocket->Nonillion();
	bool found = false;
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

	txt.setString(str + suffix);
}
