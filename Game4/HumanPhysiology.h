/*
"HumanPhysiology" manages numeric repesentations of physical attributes, such
as hunger, thirst, overall health, and fatigue.
*/

#pragma once
#include "ScientificUnit.h"
#include <SFML/Graphics.hpp>

class HumanPhysiology
{
protected: ScientificUnit Health;
public: bool isAlive();
protected: ScientificUnit Fatigue;
protected: ScientificUnit Thirst;
protected: ScientificUnit Hunger;
public: HumanPhysiology();
};