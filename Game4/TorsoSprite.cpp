#include "TorsoSprite.h"

TorsoSprite::TorsoSprite(sf::Texture *Sprite_Sheet, sf::IntRect Txt_Rect, sf::Vector2f Sprite_Dim, unsigned int y_differential_)
{
	Sprite.setSize(Sprite_Dim);
	Sprite.setTexture(Sprite_Sheet);
	Sprite.setTextureRect(Txt_Rect);
	Sprite.setOrigin(Sprite.getSize().x / 2, Sprite.getSize().y / 2);
	y_differential = y_differential_;
}

void TorsoSprite::flipTexture()
{
	Sprite.setTextureRect(sf::IntRect(Sprite.getTextureRect().left + Sprite.getTextureRect().width,
		Sprite.getTextureRect().top,
		-(Sprite.getTextureRect().width),
		Sprite.getTextureRect().height
		));
}

void TorsoSprite::setPosition(sf::Vector2f Target)
{
	Sprite.setPosition(Target.x , Target.y - y_differential);
}

sf::Vector2f TorsoSprite::getLeftArmJt()
{
	float local_x = Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width * .9;
	float local_y = Sprite.getGlobalBounds().top + Sprite.getGlobalBounds().height * .1;
	return sf::Vector2f(local_x, local_y);
}

sf::Vector2f TorsoSprite::getLeftLegJt()
{
	float local_x = Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width * .9;
	float local_y = Sprite.getGlobalBounds().top + Sprite.getGlobalBounds().height * .9;
	return sf::Vector2f(local_x, local_y);
}

sf::Vector2f TorsoSprite::getRightArmJt()
{
	float local_x = Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width * .1;
	float local_y = Sprite.getGlobalBounds().top + Sprite.getGlobalBounds().height * .1;
	return sf::Vector2f(local_x, local_y);
}

sf::Vector2f TorsoSprite::getRightLegJt()
{
	float local_x = Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width * .1;
	float local_y = Sprite.getGlobalBounds().top + Sprite.getGlobalBounds().height * .9;
	return sf::Vector2f(local_x, local_y);
}

sf::Vector2f TorsoSprite::getHeadJoint()
{
	float local_x = Sprite.getGlobalBounds().left + Sprite.getGlobalBounds().width * .5;
	float local_y = Sprite.getGlobalBounds().top;
	return sf::Vector2f(local_x, local_y);
}