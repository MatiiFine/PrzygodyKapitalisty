#include "Lvl_up.h"

Lvl_up::Lvl_up()
{
}

Lvl_up::~Lvl_up()
{
}

sf::Sprite Lvl_up::getSprite()
{
	return sprite;
}

bool Lvl_up::isPressed()
{
	float width = texture.getSize().x;
	float height = texture.getSize().y;
	sf::Vector2f sprite_position = sprite.getPosition();
	float sx = sprite_position.x;
	float sy = sprite_position.y;
	float mx = sf::Mouse::getPosition(*window).x;
	float my = sf::Mouse::getPosition(*window).y;
	if (mx < sx + width and my < sy + height and mx>sx and my>sy)
		return true;
	return false;
}

void Lvl_up::interaction()
{
	try {
		if (isPressed()) {
			if (!this->pocket->able_to_take(this->resource->getCost()))
				throw not_enough_money();
			this->resource->lvl_up(this->pocket);
		}
	}
	catch (std::exception& e) {
		std::cout << e.what() << "\n";
	}
		
}

void Lvl_up::load(sf::RenderWindow* win, Resource* res, Pocket* pock, sf::Vector2f pos)
{
	this->position = pos;
	this->window = win;
	this->resource = res;
	this->pocket = pock;
	texture.loadFromFile("graphics/lvl_up.png");
	sprite.setTexture(texture);
	sprite.setPosition(position);
}
