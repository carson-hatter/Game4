#include "Page.h"

Page::Page()
{
	vertical_buffer = 10;
}

void Page::renderToWindow(sf::RenderWindow &Window)
{
	Window.draw(Background);

	for(unsigned int i = 0; i < URText.size(); i++)
	{
		URText[i].renderToWindow(Window);
	}
	for(unsigned int i = 0; i < RText.size(); i++)
	{
		RText[i].renderToWindow(Window);
	}
}

void Page::resizeBackground(sf::Vector2f View_Dimensions)
{
	Background.setPosition(0,0);
	Background.setOrigin(0,0);
	Background.setSize(sf::Vector2f(View_Dimensions.x, View_Dimensions.y / 3));
	Background.setFillColor(sf::Color::Black);
}

//bool Page::responsiveTextClicked(sf::Vector2f Mouse)
//{
//	for(unsigned int i = 0; i < RText.size(); i++)
//	{
//		if(RText[i].getGlobalBounds().contains(Mouse))
//		{
//			std::cout<<i<<std::endl;
//			return true;
//		}
//	}
//	return false;
//}

//std::string Page::getNextPageIdViaMouse(sf::Vector2f Mouse)
//{
//	for(unsigned int i = 0; i < RText.size(); i++)
//	{
//		if(RText[i].getGlobalBounds().contains(Mouse))
//		{
//			return RText[i].getNextPageId();
//		}
//	}
//
//	return "END";
//}

//std::string* Page::getNextPageIdViaTime()
//{
//	if(time_limit >= Clock.getElapsedTime().asSeconds())
//	{
//		return Next_Page_Id;
//	}
//
//	return NULL;
//}
//

void Page::initializationCheck(std::string Id, sf::Font *Font)
{
	if((RText.empty()) && (URText.empty()))
	{
		std::string S = "ERROR: \"Page\" object wasn't initialized properly; target id was: ";
		S.append(Id);
		RText.push_back(ResponsiveText("END", S, 18, Font, 1600, sf::Vector2f(0,0)));
	}
}

std::string* Page::getNextPageId(sf::Vector2f Mouse)
{
	return NULL;
}

//std::vector<Effects> Page::getAllyEffects(sf::Vector2f Mouse)
//{
//	std::vector<Effects> To_Return;
//
//	return To_Return;
//}
////
//Effects Page::getPCEffects(sf::Vector2f Mouse)
//{
//	Effects To_Return;
//
//	return To_Return;
//}