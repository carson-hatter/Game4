#pragma once

#include "Page.h"

class DDPage : public Page
{
public: DDPage(std::string id, sf::Font *Font) : Page()
		{
			if(id == "dd_0")
			{
				
			}

			initializationCheck(id, Font);
		}
public: bool clicked(sf::Vector2f);//mouse
};