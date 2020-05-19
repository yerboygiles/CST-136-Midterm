//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Chicken.h"

Chicken::Chicken()
	:Harvestable("Chicken", 3 + (rand() % 3),Meat(),Feather()),
	Fauna(rand()%2,250),
	BaseNaturalObj("Chicken",3)
{
}

