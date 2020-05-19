//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "Human.h"

string resourcetostring[14] = {
	"apple", "meat", "berry",
	"fiber", "feather", "wood",
	"stone", "iron",
	"craftable", "knife", "multitool", "house",
	"none"
};

Human::Human(string name, bool sex)
	:BaseNaturalObj(name, 10+(rand()%10)),
	Fauna(sex,250)
{
	m_inventory = nullptr;
	m_inventorysize = 0;
}
Human::Human(const Human& other)
	:BaseNaturalObj(other.m_objectname, other.m_size),
	Fauna(other.m_sex, 250)
{
	m_inventory = nullptr;
	m_inventorysize = 0;
}
Human& Human::operator=(const Human& other)
{
	BaseNaturalObj(other.m_objectname, other.m_size);
	Fauna(other.m_sex, 250);
	m_inventory = nullptr;
	m_inventorysize = 0;
	return *this;
}
Human::Human(Human&& other)
	: BaseNaturalObj(other.m_objectname, other.m_size),
	Fauna(other.m_sex, 250)
{
	m_inventory = nullptr;
	m_inventorysize = 0;
}
Human& Human::operator=(Human&& other)
{
	BaseNaturalObj(other.m_objectname, other.m_size);
	Fauna(other.m_sex, 250);
	m_inventory = nullptr;
	m_inventorysize = 0;
	return *this;
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
	Resource* resize_inventory = new Resource[m_inventorysize];
	for (int i = 0; i < m_inventorysize; i++) {

		if (m_inventory[i] == rmvitem&&down==0) {
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

Resource Human::FindItem(Resource fnditem)
{
	Resource there;
	for (int i = 0; i < m_inventorysize; i++) {
		if (m_inventory[i] == fnditem) {
			there = m_inventory[i];
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
	if (toharvest.getObjectName() == "Flower") {
		cout << "Harvesting a flower made "
			<< m_objectname
			<< " happy!" << endl;
		AddStatus(happy);
	}
	if (toharvest.CheckStatus(fruited)) {

		AddItem(toharvest.beHarvested());
		if (CheckItem(Multitool())) {
			AddItem(toharvest.beAltHarvested());
		}
		if ((rand() % 5)==1) {
			AddStatus(tired);
			AddStatus(hungry);
		}
	}
	else {
		cout << "Can't harvest a non-fruited harvestable" << endl;
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
	if (attack.isDead()) {
		cout << m_objectname
			<< " killed "
			<< attack.getObjectName()
			<< endl;
	}
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
	if (CheckItem(itemtoeat)) {
		cout << m_objectname
			<< " ate a "
			<< resourcetostring[itemtoeat.getType()]
			<< endl;
		RemoveItem(itemtoeat);
		RemoveStatus(hungry);
		if (m_health + 10 > 250) {
			m_health = 250;
		}
		else {
			m_health += 10;
		}
	}
	else {
		cout << m_objectname
			<< " does not have a "
			<< resourcetostring[itemtoeat.getType()]
			<< " to eat."
			<< endl;
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
		for (int i = 0; i < tocraft.getAmtResources(); i++) {
			RemoveItem(tocraft[i]);
		}
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

void Human::MoveIn()
{
	if (CheckItem(House())) {
		if (ownhouse.AddInhabitant(m_objectname)) {
			m_movedin = true;
			RemoveStatus(scared);
		}
		else {
			m_movedin = false;
		}
	}
}
void Human::MoveIntoHouse(string human)
{
	if (CheckItem(House())) {
		if (ownhouse.AddInhabitant(human)) {
			m_movedin = true;
		}
		else {
			m_movedin = false;
		}
	}
}

void Human::Rest()
{
	if (m_movedin) {
		cout << m_objectname
			<< " rested in the house he currently resides in."
			<< endl;
		RemoveStatus(tired);
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
