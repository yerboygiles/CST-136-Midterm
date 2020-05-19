#include "Flora.h"

Flora::Flora(Resource resource, Resource altresource,string name, uint8 size)
	:Harvestable(name, size, resource,altresource)
{
}

void Flora::Grow()
{
	if (!CheckStatus(dead)) {
		if (m_growth + 50 >= 250) {
			m_growth = 250;
			AddStatus(fruited);
			RemoveStatus(barren);
			AddStatus(blooming);
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
			AddStatus(barren);
			RemoveStatus(fruited);
			AddStatus(dead);
			RemoveStatus(blooming);
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

