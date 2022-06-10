#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Info
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::RenderWindow* window;
	sf::Vector2f position;
	sf::Texture info_txt;
	sf::Sprite info;
	bool status;
public:
	Info();
	~Info();
	sf::Sprite getSprite();
	sf::Sprite getInfo();
	bool isPressed();
	void load(sf::RenderWindow*, sf::Vector2f, sf::Texture);
	void interaction();
	bool getStatus();
};

