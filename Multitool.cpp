#include "Multitool.h"

Multitool::Multitool()
	:Craftable("Multitool", 16, 3, multitool)
{
	m_resourcesneeded[0] = Stone();
	m_resourcesneeded[1] = Wood();
	m_resourcesneeded[2] = Fiber();
};
