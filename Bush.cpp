//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Bush.h"

Bush::Bush() 
	: Flora(Fiber(),Berry(),"Bush",3)
{
	setObjectName("Bush");
	AddStatus(fruited);
}