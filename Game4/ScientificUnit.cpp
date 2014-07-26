#include "ScientificUnit.h"

ScientificUnit::ScientificUnit(float min_value, float max_value, float current_value)
{
	min = min_value;
	max = max_value;
	current = current_value;

	boundsChecking();
}

ScientificUnit::ScientificUnit()
{
	min = 0;
	max = 100;
	current = 100;
}

float ScientificUnit::getPercentage()
{
	float range = max - min;
	float adjusted_current_value = current - min;
	return adjusted_current_value / range;
}

void ScientificUnit::mutate(float x)
{
	current += x;

	boundsChecking();
}

//void ScientificUnit::decrement(float x)
//{
//	current -= x;
//
//	boundsChecking();
//}
//
//void ScientificUnit::increment(float x)
//{
//	current += x;
//
//	boundsChecking();
//}

void ScientificUnit::boundsChecking()
{
	if(current > max)
	{
		current = max;
	}

	if(current < min)
	{
		current = min;
	}
}