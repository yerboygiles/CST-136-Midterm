#include "Bush.h"

Bush::Bush() 
	: Flora(Fiber(),Berry(),"Bush",3)
{
	setObjectName("Bush");
	AddStatus(fruited);
}

Bush::~Bush()
{
}
