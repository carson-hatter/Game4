#include "DDPage.h"

bool DDPage::clicked(sf::Vector2f Mouse_Pos)
{
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		if(RText[i].getGlobalBounds().contains(Mouse_Pos))
		{
			return true;
		}
	}

	return false;
}