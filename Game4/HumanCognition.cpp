#include "HumanCognition.h"

HumanCognition::HumanCognition()
{
	Ally_Relations.resize(3);
	for(unsigned int i = 0; i < Ally_Relations.size(); i++)
	{
		Ally_Relations[i] = ScientificUnit(0,100,100);
	}
	PC_Relation = ScientificUnit(0,100,100);
}
