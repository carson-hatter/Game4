#pragma once

#include "Page.h"

class RPage : public Page
{
public: RPage(std::string id, sf::Font *Font, HumanCharacter &PC, std::vector<HumanCharacter> &Allies) : Page()
		{
			if(id == "r_0")
			{
				Speaker = &PC;
				URText.push_back(UnresponsiveText("Testing dialog scene; page zero", 32, Font, 1400, sf::Vector2f(0,0)));
				RText.push_back(ResponsiveText("r_1", "Go to page one", 32, Font, 1400, sf::Vector2f(0,URText[0].getGlobalBounds().top + URText[0].getGlobalBounds().height + vertical_buffer), Effects(), Effects(), Effects(),Effects()));
				RText.push_back(ResponsiveText("END", "End scene", 32, Font, 1400, sf::Vector2f(0,RText[0].getGlobalBounds().top + RText[0].getGlobalBounds().height + vertical_buffer), Effects(), Effects(), Effects(),Effects()));
			}
			if(id == "r_1")
			{
				Speaker = &Allies[1];
				URText.push_back(UnresponsiveText("Testing page one", 30, Font, 1600, sf::Vector2f(0,0)));
				RText.push_back(ResponsiveText("u_0", "try out URPage,", 30, Font, 1600, sf::Vector2f(0,URText[0].getGlobalBounds().top + URText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));
				RText.push_back(ResponsiveText("END", "Or end scene here", 30, Font, 1600, sf::Vector2f(0,RText[0].getGlobalBounds().top + RText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));
			}		

			initializationCheck(id, Font);
		}
public: RPage(std::string id, sf::Font *Font) : Page()
		{
			Speaker = NULL;

			if(id == "dd_0")
			{

			}

			initializationCheck(id, Font);
		}
public: bool clicked(sf::Vector2f);//mouse
public: std::string* getNextPageId(sf::Vector2f);//mouse
public: Effects getPCEffects(sf::Vector2f);//mouse
public: std::vector<Effects> getAllyEffects(sf::Vector2f);//mouse
};