#include "Chicken.h"

Chicken::Chicken()
	:Harvestable("Chicken", 3 + (rand() % 3),Meat(),Feather()),
	Fauna(rand()%2,250)
{
}
