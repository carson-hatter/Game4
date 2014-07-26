/*
"Background" manages the graphics drawn before anything else inside "Game",
the sf::ConvexShape objects that move at a fraction of the "Foreground"
sf::ConvexShape objects
*/
#pragma once

#include "Scenery.h"

class Background : public Scenery
{
public: Background(sf::Vector2f Default_View_Dimensions_) : Scenery(Default_View_Dimensions_)
{
	pcs_displacement_at_last_shift = 0;

	text_rects_iterator = 0;
	Text_Rects.resize(2);
	Text_Rects[0] = sf::IntRect(0,0,4000,1000);
	Text_Rects[1] = sf::IntRect(0,1000,4000,1000);

	Sprite_Sheet = new sf::Texture;
	Sprite_Sheet->loadFromFile("background_sprite_sheet.jpg");

	Sprites.push_back(createSprite(0));
}
public: Background():Scenery(){};
private: unsigned int text_rects_iterator;
private: void incrementTextRectsIter();
private: float pcs_displacement_at_last_shift;
private: void pushBack();
private: void erase();
private: sf::ConvexShape createSprite(float);//last_sprites_greatest_x_value
public: void shift(float);//pcs_current displacement
};