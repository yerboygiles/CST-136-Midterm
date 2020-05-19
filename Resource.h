#pragma once
#include "BaseNaturalObj.h"

class Resource :
	public BaseNaturalObj
{
public:
	Resource(const Resource& other);
	Resource& operator=(const Resource& other);
	Resource(Resource&& other);
	Resource& operator=(Resource&& other);
	Resource();
	Resource(string name,int val, bool edible, ResourceType type);
	~Resource();
	bool operator==(Resource other);
	uint8 getValue();
	bool getEdibility();
	ResourceType getType();
protected:
	uint8 m_size = 1;
	uint8 m_value;
	bool m_edible;
	ResourceType m_type;
	string m_objectname;

};

