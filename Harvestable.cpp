#include "Harvestable.h"

Harvestable::Harvestable(string name, uint8 size,
	Resource resource,Resource altresource)
	:BaseNaturalObj(name, size), 
	m_resource(resource), m_altresource(altresource),
	m_objectname(name)
{
}

Harvestable::~Harvestable()
{
}

void Harvestable::Deteriorate()
{
}

void Harvestable::setResource(Resource resource)
{
	m_resource = resource;
}

void Harvestable::setAltResource(Resource resource)
{
	m_altresource = resource;
}


Resource Harvestable::beHarvested()
{
	if (!(rand() % 4)) {
		if (!CheckStatus(barren)) {
			AddStatus(barren);
		}
		RemoveStatus(fruited);
	}
	//Deteriorate();
	return m_resource;
}

Resource Harvestable::beAltHarvested()
{
	if (!(rand() % 4)) {
		if (!CheckStatus(barren)) {
			AddStatus(barren);
		}
		RemoveStatus(fruited);
	}
	//Deteriorate();
	return m_altresource;
}

