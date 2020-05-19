//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Craftable.h"

Craftable::Craftable(string name, uint8 val, 
	uint8 amtresource,ResourceType resourcetype)
	:Resource(name,val,false,resourcetype),
	m_amtresources(amtresource)
{
}

Craftable::~Craftable()
{
}

uint8 Craftable::getAmtResources()
{
	return m_amtresources;
}

Resource Craftable::operator[](int i)
{
	{
		int OUT_OF_BOUNDS = 6;
		Resource toreturn;
		try {
			if (i >= m_amtresources) {
				throw OUT_OF_BOUNDS;
			}
			else {
				toreturn = m_resourcesneeded[i];
			}
		}
		catch (const int error) {
			if (error == OUT_OF_BOUNDS) {
				cout << "Out of bounds! Bruh.";
			}
		}
		return toreturn;
	}
}
