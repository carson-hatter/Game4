#include "HumanCharacter.h"

void HumanCharacter::applyEffects(Effects Fx)
{
	Fatigue.mutate(Fx.getFatigueDifference());
	Health.mutate(Fx.getHealthDifference());
	Hunger.mutate(Fx.getHungerDifference());
	Thirst.mutate(Fx.getThirstDifference());

	//try/catch anywhere im not bounds checking two "allies" vectors
	for(unsigned int i = 0; i < Ally_Relations.size(); i++)
	{
		Ally_Relations[i].mutate(Fx.getAllyRelationDifferences().at(i));
	}
	PC_Relation.mutate(Fx.getPCRelationDifference());
}