#pragma once
#include <string>
#include <iostream>
#include <iomanip>

using std::string;
using std::cout;
using std::endl;


typedef unsigned _int8 uint8;

enum Status {
	dead = 0, alive,
	scared, happy, sad,
	sick, tired,
	wilting, blooming, fullyaged, fruited, barren,
	hungry, injured,
	beautiful, ugly
};
class BaseNaturalObj
{
public:
	string statustostring[16] = {
		"dead", "alive",
		"scared", "happy", "sad",
		"sick", "tired",
		"wilting", "blooming", "fullyaged", "fruited", "barren",
		"hungry", "injured",
		"beautiful", "ugly"
	};
	BaseNaturalObj();
	~BaseNaturalObj();
	uint8 getSize();
	void AddStatus(Status newstatus);
	void RemoveStatus(Status rmvstatus);
	bool CheckStatus(Status chkstatus);
	void DisplayStatus();
	bool operator<(BaseNaturalObj other);
	bool operator>(BaseNaturalObj other);
protected:
	uint8 m_size;
	uint8 m_statussize=0;
	Status* m_statuschain;
	string m_objectname;
};

