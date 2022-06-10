#pragma once
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resource.h"
#include "TransferBox.h"
#include "Money.h"

class ResInfo
{
private:
	Resource* resource;
	sf::Vector2f position_name;
	sf::Vector2f position_earnings;
	sf::Vector2f position_cost;
	sf::Vector2f position_time;
	sf::Text name;
	sf::Text earnings;
	sf::Text cost;
	sf::Text time;
	sf::Font font;
	int font_size;
	std::string name_t;
	std::string earnings_t;
	std::string cost_t;
	std::string time_t;

	std::string moneyToStr(TransferBox*);
	std::string doubleToStr(double);
	std::string setValue(Money*);
public:
	ResInfo();
	~ResInfo();
	void update();
	void load(Resource*, sf::Vector2f);
	sf::Text getName();
	sf::Text getEarnings();
	sf::Text getCost();
	sf::Text getTime();
};

