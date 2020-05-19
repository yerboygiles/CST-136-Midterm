//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

enum ResourceType { apple = 0, meat, berry,
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