//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Rock.h"

Rock::Rock()
	:Harvestable("Rock",30,Stone(),Iron())
{
	setObjectName("Rock");
	AddStatus(fruited);
}
