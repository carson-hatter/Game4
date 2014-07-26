#include "HumanPhysiology.h"

HumanPhysiology::HumanPhysiology()
{
	Health = ScientificUnit(0,100,100);
	Fatigue = ScientificUnit(0,100,100);
	Hunger = ScientificUnit(0,100,100);
	Thirst = ScientificUnit(0,100,100);
}

bool HumanPhysiology::isAlive()
{
	if(Health.getPercentage() == 0)
	{
		return false;
	}
	return true;
}