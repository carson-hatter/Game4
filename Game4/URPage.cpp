#include "URPage.h"

std::string* URPage::getNextPageId(sf::Vector2f Mouse_Pos)
{
	if(Clock.getElapsedTime().asSeconds() >= time_limit)
	{
		return Next_Page_Id;
	}
	return NULL;
}

//Effects URPage::getPCEffects(sf::Vector2f Mouse_Pos)
//{
//	return PC_Effects;
//}
//
//std::vector<Effects> URPage::getAllyEffects(sf::Vector2f Mouse_Pos)
//{
//	return Allies_Effects;
//}