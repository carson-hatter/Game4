/*
"Scenery" is a parent class to "Foreground" and "Background".
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Scenery
{
protected: std::vector<sf::ConvexShape> Sprites;
public: void renderToWindow(sf::RenderWindow&);
protected: sf::Vector2f Default_View_Dimensions;
protected: std::vector<sf::IntRect> Text_Rects;
protected: sf::Texture *Sprite_Sheet;
public: Scenery (sf::Vector2f);//Default_View_Dimensions
public: Scenery(){};
};