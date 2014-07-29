/*
Representation of the physiological and cognitive changes to be applied to a 
"HumanCharacter"
*/

#pragma once

#include "ScientificUnit.h"

class Effects
{
private: std::vector<float> ally_relations;
private: float pc_relation;
private: float hunger;
private: float thirst;
private: float fatigue;
private: float health;
public: std::vector<float> getAllyRelationDifferences(){return ally_relations;}
public: float getPCRelationDifference(){return pc_relation;}
public: float getHungerDifference(){return hunger;}
public: float getThirstDifference(){return thirst;}
public: float getFatigueDifference(){return fatigue;}
public: float getHealthDifference(){return health;}
public: Effects(float,//ally 1 relation
			float,//ally 2 relation
			float,//ally 3 relation
			float,// pc relation
			float,//hunger
			float,//fatigue
			float,//thirst
			float//health
			);
public: Effects();
};