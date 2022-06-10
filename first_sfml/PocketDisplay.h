#pragma once
#include <iostream>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Pocket.h"
#include "Money.h"

class PocketDisplay
{
private:
	sf::Text txt;
	sf::Vector2f position;
	sf::Font font;
	Pocket* pocket;
	std::string setValue(Money*);
public:
	PocketDisplay();
	~PocketDisplay();
	void setPosition(sf::Vector2f);
	void setPocket(Pocket*);
	sf::Text getText();
	void update();
};

