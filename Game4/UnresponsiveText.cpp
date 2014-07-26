#include "UnresponsiveText.h"

UnresponsiveText::UnresponsiveText(std::string String, unsigned int font_size, sf::Font *Font, unsigned int line_length, sf::Vector2f Top_Left)
{
	std::vector<std::string> Formatted_Text = TextLengthFormatting::FormatLength(font_size, line_length, String);
	Text.resize(Formatted_Text.size());
	float max_width = 0;
	float height = 0;
	for(unsigned int i = 0; i < Text.size(); i++)
	{
		Text[i].setCharacterSize(font_size);
		Text[i].setFont(*Font);
		Text[i].setString(Formatted_Text.at(i));
		Text[i].setColor(sf::Color::Red);
		Text[i].setPosition(sf::Vector2f(Top_Left.x, Top_Left.y + height));
		
		if(Text[i].getGlobalBounds().width > max_width)
		{
			max_width = Text[i].getGlobalBounds().width;
		}

		height += Text[i].getGlobalBounds().height;
	}
	Global_Bounds.top = Top_Left.y;
	Global_Bounds.left = Top_Left.x;
	Global_Bounds.width = max_width;
	Global_Bounds.height = (Text.back().getGlobalBounds().top + Text.back().getGlobalBounds().height) - Top_Left.y;
}

void UnresponsiveText::renderToWindow(sf::RenderWindow &Window)
{
	for(unsigned int i = 0; i < Text.size(); i++)
	{
		
		Window.draw(Text[i]);
	}
}