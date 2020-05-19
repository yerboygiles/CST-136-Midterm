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

