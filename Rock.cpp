#include "Rock.h"

Rock::Rock()
	:Harvestable("Rock",30,Stone(),Iron())
{
	setObjectName("Rock");
	AddStatus(fruited);
}
