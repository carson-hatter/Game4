#include "Effects.h"

Effects::Effects(float ally_1_rel, float ally_2_rel, float ally_3_rel, float pc_rel, float fatigue_, float health_, float hunger_, float thirst_)
{
	//ally_1_relation = ally_1_rel;
	//ally_2_relation = ally_2_rel;
	//ally_3_relation = ally_3_rel;
	ally_relations.push_back(ally_1_rel);
	ally_relations.push_back(ally_2_rel);
	ally_relations.push_back(ally_3_rel);
	pc_relation = pc_rel;
	fatigue = fatigue_;
	health = health_;
	hunger = hunger_;
	thirst = thirst_;
}
Effects::Effects()
{
	ally_relations.push_back(0);
	ally_relations.push_back(0);
	ally_relations.push_back(0);
	pc_relation = 0;
	fatigue = 0;
	health = 0;
	hunger = 0;
	thirst = 0;
}