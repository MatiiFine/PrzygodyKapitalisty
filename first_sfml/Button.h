#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <Windows.h>

#include "thread_is_running.h"
#include "not_enough_lvl.h"
#include "Resource.h"
#include "Pocket.h"

class Button
{
private:
	sf::Texture texture;
	sf::Texture pressed;
	sf::Vector2f position;
	sf::Sprite sprite;
	sf::RenderWindow* window;
	bool THREAD = false;
	void change_thread_status();
	void wait();
public:
	Button();
	~Button();
	sf::Sprite getSprite();
	bool isPressed();
	void load(sf::RenderWindow*, sf::Texture, sf::Vector2f);
	void interaction(Resource*, Pocket*);
};

