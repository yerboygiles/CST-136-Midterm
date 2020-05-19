#pragma once

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum ResourceType { apple = 0, meat, berry, flower,
	fiber, feather, wood, 
	stone, iron, 
	craftable, knife, multitool, house,
	none};

enum Status {
	dead = 0, alive,
	scared, happy, sad,
	sick, tired,
	wilting, blooming, fullyaged, fruited, barren,
	hungry, injured,
	beautiful, ugly,
	active
};