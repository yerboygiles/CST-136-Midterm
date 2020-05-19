#pragma once
//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include "BaseNaturalObj.h"
#include "Resource.h"
class Harvestable : public virtual BaseNaturalObj
{
public:
	Harvestable(string name, uint8 size,
		Resource resource, Resource altresource);
	~Harvestable();
	virtual void Deteriorate();
	void setResource(Resource resource);
	void setAltResource(Resource resource);
	Resource beHarvested();
	Resource beAltHarvested();
protected:
	Resource m_resource;
	Resource m_altresource;
	string m_objectname = "Harvestable";
};

