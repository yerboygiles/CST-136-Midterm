#pragma once
#include "Craftable.h"
#include "Iron.h"
#include "Fiber.h"
#include "Wood.h"
class Knife :
	public Craftable
{
public:
	Knife();
	~Knife();
private:
	const Resource m_resourcesneeded[3] = { Iron(),Wood(),Fiber() };
};

