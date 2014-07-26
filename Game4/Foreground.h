/*
"Foreground" manages the sf::ConvexShape objects that represent what the
"HumanSprite" objects in "Game" walk on top of; a master class for a vector of
quadilaterals with two right angles, and two angles that create a randomly
slanted line that connects to the top right point of the previous sf::
ConvexShape object in the given vector.
*/

#pragma once
#include "Scenery.h"
#include "MyGeometry.h"
#include "Rails.h"

class Foreground : public Scenery, public Rails
{
private: void pushBack();
private: void erase();
public: Foreground(sf::Vector2f Default_View_Dimensions_) : Scenery(Default_View_Dimensions_), Rails()
{
	Text_Rects.resize(2);
	Text_Rects[0] = sf::IntRect(0,0,1000,1000);
	Text_Rects[1] = sf::IntRect(1000,0,1000,1000);

	Sprite_Sheet = new sf::Texture;
	Sprite_Sheet->loadFromFile("foreground_sprite_sheet.jpg");
	pcs_greatest_eastward_displacement = 0;

	Sprites.push_back(createSprite(0));
	pushBack();
}
public: Foreground():Scenery(),Rails(){};
private: float pcs_greatest_eastward_displacement;
public: void setPCsGreatestEastwardDisplacement(float);//pc disp
private: sf::ConvexShape createSprite(float);//most_eastward_x_coordinate
public: float getMostEastwardCoordinate();
};