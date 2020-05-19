//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "Harvestable.h"
#include "Fauna.h"
#include "Meat.h"
#include "Feather.h"
class Chicken :
	public Harvestable, public Fauna
{
public:
	Chicken();
};

