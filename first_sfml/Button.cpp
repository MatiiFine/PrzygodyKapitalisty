#include "Button.h"

void Button::wait()
{
	Sleep(800);
	change_thread_status();
	sprite.setTexture(texture);
}

void Button::change_thread_status()
{
	THREAD == true ? THREAD = false : THREAD = true;
}

Button::Button()
{
}

Button::~Button()
{
}

sf::Sprite Button::getSprite()
{
	return sprite;
}

bool Button::isPressed()
{
	float width = texture.getSize().x;
	float height = texture.getSize().y;
	sf::Vector2f sprite_position = sprite.getPosition();
	float sx = sprite_position.x;
	float sy = sprite_position.y;
	float mx = sf::Mouse::getPosition(*window).x;
	float my = sf::Mouse::getPosition(*window).y;
	if (mx < sx + width and my < sy+height and mx>sx and my>sy)
		return true;
	return false;
}

void Button::load(sf::RenderWindow* window, sf::Texture texture, sf::Vector2f pos)
{
	this->window = window;
	this->texture = texture;
	this->position = pos;
	sprite.setPosition(this->position);
	sprite.setTexture(this->texture);
	this->pressed.loadFromFile("graphics/pressed1.png");
}

void Button::interaction(Resource* res, Pocket* pock)
{
	if (isPressed()) {
		try {
			if (res->getLvl() == 0)
				throw not_enough_lvl();
			if (THREAD)
				throw thread_is_running();
			change_thread_status();
			sprite.setTexture(pressed);
			std::thread th(&Button::wait, this);
			th.detach();
			if (res->producting_status())
				throw thread_is_running();
			res->product(pock);
		}
		catch (std::exception& e) {
			std::cout << e.what() << "\n";
		}
	}
}
