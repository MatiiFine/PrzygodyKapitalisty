#include "Sounds.h"

//Constructors/Destructors
Sounds::Sounds()
{
	this->initSoundtrack();
	this->mutedStatus = false;
}

Sounds::~Sounds()
{

}

//Functions
void Sounds::soundtrackVolumeUp()
{
	if (mutedStatus) {
		mutedStatus = false;
		std::cout << "Sound unmuted" << std::endl;
		if (remembered + 1.f <= 100)
			soundtrack.setVolume(remembered + 1.f);
		else if (remembered > 99)
			soundtrack.setVolume(100);
	}
	else {
		if (soundtrack.getVolume() + 1.f <= 100)
			soundtrack.setVolume(soundtrack.getVolume() + 1.f);
		else if (soundtrack.getVolume() > 99)
			soundtrack.setVolume(100);
	}
}

void Sounds::soundtrackVolumeDown()
{
	if (mutedStatus) {
		mutedStatus = false;
		std::cout << "Sound unmuted" << std::endl;
		if (remembered - 1.f >= 0)
			soundtrack.setVolume(remembered - 1.f);
		else if (remembered < 1)
			soundtrack.setVolume(0);
	}
	else {
		if (soundtrack.getVolume() - 1.f >= 0)
			soundtrack.setVolume(soundtrack.getVolume() - 1.f);
		else if (soundtrack.getVolume() < 1)
			soundtrack.setVolume(0);
	}
}

void Sounds::mute()
{
	if (mutedStatus) {
		soundtrack.setVolume(remembered);
		mutedStatus = false;
		std::cout << "Sound unmuted" << std::endl;
	}
	else {
		remembered = soundtrack.getVolume();
		soundtrack.setVolume(0.f);
		mutedStatus = true;
		std::cout << "Sound muted" << std::endl;
	}
}

float Sounds::getSoundtrackVolume()
{
	return soundtrack.getVolume();
}

void Sounds::initSoundtrack()
{
	if (!soundtrack.openFromFile("music.ogg"))
		return;
	soundtrack.play();
	soundtrack.setLoop(true);
	soundtrack.setVolume(35);
}
