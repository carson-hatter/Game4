/*
"ScientificUnit" is a wrapper for a floating point number, managing given
float's maximum and minimum values, bounds checking, and the percentage
of the float versus its maximum value.
*/

#pragma once
#include <SFML/Graphics.hpp>

class ScientificUnit
{
private: float max;
private: float min;
private: float current;
public: float getPercentage();
//public: void decrement(float);
//public: void increment(float);
public: void mutate(float);
public: ScientificUnit(float,
			float,
			float
			);
public: ScientificUnit();
private: void boundsChecking();
};