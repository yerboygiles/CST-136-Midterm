//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "Dog.h"
#include "Chicken.h"
#include "Human.h"
#include "Bush.h"
#include "Tree.h"
#include "Knife.h"
#include "Multitool.h"
#include "Rock.h"
#include "House.h"
#include "Flower.h"

#define _CRTDBG_MAP_ALLOC

int main() {
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//instantiating all the initial things, natural resources/harvestables,
	//as well as some living creatures to interact with the environment.
	Human adam = Human("Adam", Male);
	Human eve = Human("Eve", Female);
	Dog doggy = Dog("Fido");
	Bush bushy = Bush();
	Bush bushy2 = Bush();
	Bush bushy3 = Bush();
	Tree treey = Tree();
	Tree treey2 = Tree();
	Tree treey3 = Tree();
	Rock rocky = Rock();
	Rock rocky2 = Rock();
	Rock rocky3 = Rock();
	Chicken chicky = Chicken();
	Flower flowy = Flower(); 
	//Adam harvests some resources so he can make a tool to then gather
	//food and other alternate resources from harvestables.
	adam.Harvest(bushy);
	adam.Harvest(treey);
	adam.Harvest(rocky);

	adam.DisplayItems();

	adam.Craft(Multitool());

	adam.DisplayItems();
	//Can now harvest berries, so he harvests a bush with his multitool,
	//and if hes hungry or tired by now from harvesting, the statuses are removed
	adam.Harvest(bushy2);

	adam.EatFromInventory();

	//Harvesting the flower makes adam happy
	adam.Harvest(flowy);

	adam.Harvest(treey);
	adam.Harvest(rocky);
	adam.Harvest(rocky2);

	adam.DisplayItems();

	//Adam makes a knife and compares it to the multitool. "Ooga booga, I caveman, 
	//I wanna compare knife and multitool."
	adam.Craft(Knife());
	cout << "Is the knife bigger than the Multitool?" << endl;
	if (adam.FindItem(Knife()) > adam.FindItem(Multitool())) {
		cout << "Yes!" << endl;
	}
	else {
		cout << "No.." << endl;
	}

	adam.DisplayItems();
	//Adam attacks the chicken, and then harvests it for its meat, and its feather,
	//which is required to make a house. 
	adam.Attack(chicky);
	adam.Attack(chicky);
	adam.Attack(chicky);
	adam.Attack(chicky);
	adam.Attack(chicky);
	adam.Harvest(chicky);

	adam.DisplayItems();
	//Fido the dog approaches, barks at adam, and then bites him. The dog's damage is 
	//based on his size, which is partially randomized.
	doggy.BarkAt(adam);
	doggy.Bite(adam);

	//He gathers some more resources to get what he needs to make the house.
	adam.Harvest(bushy3);
	adam.Harvest(rocky3);
	adam.Harvest(treey3);

	//He crafts the house, removing the scared status, cause he is now moved into a house.
	//He also moves in Eve, has a baby with her(letting you, god or something, name it)
	adam.Craft(House());
	adam.MoveIn();
	adam.MoveIntoHouse(eve.getObjectName());
	Human baby = eve + adam;

	//Adam moves the baby into the house, reaching maximum occupancy, and then Eve goes out
	//and nurtures/waters/whatever the bushes nearby!
	adam.MoveIntoHouse(baby.getObjectName());
	eve.NurtureFlora(bushy);
	eve.NurtureFlora(bushy2);
	eve.NurtureFlora(bushy3);

	adam.Rest();
	return 0;
}