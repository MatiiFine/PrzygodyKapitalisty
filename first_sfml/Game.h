#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <Windows.h>
#include <thread>

#include "Sounds.h"
#include "Pocket.h"
#include "Resource.h"
#include "Saver.h"
#include "Button.h"
#include "ProductionStatus.h"
#include "Lvl_up.h"
#include "PocketDisplay.h"
#include "ResInfo.h"
#include "SaveButton.h"
#include "NewGame.h"
#include "Info.h"

class Game
{
private:
	//Variablse
	sf::RenderWindow* window;
	sf::Event event;
	Sounds sounds;
	Pocket* pocket;
	Saver sv;
	Resource* dogs;
	Resource* cherry;
	Resource* pizza;
	Resource* korki;
	Resource* food;
	Resource* zpu;
	Resource* esport;
	Resource* kino;
	Resource* apple;
	Resource* orlen;

	sf::Texture txt;

	Button b1;
	Button b2;
	Button b3;
	Button b4;
	Button b5;
	Button b6;
	Button b7;
	Button b8;
	Button b9;
	Button b10;

	ProductionStatus s1;
	ProductionStatus s2;
	ProductionStatus s3;
	ProductionStatus s4;
	ProductionStatus s5;
	ProductionStatus s6;
	ProductionStatus s7;
	ProductionStatus s8;
	ProductionStatus s9;
	ProductionStatus s10;

	Lvl_up l1;
	Lvl_up l2;
	Lvl_up l3;
	Lvl_up l4;
	Lvl_up l5;
	Lvl_up l6;
	Lvl_up l7;
	Lvl_up l8;
	Lvl_up l9;
	Lvl_up l10;

	PocketDisplay pocketDisplay;
	
	ResInfo dogs_info;
	ResInfo cherry_info;
	ResInfo pizza_info;
	ResInfo korki_info;
	ResInfo food_info;
	ResInfo zpu_info;
	ResInfo esport_info;
	ResInfo kino_info;
	ResInfo apple_info;
	ResInfo orlen_info;

	sf::RectangleShape graySprite;

	SaveButton saveButton;
	NewGame newGame;
	Info info;

	sf::Image icon;

	//Private functions
	void initializeVariables();
	void initializeWindow();
	void initializeResources();
	void threadStart(Resource*);
	void product(Resource*);
public:

	//Constructors/Destructors
	Game();
	~Game();

	//Functions
	void pollEvents();
	void updatingStatus();
	void update();
	void render();

	//Getters
	sf::RenderWindow* getWindow();
};

