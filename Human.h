//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once

#include "Fauna.h"
#include "Feather.h"
#include "Knife.h"
#include "Multitool.h"
#include "House.h"


class Human :
	public Fauna
{
public:
	Human(string name,bool sex);
	Human(const Human& other);
	Human& operator=(const Human& other);
	Human(Human&& other);
	Human& operator=(Human&& other);
	~Human();
	void AddItem(Resource additem);
	void RemoveItem(Resource rmvitem);
	bool CheckItem(Resource chkitem);
	Resource FindItem(Resource fnditem);
	void DisplayItems();
	void Harvest(Harvestable& toharvest);
	void Attack(Fauna& attack);
	void EatFromInventory();
	void EatFromInventory(Resource itemtoeat);
	void Craft(Craftable tocraft);
	void MoveIn();
	void MoveIntoHouse(string human);
	void Rest();
	Human operator+(Human other);
private:
	bool m_movedin;
	Human(string name, bool sex, uint8 size);
	House ownhouse;
	Resource* m_inventory;
	uint8 m_inventorysize;
};