#include "NewGame.h"

NewGame::NewGame()
{
}

NewGame::~NewGame()
{
}

void NewGame::load(sf::RenderWindow* window, sf::Vector2f position, sf::Texture texture, Pocket* pocket, Resource* resource)
{
	this->window = window;
	this->position = position;
	this->texture = texture;
	this->pocket = pocket;
	this->resource = resource;

	sprite.setTexture(this->texture);
	sprite.setPosition(this->position);
}

bool NewGame::isPressed()
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

void NewGame::interaction()
{
	if (isPressed()) {
		Resource* tmp = resource;
		while (tmp != nullptr) {
			tmp->stop();
			tmp = tmp->getNextResource();
		}
		sv.upload("save2.txt", pocket, resource);
	}
}

sf::Sprite NewGame::getSprite()
{
	return sprite;
}
