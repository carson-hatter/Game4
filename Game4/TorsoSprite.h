/*
"TorsoSprite" manages the sf::RectangleShape that repsents a character's torso,
such as where the origin points of each arm and leg should be (One virtue 
of this class is that the character inheiriting "TorsoSprite" would be a bi-
pedal animal).
*/

#pragma once

#include <SFML/Graphics.hpp>

class TorsoSprite
{
private: sf::RectangleShape Sprite;
public: sf::Vector2f getHeadJoint();
public: sf::RectangleShape getSprite(){return Sprite;}
public: sf::Vector2f getLeftArmJt();
public: sf::Vector2f getRightArmJt();
public: sf::Vector2f getLeftLegJt();
public: sf::Vector2f getRightLegJt();
public: TorsoSprite(sf::Texture*,//char sprt sht
			sf::IntRect,//txt rect
			sf::Vector2f,//sprite dim
			unsigned int//y differential
			);
public: TorsoSprite(){};
public: void setPosition(sf::Vector2f);
public: void flipTexture();
private: unsigned int y_differential;
};