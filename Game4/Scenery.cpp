#include "Scenery.h"

void Scenery::renderToWindow(sf::RenderWindow &Window)
{
	for(unsigned int i = 0; i < Sprites.size(); i++)
	{
		Window.draw(Sprites[i]);
	}
}

Scenery::Scenery(sf::Vector2f Default_View_Dimensions_)
{
	Default_View_Dimensions = Default_View_Dimensions_;
}