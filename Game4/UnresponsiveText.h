#pragma once

#include <SFML/Graphics.hpp>
#include "TextLengthFormatting.h"
#include <iostream>

class UnresponsiveText
{
public: UnresponsiveText(std::string, //Input,
			unsigned int, //font_size,
			sf::Font*, //Font,
			unsigned int, //max_line_length
			sf::Vector2f//global top left
			); 
private: std::vector<sf::Text> Text;
public: void renderToWindow(sf::RenderWindow&);
private: sf::FloatRect Global_Bounds;
public: bool isClicked(sf::Vector2f Mouse){if(Global_Bounds.contains(Mouse))return true; return false;}
public: sf::FloatRect getGlobalBounds(){return Global_Bounds;}
};