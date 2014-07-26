/*
"MyGeometry" is a collection of static functions that process common
geometry problems.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
class MyGeometry
{
public: MyGeometry(){};
public: static float findDistance(sf::Vector2f A, sf::Vector2f B)
		{
			float x_diff = A.x - B.x;
			float y_diff = A.y - B.y;
			return sqrt((x_diff * x_diff) + (y_diff * y_diff));
		}
public: static sf::Vector2f findPointOnACircle(float radius, float theta_in_radians, sf::Vector2f Center)
		{
			sf::Vector2f To_Return;

			To_Return.x = Center.x + (radius * cos(theta_in_radians));
			To_Return.y = Center.y + (radius * sin(theta_in_radians));

			return To_Return;
		}
public: static float findTheta(sf::Vector2f A, sf::Vector2f B)
		{
			float x_diff = B.x - A.x;
			float y_diff = B.y - A.y;
			return atan2(y_diff, x_diff);
		}
public: static float findHypotenuse(sf::Vector2f A, sf::Vector2f B)
		{
			float x_diff = B.x - A.x;
			float y_diff = B.y - A.y;
			return sqrt((x_diff * x_diff) + (y_diff * y_diff));
		}
public: static float min(float A, float B)
		{
			float to_return;

			if(A < B)
			{
				to_return = A;
			}
			else
			{
				to_return = B;
			}

			return to_return;
		}
public: static float max(float A, float B)
		{
			float to_return;

			if(A > B)
			{
				to_return = A;
			}
			else
			{
				to_return = B;
			}

			return to_return;
		}
};