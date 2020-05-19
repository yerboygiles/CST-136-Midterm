#include "Fauna.h"

Fauna::Fauna(bool sex,uint8 health)
	:BaseNaturalObj("Fauna",30), m_sex(sex)
{
}

uint8 Fauna::getHealth()
{
	return m_health;
}

void Fauna::lowerHealth(uint8 lowerby)
{
	if (m_health - lowerby <= 0) {
		m_health = 0;
		AddStatus(dead);
	}
	else {
		m_health -= lowerby;
	}
}

bool Fauna::getSex()
{
	return m_sex;
}

bool Fauna::isDead()
{
	return CheckStatus(dead);
}


Fauna Fauna::operator+(Fauna other)
{
	m_health -= 10;
	other.m_health -= 10;
	return Fauna(false,250);
}

void Fauna::NurtureFlora(Flora& plant)
{
	if (!(CheckStatus(dead)||CheckStatus(injured))) {
		cout << m_objectname << " has nurtured a " << plant.getObjectName() << endl;
		plant.Grow();
	}
	else {
		DisplayStatus();
		cout << ", cannot nurture " << plant.getObjectName() << endl;
	}
}
