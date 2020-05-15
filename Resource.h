#pragma once
#include "BaseNaturalObj.h"
enum ResourceType {Apple,Berry,Fiber,Feather,Wood,Stone,Iron,Craftable};

class Resource :
	public BaseNaturalObj
{
public:
	string resourcetostring[16] = {
		"Apple","Berry","Fiber","Feather","Wood","Stone","Iron","Craftable"
};
protected:
	uint8 m_value;
	bool m_edible;

};

