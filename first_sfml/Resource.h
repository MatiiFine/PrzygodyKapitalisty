#pragma once
#include <iostream>
#include <Windows.h>
#include <thread>
#include "TransferBox.h"
#include "Pocket.h"
#include "not_enough_money.h"
#include "thread_is_running.h"
#include "thread_terminated.h"

class Resource
{
private:
	double lvl;
	double factor;
	double production_time;
	double current_time;
	bool PRODUCTING;
	bool TERMINATED;
	bool BOUGHT;
	int PROGRESS;
	TransferBox* earnings = new TransferBox();
	TransferBox* cost = new TransferBox();
	Resource* next;
	std::string name;

	void earnings_up(double);
	void cost_up(double);
	void wait(int,Pocket*);
	void optimalization1(Money*);
	void optimalization2(Money*s);
public:
	Resource();
	~Resource();
	//setters
	void setNextResource(Resource*);
	void setLvl(double);
	void setFactor(double);
	void setProduction_time(double);
	void setPROGRESS(int);
	void setBought(bool);
	void setName(std::string);
	//getters
	bool producting_status();
	double getLvl();
	double getFactor();
	double getProduction_time();
	TransferBox* getEarnings();
	TransferBox* getCost();
	Resource* getNextResource();
	bool boughtStatus();
	std::string getName();
	double getCurrentTime();
	//functions
	void lvl_up(Pocket*);
	void producting_status_change();
	void product(Pocket*);
	int stop();
};

