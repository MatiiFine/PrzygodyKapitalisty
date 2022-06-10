#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>

#include "Pocket.h"
#include "Resource.h"
#include "Saver.h"

class SaveButton
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::RenderWindow* window;
	Saver sv;
public:
	SaveButton();
	~SaveButton();
	sf::Sprite getSprite();
	bool isPressed();
	void interaction(std::string, Pocket*, Resource*);
	void load(sf::RenderWindow*, sf::Vector2f, sf::Texture);
};

