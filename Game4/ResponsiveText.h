/*
Text that can provide "Effect"'s for PC and allied NPC's, plus an arbitrary 
std::string to be passed into a "RPage"/"URPage" constructor to determine what
Page::RText/Page::URText is declared.
*/

#pragma once

#include "UnresponsiveText.h"
#include "Effects.h"

class ResponsiveText : public UnresponsiveText
{
private: std::string next_page_id;
public: std::string getNextPageId(){return next_page_id;}
public: ResponsiveText(std::string next_page_id_, std::string String, unsigned int font_size, sf::Font *Font, unsigned int line_length_in_pix, sf::Vector2f Top_Left, Effects PC_Effects_, Effects Ally_1_Effects_, Effects Ally_2_Effects_, Effects Ally_3_Effects_) : UnresponsiveText(String, font_size, Font, line_length_in_pix, Top_Left)
		{
			Ally_Effects.push_back(Ally_1_Effects_);
			Ally_Effects.push_back(Ally_2_Effects_);
			Ally_Effects.push_back(Ally_3_Effects_);
			PC_Effects = PC_Effects_;
			next_page_id = next_page_id_;
		}
public: ResponsiveText(std::string next_page_id_, std::string String, unsigned int font_size, sf::Font *Font, unsigned int line_length_in_pix, sf::Vector2f Top_Left) : UnresponsiveText(String, font_size, Font, line_length_in_pix, Top_Left)
		{
			Ally_Effects.resize(3);
			next_page_id = next_page_id_;
		}
private: std::vector<Effects> Ally_Effects;
public: std::vector<Effects> getAllyEffects(){return Ally_Effects;}
private: Effects PC_Effects;
public: Effects getPCEffects(){return PC_Effects;}
};