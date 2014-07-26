/*
"HumanCharacter" is a child class of "HumanPhysiology", "HumanSprite", and
"HumanCognition"; "HumanCharacter" is a master class of the three parent
classes.
*/
#pragma once

#include "HumanPhysiology.h"
#include "HumanSprite.h"
#include "HumanCognition.h"
#include "Weapon.h"
#include "Effects.h"

class HumanCharacter : public HumanSprite, public HumanCognition, public Weapon, public HumanPhysiology
{
public: HumanCharacter(std::string Name_, sf::Texture *Sprite_Sheet_, sf::Vector2f Intial_Pos) : HumanSprite(Name_, Sprite_Sheet_, Intial_Pos), HumanCognition(), Weapon(), HumanPhysiology()
		{

		};
public: HumanCharacter() : HumanSprite(), HumanCognition(), Weapon(), HumanPhysiology()
		{

		};
public: void applyEffects(Effects);
};