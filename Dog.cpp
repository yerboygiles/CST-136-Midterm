//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Dog.h"

Dog::Dog(string name)
	:BaseNaturalObj(name, 8 + (rand() % 12)),
	Fauna(rand() % 2,250)
{
}

void Dog::Bite(Fauna& tobite)
{
	uint8 damage;
	if (5 * m_size > 250) {
		damage = 250;
	}
	else {
		damage = 5 * m_size;
	}
	tobite.lowerHealth(damage);
	cout << m_objectname
		<< " attacks "
		<< tobite.getObjectName()
		<< " for "
		<< (int)damage
		<< " damage." << endl;
}

void Dog::BarkAt(Fauna& barkat)
{
	cout << m_objectname
		<< " barks at "
		<< barkat.getObjectName()
		<< "."
		<< endl;
	barkat.AddStatus(scared);
}
