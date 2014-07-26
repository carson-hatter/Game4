/*
"SmoothView" is a wrapper class for sf::View, giving functions and 
variables to make the movment and zooming of sf::View happen over time.
*/
#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>

class SmoothView
{
private: sf::View View;
public: void move(sf::Vector2f, //Desired position
			sf::Time);//time per frame
public: sf::FloatRect getGlobalBounds();
public: void zoom(float,//desired zoom level
			sf::Time);//time per frame
private: sf::Vector2f Default_Size;
public: sf::Vector2f getDefaultSize(){return Default_Size;}
public: sf::View getView(){return View;}
public: SmoothView(sf::View);//default view
public: SmoothView(){};
};