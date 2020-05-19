#include "Human.h"

Human::Human(string name, bool sex)
	:BaseNaturalObj(name, 10+(rand()%10)),
	Fauna(sex,250)
{
	m_inventory = nullptr;
	m_inventorysize = 0;
}
Human::Human(string name, bool sex,uint8 size)
	:BaseNaturalObj(name, size),
	Fauna(sex, 250)
{
	m_inventory = nullptr;
	m_inventorysize = 0;
}

Human::~Human()
{
	delete[] m_inventory;
	m_inventory = nullptr;
}

void Human::AddItem(Resource additem)
{
	Resource* resize_inventory = new Resource[m_inventorysize + 1];

	for (int i = 0; i < m_inventorysize; i++) {
		resize_inventory[i] = m_inventory[i];
	}

	resize_inventory[m_inventorysize] = additem;
	m_inventorysize++;
	if (m_inventory != nullptr) {
		delete[] m_inventory;
		m_inventory = nullptr;
	}
	m_inventory = new Resource[m_inventorysize];

	for (int i = 0; i < m_inventorysize; i++) {
		m_inventory[i] = resize_inventory[i];
	}
	delete[] resize_inventory;
	resize_inventory = nullptr;
}

void Human::RemoveItem(Resource rmvitem)
{
	uint8_t down = 0;
	Resource* resize_inventory = new Resource[m_inventorysize - 1];
	for (int i = 0; i < m_inventorysize; i++) {
		if (m_inventory[i] == rmvitem) {
			down = 1;
		}
		else {
			resize_inventory[i - down] = m_inventory[i];
		}
	}
	if (down) {
		m_inventorysize--;
		delete[] m_inventory;
		m_inventory = nullptr;
		m_inventory = new Resource[m_inventorysize];
		for (int i = 0; i < m_inventorysize; i++) {
			m_inventory[i] = resize_inventory[i];
		}

	}
	delete[] resize_inventory;
	resize_inventory = nullptr;
}

bool Human::CheckItem(Resource chkitem)
{
	bool there = false;
	for (int i = 0; i < m_inventorysize; i++) {
		if (m_inventory[i] == chkitem) {
			there = true;
		}
	}
	return there;
}

void Human::DisplayItems()
{
	cout << m_objectname << " has ";
	for (int i = 0; i < m_inventorysize; i++) {
		if (i == m_inventorysize) {
			cout << "a(n) " << resourcetostring[m_inventory[i].getType()] << ".";
		}
		else {

		}
		cout << "a(n) " << resourcetostring[m_inventory[i].getType()] << ", ";
	}
	cout << endl;
}

void Human::Harvest(Harvestable& toharvest)
{
	cout << m_objectname
		<< " is harvesting "
		<< toharvest.getObjectName()
		<< endl;
	if (toharvest.CheckStatus(fruited)) {

		AddItem(toharvest.beHarvested());
		if (CheckItem(Multitool())) {
			AddItem(toharvest.beAltHarvested());
		}
	}
	else {
		cout << "Can't harvest a non-fruited plant" << endl;
	}
}

void Human::Attack(Fauna& attack)
{
	cout << m_objectname
		<< " attacks "
		<< attack.getObjectName()
		<< endl;
	uint8 damage=30;
	if (CheckItem(Knife())) {
		attack.AddStatus(injured);
		damage *= 2;
	}
	attack.lowerHealth(damage);
}

void Human::EatFromInventory()
{
	for (int i = 0; i < m_inventorysize; i++) {
		if (m_inventory[i].getEdibility()) {
			EatFromInventory(m_inventory[i]);
		}
	}
}

void Human::EatFromInventory(Resource itemtoeat)
{
	RemoveItem(itemtoeat);
	RemoveStatus(hungry);
	if (m_health + 10 > 250) {
		m_health = 250;
	}
	else {
		m_health += 10;
	}
}

void Human::Craft(Craftable tocraft)
{
	bool canbuild = true;
	Resource temp;
	for (int i = 0; i < tocraft.getAmtResources(); i++) {
		if (CheckItem(tocraft[i]))
		{
		}
		else {
			canbuild = false;
			temp = tocraft[i];
		}
		
	}
	if (canbuild) {
		AddItem(tocraft);
		cout << m_objectname
			<< " crafted "
			<< resourcetostring[tocraft.getType()]
			<< "." << endl;
	}
	else {
		cout << m_objectname
			<< " could not craft "
			<< resourcetostring[tocraft.getType()]
			<< " because of a lack of "
			<< resourcetostring[temp.getType()]
			<< "." << endl;
	}
}

Human Human::operator+(Human other)
{
	string name;
	cout << "Please give a name to the child of " 
		<< m_objectname
		<< " and "
		<< other.getObjectName()
		<< ".";
	cin >> name;
	Human temp = Human(name,false);
	return temp;
}
