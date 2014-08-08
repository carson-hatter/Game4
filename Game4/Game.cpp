#include "Game.h"
#include "Exception.h"

Game::Game(sf::View Default_View)
{
	View = SmoothView(Default_View);
	Character_Sprite_Sheet = new sf::Texture;
	Character_Sprite_Sheet->loadFromFile("character_sprite_sheet.jpg");
	Default_View_Dimensions = Default_View.getSize();
	Foreground_ = Foreground(View.getDefaultSize());
	Background_ = Background(View.getDefaultSize());
	PC = HumanCharacter("Carson", Character_Sprite_Sheet, sf::Vector2f(Foreground_.getValidCoord(View.getDefaultSize().x / 2)));
	Allies.push_back(HumanCharacter("Adam", Character_Sprite_Sheet, sf::Vector2f(Foreground_.getValidCoord(200))));
	Allies.push_back(HumanCharacter("Bill", Character_Sprite_Sheet, sf::Vector2f(Foreground_.getValidCoord(200))));
	Allies.push_back(HumanCharacter("Zane", Character_Sprite_Sheet, sf::Vector2f(Foreground_.getValidCoord(200))));
	
	Current_Scene = new NullScene(View.getDefaultSize());

	scene_count = 1;

	Font = new sf::Font;
	Font->loadFromFile("cour.ttf");
}

void Game::sceneChange()
{
	if(Current_Scene)
	{
		while(Current_Scene->sceneOver())
		{
			delete Current_Scene;

			if(scene_count % 2 == 0)
			{
				Current_Scene = new NullScene(View.getDefaultSize());
			}
			else
			{
				unsigned int number_of_scene_possibilities = 1;
				unsigned int scene_type_index = rand() % number_of_scene_possibilities;

				//if(scene_type_index == 0)
				//{
				//	unsigned int first_scene_id = getSceneId();
				//	Current_Scene = new DialogScene(Font, 0, View.getDefaultSize(), PC, Allies);
				//	for(unsigned int i = 0; i < Allies.size(); i++)
				//	{
				//		Allies[i].setSpritePosition(Allies[i].getSpritePosition());
				//	}
				//	PC.setSpritePosition(PC.getSpritePosition());
				//}
				if(scene_type_index == 0)
				{
					Current_Scene = new DDScene(Foreground_, Font, View.getDefaultSize(), 4);
					//Current_Scene = new DialogScene(Font, View.getDefaultSize(), PC, Allies);
				}
			}
			scene_count++;
		}
	}
}

unsigned int Game::generateDialogSceneId()
{
	/*
	TODO: look at PC and Allies' cognitive and physiological effects and determine
	which dialog scene should play; don't forget to check if the scene has already
	been chosen
	*/

	unsigned int to_return;



	return to_return;
}

void Game::updateScenery()
{
	Background_.shift(PC.getSpritePosition().x);
	Foreground_.setPCsGreatestEastwardDisplacement(PC.getSpritePosition().x);
}

void Game::setPCsGreatestEastwardDisplacement()
{
	Current_Scene->setPCsGreatestEastwardDisp(PC.getSpritePosition().x);
}

void Game::processScene(sf::Time Time_Per_Frame, sf::RenderWindow &Window)
{
	if(Current_Scene)
	{
		Current_Scene->eventHandling(Window, PC, Time_Per_Frame, Foreground_, Allies);
		Current_Scene->setView(View, Time_Per_Frame);
		Current_Scene->processAI(Time_Per_Frame, Allies, Foreground_);
	}
}

void Game::renderToWindow(sf::RenderWindow &Window)
{
	Window.clear();

	Window.setView(Window.getDefaultView());

	Background_.renderToWindow(Window);

	if(Current_Scene)
	{
		Current_Scene->renderToWindowDefault(Window);
	}

	Window.setView(View.getView());

	if(Current_Scene)
	{
		Current_Scene->renderToWindowNonDefault(Window);
	}

	Foreground_.renderToWindow(Window);

	for(unsigned int i = 0; i < Allies.size();i++)
	{
		Allies[i].renderToWindow(Window);
	}

	PC.renderToWindow(Window);

	Window.display();
}