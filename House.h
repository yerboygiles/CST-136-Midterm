#pragma once
#include "Craftable.h"
#include "Human.h"
class House :
	public Craftable
{
public:
	House();
	void AddInhabitant(Human human);
	void RemoveInhabitant(Human human);
	void WhoLivesHere();
private:
	uint8 amtinhabitants=0;
	string inhabitants[3];
	const Resource m_resourcesneeded[8] = { Wood(),Stone(),Iron(),Fiber(),Feather() };
};

