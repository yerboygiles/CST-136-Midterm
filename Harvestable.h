#pragma once
#include "BaseNaturalObj.h"
#include "Resource.h"
class Harvestable : public BaseNaturalObj
{
public:
	Resource getResource();
};

