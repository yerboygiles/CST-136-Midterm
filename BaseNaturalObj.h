//Name: Theodor Giles
//Programming Assignment: CST 136 Midterm Implementation
#pragma once
#include <stdio.h>		/* NULL */
#include <string>		/* string */
#include <iostream>		/* cout, cin */
#include <iomanip>		/* endl */

#include "Enums.h"		/* Status, ResourceType */

using std::string;
using std::cout;
using std::cin;
using std::endl;
#ifndef statustostring
#else
#endif // !statustostring



typedef unsigned _int8 uint8;

class BaseNaturalObj
{
public:
	BaseNaturalObj();
	BaseNaturalObj(string name,uint8 size);
	BaseNaturalObj(Status status);
	~BaseNaturalObj();
	void AddStatus(Status newstatus);
	void RemoveStatus(Status rmvstatus);
	bool CheckStatus(Status chkstatus);
	void DisplayStatus();
	bool operator<(BaseNaturalObj other);
	bool operator>(BaseNaturalObj other);
	uint8 getSize();
	void setSize(uint8 size);
	string getObjectName();
	void setObjectName(string name);
	void operator++();
	void operator--();
protected:
	uint8 m_statussize=0;
	Status* m_statuschain=nullptr;
	uint8 m_size;
	string m_objectname;
private:
	string statustostring[16] = {
		"dead", "alive",
		"scared", "happy", "sad",
		"sick", "tired",
		"wilting", "blooming", "fullyaged", "fruited", "barren",
		"hungry", "injured",
		"beautiful", "ugly"
	};
};

