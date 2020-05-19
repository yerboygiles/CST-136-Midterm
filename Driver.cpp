#pragma once
#include "Dog.h"
#include "Chicken.h"
#include "Human.h"
#include "Bush.h"
#include "Tree.h"
#include "Knife.h"
#include "Multitool.h"
#include "Rock.h"

#define _CRTDBG_MAP_ALLOC

int main() {
	srand(time(NULL));
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Human adam = Human("Adam", Male);
	Human eve = Human("Eve", Female);
	Dog doggy = Dog("Fido");
	Bush bushy = Bush();
	Tree treey = Tree();
	Rock rocky = Rock();
	Chicken chicky = Chicken();
	adam.Harvest(bushy);
	adam.Harvest(treey);
	adam.Harvest(rocky);
	adam.DisplayItems();
	adam.Craft(Multitool());


	return 0;
}