#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <thread>

#include "Pocket.h"
#include "Money.h"
#include "Resource.h"

class Saver
{
private:
	void product(Resource*, Pocket*);
public:
	Saver();
	~Saver();
	void save(std::string, Pocket*, Resource*);
	void upload(std::string, Pocket*, Resource*);
};

