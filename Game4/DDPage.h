/*
A cluster of dialog that caters to the needs of "DDScene" : a "Page" class plus 
a boolean function to determine if any Page::RText global bounds contain the 
mouse cursor position; the function 'getNextPageId' inheirited from "Page" is 
redundant, but is inheirited because all other members of "Page" are 
worthwhile, and I don't want a tiny parent class squeezed between "RPage"/
"URPage" and "Page"
*/

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