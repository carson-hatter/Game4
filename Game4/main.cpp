/*
"Game 4" is a 2D sidescrolling game. The PC will be followed by 3 NPC's, only
moving east (Super Mario style). 
There will be four types of scenes: 
	Null: NPC's follow PC east. Scene ends after a random interval.
	Dialog: sf::View zooms in on speaking character, and PC can observe and 
	interact with dialog. Scene is over when dialog is over
	Discover and Distribute (DD): PC and NPC's travel east until they cross
	an item(s) on the ground, then sf::View zooms in on PC and user chooses
	how to distribute given item(s). Scene is over when items are distributed.
	Fight: A hostile NPC appears and attacks nearest character or character
	that is attacking it. Scene is over when hostile NPC is dead.
The first scene and every other scene will be Null scene. The game will
continue until PC is dead.
Upon any character death, there will be a eulogy given by the surviving
characters.
*/
#include <SFML/Graphics.hpp>
#include "Game.h"
int main()
{
	srand(time(NULL));

    sf::RenderWindow Window(sf::VideoMode(1600, 900), "The Start Of Your Ending");

	Game Game_(Window.getDefaultView());

	sf::Clock Frame_Clock;

	while(Window.isOpen())
	{
		Frame_Clock.restart();

		Game_.sceneChange();

		Game_.updateScenery();

		Game_.setPCsGreatestEastwardDisplacement();

		Game_.processScene(Frame_Clock.getElapsedTime(), Window);

		Game_.renderToWindow(Window);
	}

}