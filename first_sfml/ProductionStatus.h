#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "Resource.h"

class ProductionStatus
{
private:
	int status = 0; // 0 - unable 1 - able to use 2 - running
	sf::RectangleShape statusBox;
	sf::Vector2f position;
public:
	ProductionStatus();
	~ProductionStatus();
	void load(sf::Vector2f);
	void setStatus(int);
	void checkAndSet(Resource* res);
	sf::RectangleShape getStatusBox();
};

