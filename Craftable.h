//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "Resource.h"
class Craftable :
	public Resource
{
public:
	Craftable(string name, uint8 val,
		uint8 amtresource, ResourceType resourcetype);
	~Craftable();
	uint8 getAmtResources();
	Resource operator[](int i);
protected:
	Resource m_resourcesneeded[10];
	uint8 m_amtresources;
};

