/*
"HumanSprite" manages one "TorsoSprite" object, as well as four sf::ConvexShape
objects that represent two legs and two arms, such as movement and setting
global positions.
*/

#pragma once
#include "TorsoSprite.h"
#include <SFML/Graphics.hpp>

class HumanSprite
{
private: TorsoSprite Torso;
private: sf::ConvexShape Left_Arm;
private: sf::ConvexShape Right_Arm;
private: sf::ConvexShape Left_Leg;
private: sf::ConvexShape Right_Leg;
private: sf::ConvexShape Head;

/*Determines the draw order of 'Torso'/limbs.*/
public: enum CardinalOrientation{EAST, WEST};
private: CardinalOrientation Cardinal_Orientation;
public: void setCardinalOrientation(CardinalOrientation);

private: sf::Vector2f Sprite_Position;
public: sf::Vector2f getSpritePosition(){return Sprite_Position;}
public: void setSpritePosition(sf::Vector2f);//destination

private: float speed;
public: float getDisplacement(sf::Time,
			bool
			);
private: float max_displacement_per_frame;
public: HumanSprite(std::string,
			sf::Texture*,
			sf::Vector2f
			);
public: HumanSprite(){};
private: sf::Texture *Sprite_Sheet;
private: std::string Name;
protected: std::string getName(){return Name;}
public: void renderToWindow(sf::RenderWindow&);
private: sf::ConvexShape flipTexture(sf::ConvexShape);
private: void flipAllSpriteTextures();
public: void checkLimbRotation(bool);
private: sf::Clock Movement_Clock;
private: unsigned int movement_time_endpoint;
};