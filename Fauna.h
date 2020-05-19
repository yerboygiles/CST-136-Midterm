//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once

#include "BaseNaturalObj.h"
#include "Flora.h"

#define Male 1
#define Female 0

class Fauna :
	public virtual BaseNaturalObj
{
public:
	Fauna(bool sex, uint8 health);
	uint8 getHealth();
	void lowerHealth(uint8 lowerby);
	bool getSex();
	bool isDead();
	virtual void Rest();
	Fauna operator+(Fauna other);
	void NurtureFlora(Flora& plant);

protected:
	uint8 m_health=250;
	bool m_sex;
	string m_name;
};

