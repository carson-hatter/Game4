/*
A master class for "Foreground", "Background", "HumanCharacter", 
"SmoothView", and a child class of "Scene".
*/

#pragma once

#include "NullScene.h"
#include "DialogScene.h"
#include "DDScene.h"
#include "Foreground.h"
#include "Background.h"
#include "HumanCharacter.h"
#include "SmoothView.h"

class Game
{
private: Foreground Foreground_;
public: void updateScenery();
private: Background Background_;
private: Scene *Current_Scene;
private: HumanCharacter PC;
private: std::vector<HumanCharacter> Allies;
private: SmoothView View;

private: unsigned int scene_count;

private: sf::Texture *Character_Sprite_Sheet;

public: Game(sf::View);//Window.getDefaultView()

private: sf::Vector2f Default_View_Dimensions;

public: void processScene(sf::Time,//time per frame
			sf::RenderWindow&//window
			);
public: void renderToWindow(sf::RenderWindow&);//window

public: void setPCsGreatestEastwardDisplacement();

public: void sceneChange();

private: unsigned int generateDialogSceneId();

private: std::vector<unsigned int> Dialog_Scenes_Generated;

private: sf::Font *Font;
};