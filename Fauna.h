#pragma once

#include "BaseNaturalObj.h"
#include "Flora.h"

class Fauna :
	public virtual BaseNaturalObj
{
public:
	Fauna(bool sex, uint8 health);
	uint8 getHealth();
	void lowerHealth(uint8 lowerby);
	bool getSex();
	bool isDead();
	Fauna operator+(Fauna other);
	void NurtureFlora(Flora& plant);

protected:
	uint8 m_health;
	bool m_sex;
	string m_name;
};

