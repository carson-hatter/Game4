#pragma once

#include<string>
#include<vector>

class TextLengthFormatting
{
public: static std::vector<std::string> FormatLength (int font_size,
			   int length_in_pix, std::string Input)
		   {
				int characters_per_line = length_in_pix / font_size;

				std::vector<std::string> To_Return;

				int prev_white_space_index = 0;
				int prev_line_break_index = 0;

				for(unsigned int i = 0; i < Input.size(); i++)
				{
					if(Input.at(i) == ' ')
					{
						prev_white_space_index = i;
					}
					if(i - prev_line_break_index >= characters_per_line)
					{
						To_Return.push_back(Input.substr(prev_line_break_index, prev_white_space_index - prev_line_break_index));
						prev_line_break_index = prev_white_space_index;
					}
				}

				To_Return.push_back(Input.substr(prev_line_break_index, Input.size()));

				return To_Return;
		   }
};