#include "Tree.h"

Tree::Tree()
	:Flora(Wood(),Apple(),"Tree",12)
{
	setObjectName("Tree");
	AddStatus(fruited);
}
