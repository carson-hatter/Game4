#pragma once

#include "Scene.h"
#include "URPage.h"
#include "RPage.h"

class DialogScene : public Scene
{
public: DialogScene(sf::Font *Font_, int id, sf::Vector2f Default_View_Dimensions, HumanCharacter &PC, std::vector<HumanCharacter> &Allies) : Scene(Default_View_Dimensions)
		{
			Font = Font_;
			if(id == 0)
			{
				Current_Page = new RPage("r_0", Font, PC, Allies);
			} 
			Background.setSize(sf::Vector2f(Default_View_Dimensions.x, Default_View_Dimensions.y / 2.5));
			Background.setFillColor(sf::Color::Black);
			Background.setPosition(0,0);
			
			//another_fucking_font = new sf::Font;
			//another_fucking_font->loadFromFile("cour.ttf");
		}
//private: sf::Font *another_fucking_font;
public: void renderToWindowDefault(sf::RenderWindow&);
public: void setView(SmoothView&,
			sf::Time
			);
public: void eventHandling(sf::RenderWindow&,
			HumanCharacter&,//pc
			sf::Time,//time per frame
			Foreground,
			std::vector<HumanCharacter>&//allies
			);
public: void processAI(sf::Time,
			std::vector<HumanCharacter>&,
			Foreground
			);
public: bool sceneOver();

private: sf::Font *Font;
private: Page* Current_Page;
private: sf::RectangleShape Background;
};