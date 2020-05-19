//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Resource.h"


Resource::Resource(const Resource& other)
	:BaseNaturalObj(other.m_objectname, other.m_size)
{
	m_value = other.m_value;
	m_edible = other.m_edible;
	m_type = other.m_type;
	m_size = other.m_size;
}

Resource& Resource::operator=(const Resource& other)
{
	m_value = other.m_value;
	m_edible = other.m_edible;
	m_type = other.m_type;
	m_size = other.m_size;
	return *this;
}

Resource::Resource(Resource&& other)
	:BaseNaturalObj(other.m_objectname, other.m_size)
{
	m_value = other.m_value;
	m_edible = other.m_edible;
	m_type = other.m_type;
	m_size = other.m_size;
	other.~Resource();
}

Resource& Resource::operator=(Resource&& other)
{
	m_value = other.m_value;
	m_edible = other.m_edible;
	m_type = other.m_type;
	m_size = other.m_size;
	other.~Resource();
	return *this;
}
Resource::Resource()
	:BaseNaturalObj("Resource",1),m_value(0),m_edible(NULL),m_type(none)
{
}
Resource::Resource(string name,uint8 val, bool edible, ResourceType type)
	:BaseNaturalObj(name,1),m_value(val),m_edible(edible),m_type(type)
{
}

Resource::~Resource()
{
}

bool Resource::operator==(Resource other)
{
	return m_type==other.m_type;
}

uint8 Resource::getValue()
{
	return m_value;
}

bool Resource::getEdibility()
{
	return m_edible;
}

ResourceType Resource::getType()
{
	return m_type;
}


