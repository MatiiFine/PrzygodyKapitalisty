#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Saver.h"
#include "Pocket.h"
#include "Resource.h"

class NewGame
{
private:
	Pocket* pocket;
	Resource* resource;
	Saver sv;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::RenderWindow* window;
public:
	NewGame();
	~NewGame();
	void load(sf::RenderWindow*, sf::Vector2f, sf::Texture, Pocket*, Resource*);
	bool isPressed();
	void interaction();
	sf::Sprite getSprite();
};

