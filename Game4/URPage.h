#pragma once

#include "Page.h"

class URPage : public Page
{
public: URPage(std::string id, sf::Font *Font, HumanCharacter &PC, std::vector<HumanCharacter> &Allies) : Page()
		{
			Allies_Effects.resize(3);

			if(id == "u_0")
			{
				Speaker = &Allies[0];
				URText.push_back(UnresponsiveText("Testing URPage zero", 30, Font, 1600, sf::Vector2f(0,0)));
				time_limit = 1.5;
				Clock.restart();
				Next_Page_Id = new std::string;
				*Next_Page_Id = "u_1";
/*				RText.push_back(ResponsiveText("u_0", "try out URPage,", 30, Font, 1600, sf::Vector2f(0,URText[0].getGlobalBounds().top + URText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));
				RText.push_back(ResponsiveText("END", "Or end scene here", 30, Font, 1600, sf::Vector2f(0,RText[0].getGlobalBounds().top + RText[0].getGlobalBounds().height + vertical_buffer), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0), Effects(0,0,0,0,0,0,0,0),Effects(0,0,0,0,0,0,0,0)));		*/		
			}
			if(id == "u_1")
			{
				Speaker = &Allies[2];
				URText.push_back(UnresponsiveText("Testing URPage one", 30, Font, 1600, sf::Vector2f(0,0)));
				time_limit = 1.5;
				Clock.restart();
				Next_Page_Id = new std::string;
				*Next_Page_Id = "END";
			}

			initializationCheck(id, Font);
		}
public: std::string *getNextPageId(sf::Vector2f);//mouse
//public: Effects getPCEffects(sf::Vector2f);//mouse
//public: std::vector<Effects> getAllyEffects(sf::Vector2f);//mouse

private: sf::Clock Clock;
private: float time_limit;
private: std::string *Next_Page_Id;
//private: Effects PC_Effects;
//private: std::vector<Effects> Allies_Effects;
};