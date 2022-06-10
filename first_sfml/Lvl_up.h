#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "Resource.h"
#include "Pocket.h"

class Lvl_up
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::RenderWindow* window;
	Resource* resource;
	Pocket* pocket;

public:
	Lvl_up();
	~Lvl_up();
	sf::Sprite getSprite();
	bool isPressed();
	void interaction();
	void load(sf::RenderWindow*, Resource*, Pocket*, sf::Vector2f);
};

