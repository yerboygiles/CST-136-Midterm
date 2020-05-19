//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Flora.h"

Flora::Flora(Resource resource, Resource altresource, string name, uint8 size)
	:Harvestable(name, size, resource, altresource),
	m_growth(250)
{
}

void Flora::Grow()
{
	if (!CheckStatus(dead)) {
		if (m_growth + 50 >= 250) {
			m_growth = 250;
			AddStatus(blooming);
			AddStatus(fruited);
		}
		else {
			RemoveStatus(blooming);
			m_growth += 50;
		}
	}
}

void Flora::Deteriorate()
{
	if (!CheckStatus(dead)) {
		if (m_growth - 50 <= 0) {
			m_growth = 0;
			AddStatus(dead);
		}
		else {
			RemoveStatus(blooming);
			m_growth -= 50;
		}
	}
}

uint8 Flora::getGrowth()
{
	return m_growth;
}

void Flora::setGrowth(uint8 togrow)
{
	m_growth= togrow;
}

