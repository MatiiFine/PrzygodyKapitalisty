#pragma once
#include <SFML/Audio.hpp>
#include <iostream>
class Sounds
{
private:
	//Vars
	sf::Music soundtrack;
	float remembered;
	bool mutedStatus;

	//init
	void initSoundtrack();
public:
	//Constructors/Destructors
	Sounds();
	~Sounds();

	//Functions
	void soundtrackVolumeUp();
	void soundtrackVolumeDown();
	void mute();

	//Getters
	float getSoundtrackVolume();
};

