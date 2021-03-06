/*
Branching dialog, a graphic background for the dialog, plus redefinitons of all
virtual Scene functions, except Scene::renderToWindowNonDefault
*/

#pragma once

#include "Scene.h"
#include "URPage.h"
#include "RPage.h"

class DialogScene : public Scene
{
public: DialogScene(sf::Font *Font_, sf::Vector2f Default_View_Dim, HumanCharacter &PC, std::vector<HumanCharacter> &Allies) : Scene(Default_View_Dim)
		{
			Font = Font_;
			Current_Page = new RPage(generatePageId(), Font, PC, Allies, Default_View_Dimensions);
		}
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
private: std::string generatePageId();
//private: sf::RectangleShape Background;
};