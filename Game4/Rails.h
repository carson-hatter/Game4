 /*
"Rails" implements a line that traces through the top two points of each
element of Foreground::Sprites.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "MyGeometry.h"

class Rails
{
private: std::vector<sf::Vector2f> Rail;
public: void updateRail(std::vector<sf::ConvexShape>,//foreground pieces
			unsigned int,//top right point index
			unsigned int//top left point index
			);
public: sf::Vector2f getMovementDestination(float,//distance to travel
			sf::Vector2f//starting pt.
			);
public: sf::Vector2f getValidCoord(float);//x coord
public: Rails();
};