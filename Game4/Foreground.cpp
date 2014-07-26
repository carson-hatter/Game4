#include "Foreground.h"

void Foreground::setPCsGreatestEastwardDisplacement(float disp)
{
	if(disp > pcs_greatest_eastward_displacement)
	{
		pcs_greatest_eastward_displacement = disp;
	}

	pushBack();
	erase();
}

float Foreground::getMostEastwardCoordinate()
{
	return Sprites.back().getGlobalBounds().width + Sprites.back().getGlobalBounds().left;
}

void Foreground::pushBack()
{
	if(!Sprites.empty())
	{
		float most_eastward_x_coordinate = Sprites[Sprites.size() - 1].getGlobalBounds().width + Sprites[Sprites.size() - 1].getGlobalBounds().left;

		while(most_eastward_x_coordinate < pcs_greatest_eastward_displacement + Default_View_Dimensions.x)
		{
			Sprites.push_back(createSprite(most_eastward_x_coordinate));

			most_eastward_x_coordinate = Sprites[Sprites.size() - 1] .getGlobalBounds().width + Sprites[Sprites.size() - 1].getGlobalBounds().left;
		}
	}

	updateRail(Sprites,0,1);
}

void Foreground::erase()
{
	if(!Sprites.empty())
	{
		float most_eastward_x_coordinate = Sprites[0].getGlobalBounds().left + Sprites[0].getGlobalBounds().width;

		while(most_eastward_x_coordinate < pcs_greatest_eastward_displacement - Default_View_Dimensions.x)
		{
			Sprites.erase(Sprites.begin());

			most_eastward_x_coordinate = Sprites[0].getGlobalBounds().left + Sprites[0].getGlobalBounds().width;
		}
	}

	updateRail(Sprites, 0, 1);
}

sf::ConvexShape Foreground::createSprite(float most_eastward_x_coordinate)
{
	sf::ConvexShape To_Return;

	unsigned int max_width = 1200;
	unsigned int min_width = 300;
	unsigned int height_range = 100;
	int max_height = -350;
	int min_height = -250;

	float left_y, right_x, right_y;

	if(Sprites.size() > 0)
	{
		left_y = Sprites[Sprites.size() - 1].getPoint(1).y;
	}
	else
	{
		left_y = (max_height + min_height) / 2;
	}
	
	right_x = (rand() % (max_width - min_width)) + min_width;
	
	right_y = left_y + (rand() % height_range) - (height_range / 2);
	if(right_y < max_height)
	{
		right_y = max_height;
	}
	if(right_y > min_height)
	{
		right_y =min_height;
	}
	
	To_Return.setPointCount(4);
	To_Return.setPoint(0, sf::Vector2f(0, left_y));
	To_Return.setPoint(1, sf::Vector2f(right_x, right_y));
	To_Return.setPoint(2, sf::Vector2f(right_x, 0));
	To_Return.setPoint(3, sf::Vector2f(0, 0));
	To_Return.setOrigin(To_Return.getPoint(3));
	To_Return.setPosition(most_eastward_x_coordinate, Default_View_Dimensions.y);
	To_Return.setTexture(Sprite_Sheet);
	To_Return.setTextureRect(Text_Rects[rand() % Text_Rects.size()]);

	return To_Return;
}