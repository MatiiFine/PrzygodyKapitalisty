#include "ProductionStatus.h"

ProductionStatus::ProductionStatus()
{
}

ProductionStatus::~ProductionStatus()
{
}

void ProductionStatus::load(sf::Vector2f pos)
{
	this->position = pos;
	statusBox.setPosition(this->position);
	statusBox.setSize(sf::Vector2f(25, 25));
	statusBox.setFillColor(sf::Color::Red);
}

void ProductionStatus::setStatus(int x)
{
	this->status = x;
}

void ProductionStatus::checkAndSet(Resource* res)
{
	int lvl = res->getLvl();
	bool prod = res->producting_status();

	if (lvl == 0)
		status = 0;
	if (prod)
		status = 2;
	else if (lvl>0)
		status = 1;


	switch (status)
	{
	case 0:
		statusBox.setFillColor(sf::Color::Red);
		break;
	case 1:
		statusBox.setFillColor(sf::Color::Yellow);
		break;
	case 2:
		statusBox.setFillColor(sf::Color::Green);
		break;
	default:
		break;
	}
}

sf::RectangleShape ProductionStatus::getStatusBox()
{
	return statusBox;
}
