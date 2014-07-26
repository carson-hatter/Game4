/*
"Scene" is a parent class to "NullScene" (and planned child classes not
implmented as of 7/1/14).
*/

#pragma once
#include <SFML/Graphics.hpp>
#include "SmoothView.h"
#include "HumanCharacter.h"
#include "Foreground.h"

class Scene
{
public: virtual void setView(SmoothView&,//view
			sf::Time//time per frame
			){};
public: virtual void eventHandling(sf::RenderWindow&,//window
			HumanCharacter&,//pc
			sf::Time, // time per frame
			Foreground,
			std::vector<HumanCharacter>&
			){};
public: virtual void renderToWindowDefault(sf::RenderWindow&){};
public: virtual void renderToWindowNonDefault(sf::RenderWindow&){};
public: virtual void processAI(sf::Time,/*Time_Per_Frame*/
			std::vector<HumanCharacter>&,/*Allies*/
			Foreground)/*Foreground_*/
		{};
public: virtual bool sceneOver(){return true;}

protected: float pcs_greatest_eastward_displacement;
public: void setPCsGreatestEastwardDisp(float);//pc's x coord

protected: sf::Vector2f Default_View_Dimensions;
protected: bool westwardBoundsChecking(float);
public: void setDefaultViewDimensions(sf::Vector2f DVD){Default_View_Dimensions = DVD;}

public: Scene(sf::Vector2f);//default view dimensions

protected: float gap_between_chars_in_pix;
};