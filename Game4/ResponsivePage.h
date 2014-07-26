#pragma once

#include "Page.h"

class ResponsivePage : public Page
{
public: ResponsivePage(std::string id_, sf::Font *Font, HumanCharacter &PC, std::vector<HumanCharacter> &Allies):Page(id_, Font, PC, Allies)
		{
			
		}
public: void renderToWindow(sf::RenderWindow&);//window
//public: bool responsiveTextClicked(sf::Vector2f);//mouse
public: std::string getNextPageId(sf::Vector2f);
public: std::vector<Effects> getAllyEffects(sf::Vector2f);//mouse
public: Effects getPCEffects(sf::Vector2f);//mouse
}