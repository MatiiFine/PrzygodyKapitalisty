#include "Game.h"

//Constructors / Destructors
Game::Game()
{
	this->initializeVariables();
	this->initializeWindow();
	this->initializeResources();
}

Game::~Game()
{
	delete this->window;
}

//Private functions

void Game::initializeVariables()
{
	this->window = nullptr;
	pocket = new Pocket();
	dogs = new Resource();
	cherry = new Resource();
	pizza = new Resource();
	korki = new Resource();
	food = new Resource();
	zpu = new Resource();
	esport = new Resource();
	kino = new Resource();
	apple = new Resource();
	orlen = new Resource();
}

void Game::initializeWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(1500, 800), "Przygody Kapitalisty", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initializeResources()
{
	dogs->setLvl(1);
	dogs->setFactor(1.07);
	dogs->getEarnings()->setPLN(4);
	dogs->getCost()->setPLN(8);
	dogs->setProduction_time(1);
	dogs->setNextResource(cherry);
	dogs->setName("Wyprowadzanie psow");

	cherry->setLvl(0);
	cherry->setFactor(1.15);
	cherry->getEarnings()->setPLN(20);
	cherry->getCost()->setPLN(60);
	cherry->setProduction_time(3);
	cherry->setNextResource(pizza);
	cherry->setName("Zbieranie wisni");

	pizza->setLvl(0);
	pizza->setFactor(1.14);
	pizza->getEarnings()->setPLN(90);
	pizza->getCost()->setPLN(720);
	pizza->setProduction_time(6);
	pizza->setNextResource(korki);
	pizza->setName("Rozwozenie pizzy");

	korki->setLvl(0);
	korki->setFactor(1.13);
	korki->getEarnings()->setPLN(360);
	korki->getCost()->setThousand(8);
	korki->getCost()->setPLN(640);
	korki->setProduction_time(24);
	korki->setNextResource(food);
	korki->setName("Udzielanie korepetycji");

	food->setLvl(0);
	food->setFactor(1.12);
	food->getEarnings()->setThousand(2);
	food->getEarnings()->setPLN(137);
	food->getCost()->setThousand(103);
	food->getCost()->setPLN(680);
	food->setProduction_time(24);
	food->setNextResource(zpu);
	food->setName("Foodtruck");

	zpu->setLvl(0);
	zpu->setFactor(1.11);
	zpu->getEarnings()->setThousand(6);
	zpu->getEarnings()->setPLN(480);
	zpu->getCost()->setMillion(1);
	zpu->getCost()->setThousand(224);
	zpu->getCost()->setPLN(160);
	zpu->setProduction_time(96);
	zpu->setNextResource(esport);
	zpu->setName("Ubezpieczalnia");

	esport->setLvl(0);
	esport->setFactor(1.10);
	esport->getEarnings()->setThousand(19);
	esport->getEarnings()->setPLN(440);
	esport->getCost()->setMillion(14);
	esport->getCost()->setThousand(929);
	esport->getCost()->setPLN(920);
	esport->setProduction_time(384);
	esport->setNextResource(kino);
	esport->setName("Dru¿yna e-sportowa");

	kino->setLvl(0);
	kino->setFactor(1.09);
	kino->getEarnings()->setThousand(58);
	kino->getEarnings()->setPLN(320);
	kino->getCost()->setMillion(179);
	kino->getCost()->setThousand(159);
	kino->getCost()->setPLN(040);
	kino->setProduction_time(1536);
	kino->setNextResource(apple);
	kino->setName("Kino");

	apple->setLvl(0);
	apple->setFactor(1.08);
	apple->getEarnings()->setThousand(174);
	apple->getEarnings()->setPLN(960);
	apple->getCost()->setBillion(2);
	apple->getCost()->setMillion(149);
	apple->getCost()->setThousand(908);
	apple->getCost()->setPLN(480);
	apple->setProduction_time(6144);
	apple->setNextResource(orlen);
	apple->setName("Firma komputerowa");

	orlen->setLvl(0);
	orlen->setFactor(1.07);
	orlen->getEarnings()->setThousand(804);
	orlen->getEarnings()->setPLN(816);
	orlen->getCost()->setBillion(25);
	orlen->getCost()->setMillion(798);
	orlen->getCost()->setThousand(901);
	orlen->getCost()->setPLN(760);
	orlen->setProduction_time(36864);
	orlen->setNextResource(nullptr);
	orlen->setName("Koncenr naftowy");

	txt.loadFromFile("graphics/dogs.png");
	b1.load(this->window, txt,sf::Vector2f(0,150));
	txt.loadFromFile("graphics/cherry.png");
	b2.load(this->window, txt, sf::Vector2f(0, 250));
	txt.loadFromFile("graphics/pizza.png");
	b3.load(this->window, txt, sf::Vector2f(0, 350));
	txt.loadFromFile("graphics/korki.png");
	b4.load(this->window, txt, sf::Vector2f(0, 450));
	txt.loadFromFile("graphics/food_truck.png");
	b5.load(this->window, txt, sf::Vector2f(0, 550));
	txt.loadFromFile("graphics/zpu.png");
	b6.load(this->window, txt, sf::Vector2f(500, 150));
	txt.loadFromFile("graphics/esport.png");
	b7.load(this->window, txt, sf::Vector2f(500, 250));
	txt.loadFromFile("graphics/kino.png");
	b8.load(this->window, txt, sf::Vector2f(500, 350));
	txt.loadFromFile("graphics/apple.png");
	b9.load(this->window, txt, sf::Vector2f(500, 450));
	txt.loadFromFile("graphics/orlen.png");
	b10.load(this->window, txt, sf::Vector2f(500, 550));

	s1.load(sf::Vector2f(329, 150));
	s2.load(sf::Vector2f(329, 250));
	s3.load(sf::Vector2f(329, 350));
	s4.load(sf::Vector2f(329, 450));
	s5.load(sf::Vector2f(329, 550));
	s6.load(sf::Vector2f(829, 150));
	s7.load(sf::Vector2f(829, 250));
	s8.load(sf::Vector2f(829, 350));
	s9.load(sf::Vector2f(829, 450));
	s10.load(sf::Vector2f(829, 550));
	
	l1.load(this->window, dogs, pocket, sf::Vector2f(329, 180));
	l2.load(this->window, cherry, pocket, sf::Vector2f(329, 280));
	l3.load(this->window, pizza, pocket, sf::Vector2f(329, 380));
	l4.load(this->window, korki, pocket, sf::Vector2f(329, 480));
	l5.load(this->window, food, pocket, sf::Vector2f(329, 580));
	l6.load(this->window, zpu, pocket, sf::Vector2f(829, 180));
	l7.load(this->window, esport, pocket, sf::Vector2f(829, 280));
	l8.load(this->window, kino, pocket, sf::Vector2f(829, 380));
	l9.load(this->window, apple, pocket, sf::Vector2f(829, 480));
	l10.load(this->window, orlen, pocket, sf::Vector2f(829, 580));

	pocketDisplay.setPosition(sf::Vector2f(0, 0));
	pocketDisplay.setPocket(pocket);

	dogs_info.load(dogs, sf::Vector2f(900, 0));
	cherry_info.load(cherry, sf::Vector2f(900, 150));
	pizza_info.load(pizza, sf::Vector2f(900, 300));
	korki_info.load(korki, sf::Vector2f(900, 450));
	food_info.load(food, sf::Vector2f(900, 600));
	zpu_info.load(zpu, sf::Vector2f(1200, 0));
	esport_info.load(esport, sf::Vector2f(1200, 150));
	kino_info.load(kino, sf::Vector2f(1200, 300));
	apple_info.load(apple, sf::Vector2f(1200, 450));
	orlen_info.load(orlen, sf::Vector2f(1200, 600));

	graySprite.setFillColor(sf::Color(145,144,145,255));
	graySprite.setPosition(sf::Vector2f(880, 0));
	graySprite.setSize(sf::Vector2f(520, 750));

	txt.loadFromFile("graphics/save_button.png");
	saveButton.load(window, sf::Vector2f(0, 700), txt);
	txt.loadFromFile("graphics/new_game.png");
	newGame.load(window, sf::Vector2f(150, 700), txt, pocket, dogs);
	txt.loadFromFile("graphics/info_icon.png");
	info.load(window, sf::Vector2f(300, 700), txt);

	icon.loadFromFile("graphics/icon.png");
	window->setIcon(91, 97, icon.getPixelsPtr());

	sv.upload("save1.txt", pocket, dogs);
}

void Game::product(Resource* res) {
	res->product(pocket);
}

void Game::threadStart(Resource* res) {
	std::thread th(&Game::product, this, res);
	th.detach();
}

//Public Functions
void Game::update()
{
	this->pollEvents();
	this->updatingStatus();
}

void Game::render()
{
	this->window->clear(sf::Color::White); //Clear the frame

	//Draw
	this->window->draw(graySprite);

	this->window->draw(b1.getSprite());
	this->window->draw(b2.getSprite());
	this->window->draw(b3.getSprite());
	this->window->draw(b4.getSprite());
	this->window->draw(b5.getSprite());
	this->window->draw(b6.getSprite());
	this->window->draw(b7.getSprite());
	this->window->draw(b8.getSprite());
	this->window->draw(b9.getSprite());
	this->window->draw(b10.getSprite());

	this->window->draw(s1.getStatusBox());
	this->window->draw(s2.getStatusBox());
	this->window->draw(s3.getStatusBox());
	this->window->draw(s4.getStatusBox());
	this->window->draw(s5.getStatusBox());
	this->window->draw(s6.getStatusBox());
	this->window->draw(s7.getStatusBox());
	this->window->draw(s8.getStatusBox());
	this->window->draw(s9.getStatusBox());
	this->window->draw(s10.getStatusBox());

	this->window->draw(l1.getSprite());
	this->window->draw(l2.getSprite());
	this->window->draw(l3.getSprite());
	this->window->draw(l4.getSprite());
	this->window->draw(l5.getSprite());
	this->window->draw(l6.getSprite());
	this->window->draw(l7.getSprite());
	this->window->draw(l8.getSprite());
	this->window->draw(l9.getSprite());
	this->window->draw(l10.getSprite());

	this->window->draw(pocketDisplay.getText());

	this->window->draw(dogs_info.getName());
	this->window->draw(dogs_info.getEarnings());
	this->window->draw(dogs_info.getCost());
	this->window->draw(dogs_info.getTime());

	this->window->draw(cherry_info.getName());
	this->window->draw(cherry_info.getEarnings());
	this->window->draw(cherry_info.getCost());
	this->window->draw(cherry_info.getTime());

	this->window->draw(pizza_info.getName());
	this->window->draw(pizza_info.getEarnings());
	this->window->draw(pizza_info.getCost());
	this->window->draw(pizza_info.getTime());

	this->window->draw(korki_info.getName());
	this->window->draw(korki_info.getEarnings());
	this->window->draw(korki_info.getCost());
	this->window->draw(korki_info.getTime());

	this->window->draw(food_info.getName());
	this->window->draw(food_info.getEarnings());
	this->window->draw(food_info.getCost());
	this->window->draw(food_info.getTime());

	this->window->draw(zpu_info.getName());
	this->window->draw(zpu_info.getEarnings());
	this->window->draw(zpu_info.getCost());
	this->window->draw(zpu_info.getTime());

	this->window->draw(esport_info.getName());
	this->window->draw(esport_info.getEarnings());
	this->window->draw(esport_info.getCost());
	this->window->draw(esport_info.getTime());

	this->window->draw(apple_info.getName());
	this->window->draw(apple_info.getEarnings());
	this->window->draw(apple_info.getCost());
	this->window->draw(apple_info.getTime());

	this->window->draw(kino_info.getName());
	this->window->draw(kino_info.getEarnings());
	this->window->draw(kino_info.getCost());
	this->window->draw(kino_info.getTime());

	this->window->draw(orlen_info.getName());
	this->window->draw(orlen_info.getEarnings());
	this->window->draw(orlen_info.getCost());
	this->window->draw(orlen_info.getTime());

	this->window->draw(saveButton.getSprite());
	this->window->draw(newGame.getSprite());
	this->window->draw(info.getSprite());
	if (info.getStatus())
		this->window->draw(info.getInfo());

	this->window->display(); //draw frame
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			switch (event.key.code)
			{
			case sf::Keyboard::P:
				sounds.soundtrackVolumeUp();
				std::cout << "Volume: " << sounds.getSoundtrackVolume() << std::endl;
				break;
			case sf::Keyboard::L:
				sounds.soundtrackVolumeDown();
				std::cout << "Volume: " << sounds.getSoundtrackVolume() << std::endl;
				break;
			case sf::Keyboard::M:
				sounds.mute();
				break;
			default:
				break;
			}
			break;
		case sf::Event::MouseButtonPressed:
			b1.interaction(dogs,pocket);
			b2.interaction(cherry,pocket);
			b3.interaction(pizza,pocket);
			b4.interaction(korki,pocket);
			b5.interaction(food,pocket);
			b6.interaction(zpu,pocket);
			b7.interaction(esport,pocket);
			b8.interaction(kino,pocket);
			b9.interaction(apple,pocket);
			b10.interaction(orlen,pocket);

			l1.interaction();
			l2.interaction();
			l3.interaction();
			l4.interaction();
			l5.interaction();
			l6.interaction();
			l7.interaction();
			l8.interaction();
			l9.interaction();
			l10.interaction();

			saveButton.interaction("save1.txt", pocket, dogs);
			newGame.interaction();
			info.interaction();
			break;
		deafult:
			break;
		}
	}
}


//Getters
sf::RenderWindow* Game::getWindow() {
	return this->window;
}

void Game::updatingStatus()
{
	s1.checkAndSet(dogs);
	s2.checkAndSet(cherry);
	s3.checkAndSet(pizza);
	s4.checkAndSet(korki);
	s5.checkAndSet(food);
	s6.checkAndSet(zpu);
	s7.checkAndSet(esport);
	s8.checkAndSet(kino);
	s9.checkAndSet(apple);
	s10.checkAndSet(orlen);

	pocketDisplay.update();

	dogs_info.update();
	cherry_info.update();
	pizza_info.update();
	korki_info.update();
	food_info.update();
	zpu_info.update();
	esport_info.update();
	kino_info.update();
	apple_info.update();
	orlen_info.update();
}
