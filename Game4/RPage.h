/*
A "Page" that represents the user choosing either the next branch of dialog in a "DialogScene" or which "Effects" will be applied to Game::PC and Game::NPCs in a "DDScene".
*/

#pragma once

#include "Page.h"

class RPage : public Page
{
public: RPage(std::string id, sf::Font *Font, HumanCharacter &PC, std::vector<HumanCharacter> &Allies, sf::Vector2f View_Dimensions) : Page()
		{
			if(id == "dd_0")
			{
				Speaker = NULL;
				URText.push_back(UnresponsiveText("Testing Discover and Distribute scene; page zero", 32, Font, View_Dimensions.x, sf::Vector2f(0,0)));
				RText.push_back(ResponsiveText("END", "Make PC Hungry", 32, Font, View_Dimensions.x, sf::Vector2f(0, URText.back().getGlobalBounds().top + URText.back().getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,-50,0,0,0), Effects(), Effects(), Effects()));
				RText.push_back(ResponsiveText("END", "Make Ally 2 Hungry", 32, Font, View_Dimensions.x, sf::Vector2f(0, RText.back().getGlobalBounds().top + RText.back().getGlobalBounds().height + vertical_buffer), Effects(), Effects(), Effects(0,0,0,0,-50,0,0,0), Effects()));
			}
			if(id == "r_0")
			{
				Speaker = &PC;
				URText.push_back(UnresponsiveText("Testing dialog scene; page zero", 32, Font, 1400, sf::Vector2f(0,0)));
				RText.push_back(ResponsiveText("r_1", "Go to page one", 32, Font, 1400, sf::Vector2f(0,URText.back().getGlobalBounds().top + URText.back().getGlobalBounds().height + vertical_buffer), Effects(), Effects(), Effects(),Effects()));
				RText.push_back(ResponsiveText("END", "End scene", 32, Font, 1400, sf::Vector2f(0,RText.back().getGlobalBounds().top + RText.back().getGlobalBounds().height + vertical_buffer), Effects(), Effects(), Effects(),Effects()));
			}
			if(id == "r_1")
			{
				Speaker = &Allies[1];
				URText.push_back(UnresponsiveText("Testing page one", 30, Font, 1600, sf::Vector2f(0,0)));
				RText.push_back(ResponsiveText("u_0", "try out URPage,", 30, Font, 1600, sf::Vector2f(0,URText.back().getGlobalBounds().top + URText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));
				RText.push_back(ResponsiveText("END", "Or end scene here", 30, Font, 1600, sf::Vector2f(0,RText.back().getGlobalBounds().top + RText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));
			}		

			initializationCheck(id, Font);

			resizeBackground(View_Dimensions);
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