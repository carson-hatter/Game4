/*
"HumanCognition" manages numeric representations of a character's attitude
towards another character.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "ScientificUnit.h"

class HumanCognition
{
protected: std::vector<ScientificUnit> Ally_Relations;
protected: ScientificUnit PC_Relation;
public: HumanCognition();
};