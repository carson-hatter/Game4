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
public: float getHealthPercentage(){return Health.getPercentage();}
public: bool isAlive();
protected: ScientificUnit Fatigue;
public: float getFatiguePercentage(){return Fatigue.getPercentage();}
protected: ScientificUnit Thirst;
public: float getThirstPercentage(){return Thirst.getPercentage();}
protected: ScientificUnit Hunger;
public: float getHungerPercentage(){return Hunger.getPercentage();}
public: HumanPhysiology();
};