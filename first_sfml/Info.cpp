#include "Info.h"

Info::Info()
{
	window = nullptr;
	status = false;
}

Info::~Info()
{
}

sf::Sprite Info::getSprite()
{
	return sprite;
}

sf::Sprite Info::getInfo()
{
	return info;
}

bool Info::isPressed()
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

void Info::load(sf::RenderWindow* window, sf::Vector2f position, sf::Texture texture)
{
	this->window = window;
	this->position = position;
	this->texture = texture;

	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(this->position);

	info_txt.loadFromFile("graphics/info.png");
	info.setTexture(info_txt);
}

void Info::interaction()
{
	if (status)
		status = false;
	else if (isPressed())
		status = true;
}

bool Info::getStatus()
{
	return status;
}
