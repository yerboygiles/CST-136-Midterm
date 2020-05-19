#include "House.h"

House::House()
	:Craftable("House",100,8,house)
{
}

void House::AddInhabitant(Human human)
{
	if (amtinhabitants < 3) {
		inhabitants[amtinhabitants] = human.getObjectName();
		amtinhabitants++;
		cout << human.getObjectName() 
			<< " now lives in "
			<< getObjectName() 
			<< "."
			<< endl;
	}
	else {
		cout << "This house is at capacity." << endl;
	}
}

void House::RemoveInhabitant(Human human)
{
	bool removed=false;
	for (int i = 0; i < amtinhabitants; i++) {
		if (removed) {
			inhabitants[i - 1] = inhabitants[i];
		}
		else if (human.getObjectName() == inhabitants[i]) {
			removed = true;
		}
	}
	if (removed) {
		inhabitants[amtinhabitants] = "";
		amtinhabitants--;
		cout << human.getObjectName()
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
