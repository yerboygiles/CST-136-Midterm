#pragma once

#include "Fauna.h"
#include "Feather.h"
#include "Knife.h"
#include "Craftable.h"
#include "Multitool.h"
#define Male 1
#define Female 0

class Human :
	public Fauna
{
public:
	Human(string name,bool sex);
	~Human();
	void AddItem(Resource additem);
	void RemoveItem(Resource rmvitem);
	bool CheckItem(Resource chkitem);
	void DisplayItems();
	void Harvest(Harvestable& toharvest);
	void Attack(Fauna& attack);
	void EatFromInventory();
	void EatFromInventory(Resource itemtoeat);
	void Craft(Craftable tocraft);
	Human operator+(Human other);
private:
	string resourcetostring[14] = {
		"apple", "meat", "berry", "flower",
		"fiber", "feather", "wood",
		"stone", "iron",
		"craftable", "knife", "multitool", "house",
		"none"
	};

	Human(string name, bool sex, uint8 size);
	Resource* m_inventory;
	uint8 m_inventorysize;
};