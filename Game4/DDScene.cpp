#include "DDScene.h"

void DDScene::renderToWindowNonDefault(sf::RenderWindow &Window)
{
	if(Item_To_DD)
	{
		Window.draw(*Item_To_DD);
	}
}

void DDScene::renderToWindowDefault(sf::RenderWindow &Window)
{
	if(DD_Page)
	{
		DD_Page->renderToWindow(Window);
	}
}

void DDScene::setView(SmoothView &View, sf::Time Time_Per_Frame)
{
	if(itemDiscovered())
	{
		View.move(sf::Vector2f(pcs_greatest_eastward_displacement, Default_View_Dimensions.y / 2),Time_Per_Frame);
		View.zoom(null_to_dd_view_ratio, Time_Per_Frame);		
	}
	else
	{
		View.move(sf::Vector2f(pcs_greatest_eastward_displacement, Default_View_Dimensions.y / 2),Time_Per_Frame);
		View.zoom(1, Time_Per_Frame);		
	}
}

void DDScene::eventHandling(sf::RenderWindow &Window, HumanCharacter &PC, sf::Time Time_Per_Frame, Foreground Foreground_, std::vector<HumanCharacter> &Allies)
{
	if(!itemDiscovered())
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

		setPCsGreatestEastwardDisp(PC.getSpritePosition().x);

		if(itemDiscovered())
		{
			if(DD_Page)
			{
				delete DD_Page;
			}
			DD_Page = new RPage(generateDDPageId() ,Font);
		}
	}

	sf::Event Event;
	while(Window.pollEvent(Event))
	{
		if(Event.type == sf::Event::Closed)
		{
			Window.close();
		}
		
		//if(itemDiscovered())
		//{
			if(Event.type == sf::Event::MouseButtonReleased)
			{
				if(DD_Page)
				{
					sf::Vector2f Mouse_Pos(sf::Mouse::getPosition(Window));

					if(DD_Page->clicked(Mouse_Pos))
					{
						for(unsigned int i = 0; i < Allies.size(); i++)
						{
							Allies[i].applyEffects(DD_Page->getAllyEffects(Mouse_Pos).at(i));
						}

						PC.applyEffects(DD_Page->getPCEffects(Mouse_Pos));

						delete DD_Page;
						DD_Page = NULL;
						delete Item_To_DD;
						Item_To_DD = NULL;
					}
				}
			}
		//}	
	}
}

std::string DDScene::generateDDPageId()
{
	return "dd_0";
}

void DDScene::processAI(sf::Time Time_Per_Frame, std::vector<HumanCharacter> &Allies, Foreground Foreground_)
{
	if(itemDiscovered())
	{
		for(unsigned int i = 0; i < Allies.size(); i++)
		{
			if(pcs_greatest_eastward_displacement < Allies[i].getSpritePosition().x)
			{
				Allies[i].setCardinalOrientation(HumanSprite::CardinalOrientation::WEST);
			}
			if(pcs_greatest_eastward_displacement > Allies[i].getSpritePosition().x)
			{
				Allies[i].setCardinalOrientation(HumanSprite::CardinalOrientation::EAST);
			}
		}
	}
	else
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
}

bool DDScene::sceneOver()
{
	if(itemDistributed())
	{
		return true;
	}
	return false;
}

bool DDScene::itemDistributed()
{
	if(itemDiscovered() && !DD_Page)
	{
		return true;
	}
	return false;
}

bool DDScene::itemDiscovered()
{
	if(Item_To_DD)
	{
			if(pcs_greatest_eastward_displacement > Item_To_DD->getPosition().x)
			{
				return true;
			}
			return false;
	}
	return true;
}