#include "NullScene.h"

void NullScene::setView(SmoothView &View, sf::Time Time_Per_Frame)
{
	View.move(sf::Vector2f(pcs_greatest_eastward_displacement, Default_View_Dimensions.y / 2),Time_Per_Frame);
	View.zoom(1, Time_Per_Frame);
}

void NullScene::eventHandling(sf::RenderWindow &Window, HumanCharacter &PC, sf::Time Time_Per_Frame, Foreground Foreground_, std::vector<HumanCharacter> &Allies)
{
	sf::Vector2f Temp(PC.getSpritePosition());

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		float displacement = PC.getDisplacement(Time_Per_Frame, false);
		Temp = sf::Vector2f(Foreground_.getValidCoord(PC.getSpritePosition().x + displacement));
		if(!westwardBoundsChecking(Temp.x))
		{
			Temp.x = pcs_greatest_eastward_displacement - (Default_View_Dimensions.x / 2);
		}
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		float displacement = PC.getDisplacement(Time_Per_Frame, true);
		Temp = sf::Vector2f(Foreground_.getValidCoord(PC.getSpritePosition().x + displacement));
	}

	PC.setSpritePosition(Temp);

	sf::Event Event;

	while(Window.pollEvent(Event))
	{
		if(Event.type == sf::Event::Closed)
		{
	        Window.close();
		}
	}
}

void NullScene::processAI(sf::Time Time_Per_Frame, std::vector<HumanCharacter>& Allies, Foreground Foreground_)
{
	std::vector<float> Destinations;

	Destinations.push_back(pcs_greatest_eastward_displacement + gap_between_chars_in_pix);
	Destinations.push_back(pcs_greatest_eastward_displacement + (2 * gap_between_chars_in_pix));
	Destinations.push_back(pcs_greatest_eastward_displacement + (3 * gap_between_chars_in_pix));

	for(unsigned int i = 0; i < Allies.size(); i++)
	{	
		float x_diff = Allies[i].getSpritePosition().x - Destinations[i];

		if(abs(x_diff) > 1)
		{
			float displacement = 0;
			if(Destinations[i] < Allies[i].getSpritePosition().x)
			{
				displacement = Allies[i].getDisplacement(Time_Per_Frame, false);
			}
			if(Destinations[i] > Allies[i].getSpritePosition().x)
			{
				displacement = Allies[i].getDisplacement(Time_Per_Frame, true);
			}
			float temp_x_coord = displacement + Allies[i].getSpritePosition().x;

			Allies[i].setSpritePosition(Foreground_.getValidCoord(Allies[i].getSpritePosition().x + displacement));
		}
		else
		{
			Allies[i].setSpritePosition(Allies[i].getSpritePosition());
		}
	}
}
