//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#include "BaseNaturalObj.h"

BaseNaturalObj::BaseNaturalObj()
{
}

BaseNaturalObj::BaseNaturalObj(string name, uint8 size)
	:m_objectname(name),m_size(size)
{
}

BaseNaturalObj::BaseNaturalObj(Status status)
{
	AddStatus(status);
}

BaseNaturalObj::~BaseNaturalObj()
{
	if (m_statuschain != nullptr) {
		delete[] m_statuschain;
		m_statuschain = nullptr;
	}
}

uint8 BaseNaturalObj::getSize()
{
	return m_size;
}

void BaseNaturalObj::setSize(uint8 size)
{
	m_size = size;
}

void BaseNaturalObj::AddStatus(Status newstatus)
{
	if (!CheckStatus(newstatus)) {
		Status* resize_statuschain = new Status[m_statussize + 1];

		for (int i = 0; i < m_statussize; i++) {
			resize_statuschain[i] = m_statuschain[i];
		}

		resize_statuschain[m_statussize] = newstatus;
		m_statussize++;
		delete[] m_statuschain;
		m_statuschain = nullptr;
		m_statuschain = new Status[m_statussize];

		for (int i = 0; i < m_statussize; i++) {
			m_statuschain[i] = resize_statuschain[i];
		}
		delete[] resize_statuschain;
		resize_statuschain = nullptr;
		cout << m_objectname
			<< " is now "
			<< statustostring[newstatus] << endl;
	}
	else {
		cout << m_objectname << " is already " << statustostring[newstatus] << endl;
	}
}

void BaseNaturalObj::RemoveStatus(Status rmvstatus)
{
	if (CheckStatus(rmvstatus)) {
		uint8_t down = 0;
		Status* resize_statuschain = new Status[m_statussize - 1];
		for (int i = 0; i < m_statussize; i++) {
			if (m_statuschain[i] == rmvstatus) {
				down = 1;
			}
			else {
				resize_statuschain[i - down] = m_statuschain[i];
			}
		}
		if (down) {
			m_statussize--;
			delete[] m_statuschain;
			m_statuschain = nullptr;
			m_statuschain = new Status[m_statussize];
			for (int i = 0; i < m_statussize; i++) {
				m_statuschain[i] = resize_statuschain[i];
			}

		}
		delete[] resize_statuschain;
		resize_statuschain = nullptr;
		cout << m_objectname
			<< " is no longer "
			<< statustostring[rmvstatus] << endl;
	}
	else {
		cout << m_objectname << " is not " << statustostring[rmvstatus] << endl;
	}
}

bool BaseNaturalObj::CheckStatus(Status chkstatus)
{
	bool there = false;
	for (int i = 0; i < m_statussize; i++) {
		if (m_statuschain[i] == chkstatus) {
			there=true;
		}
	}

	/*cout << m_objectname
		<< " is ";
	if (!there) {
		cout << "not ";
	}
	cout << statustostring[chkstatus] << endl;*/
	return there;
}

void BaseNaturalObj::DisplayStatus()
{
	cout << m_objectname << " is ";
	for (int i = 0; i < m_statussize; i++) {
		cout << statustostring[m_statuschain[i]];
	}
}

bool BaseNaturalObj::operator<(BaseNaturalObj other)
{
	return m_size < other.getSize();
}

bool BaseNaturalObj::operator>(BaseNaturalObj other)
{
	return m_size > other.getSize();
}

string BaseNaturalObj::getObjectName()
{
	return m_objectname;
}

void BaseNaturalObj::setObjectName(string name)
{
	m_objectname = name;
}

void BaseNaturalObj::operator++()
{
	if (m_size != 250) {
		m_size++;
		cout << m_objectname
			<< " has grown in size." << endl;
	}
	else {
		cout << m_objectname
			<< " is at the size maximum. " << endl;
	}
}
void BaseNaturalObj::operator--()
{
	if (m_size != 0) {
		m_size--;
		cout << m_objectname
			<< " has lessened in size." << endl;
	}
	else {
		cout << m_objectname
			<< " has pulled a Benjamin Button and become nonexistant in size. "
			<< endl;
	}
}
