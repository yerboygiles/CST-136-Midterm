#pragma once
#include "Fauna.h"
class Dog :
	public Fauna
{
public:
	Dog(string name);
	void Bite(Fauna& tobite);
	void BarkAt(Fauna& barkat);
};

