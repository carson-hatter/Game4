/*
"NullScene" is a child class of "Scene". The scene only lasts a random duration,
regardless of how far PC travels. NPCs stand a certain distance west of PC's
greatest eastward displacement.
*/

#pragma once
#include "Scene.h"

class NullScene : public Scene
{
////////////////////////INHEIRITED FUCNTIONS//////////////////////////////////
public: void setView(SmoothView&, // view
			sf::Time// time per fram
			);
public: void eventHandling(sf::RenderWindow&,//window
			HumanCharacter&,//pc
			sf::Time, //time per frame
			Foreground,
			std::vector<HumanCharacter>&//allies
			);
public: void processAI(sf::Time,
			std::vector<HumanCharacter>&,
			Foreground
			);
public: bool sceneOver(){if(Clock.getElapsedTime().asSeconds() < duration){return false;}return true;}
//////////////////////////////////////////////////////////////////////////////

public: NullScene(sf::Vector2f Window_Dimensions_):Scene(Window_Dimensions_)
		{
			duration = rand() % 5 + 5;
		};

private: sf::Clock Clock;
private: unsigned int duration;
};