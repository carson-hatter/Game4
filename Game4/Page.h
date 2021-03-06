/*
A vector of text which doesn't respond to mouse clicks; a vector of text 
which responds to mouse clicks with "Effect"'s; a 'Speaker', which Game::View
centers and zooms in on.
*/

#pragma once

#include "ResponsiveText.h"
#include "HumanCharacter.h"

class Page
{
protected: std::vector<UnresponsiveText> URText;
protected: std::vector<ResponsiveText> RText;
protected: HumanCharacter *Speaker;
private: sf::RectangleShape Background;
public: sf::Vector2f getSpeakerPosition(){return Speaker->getSpritePosition();}
public: Page();
protected: float vertical_buffer;
public: void renderToWindow(sf::RenderWindow&);//window
public: virtual std::string *getNextPageId(sf::Vector2f);//mouse
public: virtual std::vector<Effects> getAllyEffects(sf::Vector2f M){return Allies_Effects;}
public: virtual Effects getPCEffects(sf::Vector2f M){return PC_Effects;}
protected: Effects PC_Effects;
protected: std::vector<Effects> Allies_Effects;
protected: void initializationCheck(std::string,//id
			   sf::Font*//font
			   );
protected: void resizeBackground(sf::Vector2f // view dimensions
			   );
};