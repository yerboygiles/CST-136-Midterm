//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "Craftable.h"
#include "Stone.h"
#include "Wood.h"
#include "Fiber.h"
#include "Iron.h"
#include "Feather.h"
class House :
	public Craftable
{
public:
	House();
	bool AddInhabitant(string human);
	void RemoveInhabitant(string human);
	void WhoLivesHere();
private:
	uint8 amtinhabitants=0;
	string inhabitants[3];
};

