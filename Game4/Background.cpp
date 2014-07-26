#include "Background.h"



void Background::erase()
{
	if(!Sprites.empty())
	{
		float sprites_greatest_x_value = Sprites[0].getGlobalBounds().left + Sprites[0].getGlobalBounds().width;

		while(sprites_greatest_x_value <= 0)
		{
			Sprites.erase(Sprites.begin());

			sprites_greatest_x_value = Sprites[0].getGlobalBounds().left + Sprites[0].getGlobalBounds().width;
		}
	}
}

void Background::pushBack()
{
	if(!Sprites.empty())
	{
		float last_sprites_greatest_x_value = Sprites[Sprites.size() - 1].getGlobalBounds().left + Sprites[Sprites.size() - 1].getGlobalBounds().width;
		
		while(last_sprites_greatest_x_value <= Default_View_Dimensions.x)
		{
			Sprites.push_back(createSprite(last_sprites_greatest_x_value));
			
			incrementTextRectsIter();
			
			last_sprites_greatest_x_value = Sprites[Sprites.size() - 1].getGlobalBounds().left + Sprites[Sprites.size() - 1].getGlobalBounds().width;
		}
	}
}

void Background::incrementTextRectsIter()
{
	text_rects_iterator++;

	if(text_rects_iterator >= Text_Rects.size())
	{
		text_rects_iterator = 0;
	}
}
sf::ConvexShape Background::createSprite(float last_sprites_greatest_x_value)
{
	float sprite_width = 4000;
	float sprite_height = Default_View_Dimensions.y;

	sf::ConvexShape Sprite;
	Sprite.setPointCount(4);
	Sprite.setPoint(0, sf::Vector2f(0,0));
	Sprite.setPoint(1, sf::Vector2f(sprite_width,0));
	Sprite.setPoint(2, sf::Vector2f(sprite_width, sprite_height));
	Sprite.setPoint(3, sf::Vector2f(0, sprite_height));
	Sprite.setTexture(Sprite_Sheet);
	Sprite.setTextureRect(Text_Rects[text_rects_iterator]);
	Sprite.setOrigin(Sprite.getPoint(0));
	Sprite.setPosition(last_sprites_greatest_x_value, 0);

	return Sprite;
}

void Background::shift(float pcs_current_displacement)
{
	float displacements_diff = pcs_current_displacement - pcs_displacement_at_last_shift;
	
	int distance_between_shifts = 1;
	
	unsigned int max_difference_between_displacements = 100;
	
	if(displacements_diff >= max_difference_between_displacements)
	{
		for(unsigned int i = 0; i < Sprites.size(); i++)
		{
			Sprites[i].move(-distance_between_shifts, 0);
		}

		pcs_displacement_at_last_shift = pcs_current_displacement;
	}

	erase();
	pushBack();
}