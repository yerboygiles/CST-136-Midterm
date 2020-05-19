//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "House.h"

House::House()
	:Craftable("House",100,5,house)
{
	m_resourcesneeded[0] = Stone();
	m_resourcesneeded[1] = Wood();
	m_resourcesneeded[2] = Fiber();
	m_resourcesneeded[3] = Iron();
	m_resourcesneeded[4] = Feather();
}

bool House::AddInhabitant(string human)
{
	bool movedin;
	RemoveInhabitant(human);
	if (amtinhabitants < 3) {
		inhabitants[amtinhabitants] = human;
		amtinhabitants++;
		cout << human 
			<< " now lives in "
			<< getObjectName() 
			<< "."
			<< endl;
		movedin = true;
	}
	else {
		cout << "This house is at capacity." << endl;
		movedin = false;
	}
	return movedin;
}

void House::RemoveInhabitant(string human)
{
	bool removed=false;
	for (int i = 0; i < amtinhabitants; i++) {
		if (removed) {
			inhabitants[i - 1] = inhabitants[i];
		}
		else if (human == inhabitants[i]) {
			removed = true;
		}
	}
	if (removed) {
		inhabitants[amtinhabitants] = "";
		amtinhabitants--;
		cout << human
			<< " no longer lives in "
			<< getObjectName()
			<< "."
			<< endl;
	}
}

void House::WhoLivesHere()
{
	for (int i = 0; i < amtinhabitants; i++) {
		if (i == amtinhabitants) {
			cout << inhabitants[i] << ", and ";
		}
		else {
			cout << inhabitants[i];
		}
	}
	cout << " live here." << endl;
}
