//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "Harvestable.h"
class Flora :
	public Harvestable
{
public:
	Flora(Resource resource, Resource altresource,string name, uint8 size);
	void Grow();
	void Deteriorate();
	uint8 getGrowth();
	void setGrowth(uint8 togrow);
protected:
	uint8 m_growth;
};

