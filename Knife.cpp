//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Knife.h"

Knife::Knife()
	:Craftable("Knife", 26, 3,knife)
{
	m_resourcesneeded[0] = Iron();
	m_resourcesneeded[1] = Wood();
	m_resourcesneeded[2] = Fiber();
}