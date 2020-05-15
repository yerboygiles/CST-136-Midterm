#include "BaseNaturalObj.h"

BaseNaturalObj::BaseNaturalObj() 
	:m_objectname("BaseNaturalObj"),
	m_size(0), 
	m_statuschain(nullptr),
	m_statussize(0)
{
}

BaseNaturalObj::~BaseNaturalObj()
{
	delete[] m_statuschain;
	m_statuschain = nullptr;
}

uint8 BaseNaturalObj::getSize()
{
	return m_size;
}

void BaseNaturalObj::AddStatus(Status newstatus)
{
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
}

void BaseNaturalObj::RemoveStatus(Status rmvstatus)
{
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
}

bool BaseNaturalObj::CheckStatus(Status chkstatus)
{
	bool there = false;
	for (int i = 0; i < m_statussize; i++) {
		if (m_statuschain[i] == chkstatus) {
			there=true;
		}
	}
	return there;
}

void BaseNaturalObj::DisplayStatus()
{
	cout << m_objectname << "has the statuses: " << endl;
	for (int i = 0; i < m_statussize; i++) {
		cout << statustostring[m_statuschain[i]] << endl;
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
