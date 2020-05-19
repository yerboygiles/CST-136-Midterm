//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
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
	if (m_health < 150) {
		AddStatus(injured);
	}
}

bool Fauna::getSex()
{
	return m_sex;
}

bool Fauna::isDead()
{
	if (m_objectname == "Chicken"&&CheckStatus(dead)) {
		AddStatus(fruited);
	}
	return CheckStatus(dead);
}


void Fauna::Rest()
{
	cout << m_objectname
		<< " rested on the ground, ";
	if (!(rand() % 2)) {
		cout << "and felt well rested." << endl;
		RemoveStatus(tired);
	}
	else {
		cout << "and did not feel well rested." << endl;
	}

}


Fauna Fauna::operator+(Fauna other)
{
	{
		int BAD_PROCREATION = 12;
		try {
			if ((getSex()==Male&&other.getSex()==Female)|| (getSex() == Female && other.getSex() == Male)) {
				return Fauna(false, 250);
			}
			else {
				throw BAD_PROCREATION;
			}
		}
		catch (const int error) {
			if (error == BAD_PROCREATION) {
				cout << "They can get married, but they can't quite make a child. Sorry.";
			}
		}
	}
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
