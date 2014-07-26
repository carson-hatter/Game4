#include "Scene.h"

Scene::Scene(sf::Vector2f Default_View_Dim)
{
	Default_View_Dimensions = Default_View_Dim;

	gap_between_chars_in_pix = -200;
}

void Scene::setPCsGreatestEastwardDisp(float pcs_x_coord)
{
	if(pcs_x_coord > pcs_greatest_eastward_displacement)
	{
		pcs_greatest_eastward_displacement = pcs_x_coord;
	}
}

bool Scene::westwardBoundsChecking(float x)
{
	if(x < pcs_greatest_eastward_displacement - (Default_View_Dimensions.x / 2))
	{
		return false;
	}
	return true;
}