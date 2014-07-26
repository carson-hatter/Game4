#include "RPage.h"

Effects RPage::getPCEffects(sf::Vector2f Mouse_Pos)
{
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		if(RText[i].getGlobalBounds().contains(Mouse_Pos))
		{
			return RText[i].getPCEffects();
		}
	}

	return Effects();
}

std::vector<Effects> RPage::getAllyEffects(sf::Vector2f Mouse_Pos)
{
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		if(RText[i].getGlobalBounds().contains(Mouse_Pos))
		{
			return RText[i].getAllyEffects();
		}
	}
	std::vector<Effects> To_Return;
	return To_Return;
}

std::string* RPage::getNextPageId(sf::Vector2f Mouse_Pos)
{
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		if(RText[i].getGlobalBounds().contains(Mouse_Pos))
		{
			std::string *S = new std::string;
			*S = RText[i].getNextPageId();
			return S;
		}
	}

	return NULL;
}

bool RPage::clicked(sf::Vector2f Mouse)
{
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		if(RText[i].getGlobalBounds().contains(Mouse))
		{
			return true;
		}
	}

	return false;
}