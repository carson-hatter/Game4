#include "DialogScene.h"

void DialogScene::eventHandling(sf::RenderWindow &Window, HumanCharacter &PC, sf::Time Time_Per_Frame, Foreground Foreground_, std::vector<HumanCharacter> &Allies)
{
	sf::Event Event;
	while(Window.pollEvent(Event))
	{
		if(Event.type == sf::Event::Closed)
		{
			Window.close();
		}

		if(Event.type == sf::Event::MouseButtonReleased)
		{
			if(Current_Page)
			{
				//comp this
				sf::Vector2f Speaker_Pos = Current_Page->getSpeakerPosition();

				if(Speaker_Pos.x <= PC.getSpritePosition().x)
				{
					PC.setCardinalOrientation(HumanSprite::CardinalOrientation::WEST);
				}
				else
				{
					PC.setCardinalOrientation(HumanSprite::CardinalOrientation::EAST);
				}
				//-------------------------

				sf::Vector2f Mouse_Pos(sf::Mouse::getPosition(Window));

				//if page clicked.... and toss out "if(NextPageId)"
				std::string *Next_Page_Id;
				Next_Page_Id = Current_Page->getNextPageId(Mouse_Pos);
				if(Next_Page_Id)
				{
					for(unsigned int i = 0; i < Allies.size(); i++)
					{
						Allies[i].applyEffects(Current_Page->getAllyEffects(Mouse_Pos).at(i));
					}
					PC.applyEffects(Current_Page->getPCEffects(Mouse_Pos));
					
					delete Current_Page;
					Current_Page = NULL;
					
					if(Next_Page_Id->at(0) == 'r')
					{
						Current_Page = new RPage(*Next_Page_Id, Font, PC, Allies);
					}
					if(Next_Page_Id->at(0) == 'u')
					{
						Current_Page = new URPage(*Next_Page_Id, Font, PC, Allies);
					}
				}
			}
		}
	}
}

void DialogScene::renderToWindowDefault(sf::RenderWindow &Window)
{
	if(Current_Page)
	{
		Window.draw(Background);
		Current_Page->renderToWindow(Window);
	}
}

void DialogScene::processAI(sf::Time Time_Per_Frame, std::vector<HumanCharacter> &Allies, Foreground Foreground_)
{
	if(Current_Page)
	{
		sf::Vector2f Speaker_Pos = Current_Page->getSpeakerPosition();
		
		for(unsigned int i = 0; i < Allies.size(); i++)
		{
			if(Speaker_Pos.x < Allies[i].getSpritePosition().x)
			{
				Allies[i].setCardinalOrientation(HumanSprite::CardinalOrientation::WEST);
			}
			if(Speaker_Pos.x > Allies[i].getSpritePosition().x)
			{
				Allies[i].setCardinalOrientation(HumanSprite::CardinalOrientation::EAST);
			}
		}
	}
}

bool DialogScene::sceneOver()
{
	if(Current_Page)
	{
		return false;
	}
	return true;
}

void DialogScene::setView(SmoothView &View, sf::Time Time_Per_Frame)
{
	if(Current_Page)
	{
		View.zoom(0.33, Time_Per_Frame);
		
		View.move(Current_Page->getSpeakerPosition(), Time_Per_Frame);
	}
}