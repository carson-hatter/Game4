#pragma once

#include "Scene.h"
#include "RPage.h"

class DDScene : public Scene
{
public: DDScene(Foreground F_Ground, sf::Font *Font_, sf::Vector2f Default_View_Dimensions, unsigned int number_of_chars) : Scene(Default_View_Dimensions)
		{
			null_to_dd_view_ratio = (number_of_chars * abs(gap_between_chars_in_pix)) / Default_View_Dimensions.x;
			DD_Page = NULL;
			Font = Font_;

			sf::Vector2f Item_Position;
			Item_Position = F_Ground.getValidCoord(F_Ground.getMostEastwardCoordinate());

			Item_To_DD = new sf::ConvexShape();
			Item_To_DD->setPointCount(4);
			Item_To_DD->setPoint(0, sf::Vector2f(0,0));
			Item_To_DD->setPoint(1, sf::Vector2f(100,0));
			Item_To_DD->setPoint(2, sf::Vector2f(100,100));
			Item_To_DD->setPoint(3, sf::Vector2f(0,100));
			Item_To_DD->setFillColor(sf::Color::Magenta);
			Item_To_DD->setOrigin(Item_To_DD->getLocalBounds().width / 2, Item_To_DD->getLocalBounds().height / 2);
			Item_To_DD->setPosition(Item_Position);
		}
public: void setView(SmoothView&,
			sf::Time
			);
public: void eventHandling(sf::RenderWindow&,
			HumanCharacter&,
			sf::Time,
			Foreground,
			std::vector<HumanCharacter>&
			);
public: void renderToWindowDefault(sf::RenderWindow&);
public: void renderToWindowNonDefault(sf::RenderWindow&);
public: void processAI(sf::Time,
			std::vector<HumanCharacter>&,
			Foreground
			);
public: bool sceneOver();

private: sf::ConvexShape *Item_To_DD;
private: bool itemDiscovered();
private: bool itemDistributed();
private: float null_to_dd_view_ratio;
private: RPage *DD_Page;
private: sf::Font *Font;
private: std::string generateDDPageId();
		 //private: float posse_width = gap between chars * number of chars / 2
};