#include "SaveButton.h"

SaveButton::SaveButton()
{
	this->window = nullptr;
}

SaveButton::~SaveButton()
{
}

sf::Sprite SaveButton::getSprite()
{
	return sprite;
}

bool SaveButton::isPressed()
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

void SaveButton::interaction(std::string name, Pocket* pocket, Resource*resource)
{
	if (isPressed()) {
		sv.save(name, pocket, resource);
		window->close();
		std::cout << "pressed\n";
	}
}

void SaveButton::load(sf::RenderWindow* window, sf::Vector2f position, sf::Texture texture)
{
	this->window = window;
	this->texture = texture;
	this->position = position;
	sprite.setPosition(this->position);
	sprite.setTexture(this->texture);
}
