#include "HumanSprite.h"

HumanSprite::HumanSprite(std::string Name_, sf::Texture *Sprite_Sheet_, sf::Vector2f Initial_Pos)
{
	Cardinal_Orientation = EAST;

	sf::IntRect Torso_Text_Rect, Rt_Arm_Text_Rect, Lf_Arm_Text_Rect,
		Rt_Leg_Text_Rect, Lf_Leg_Text_Rect, Head_Text_Rect;
	
	unsigned int torso_width, torso_height, arm_width, arm_height,
		leg_width, leg_height, head_width;

	float max_torso_height = 100;
	float limb_torso_ratio = 0.95;
	float max_movement_time_endpoint = 500;

	if(Name_ == "Carson")
	{
		torso_width = 36;
		torso_height = 100;
		arm_width = torso_width / 3;
		arm_height = torso_height *limb_torso_ratio;
		arm_height = torso_height * .95;
		leg_width = torso_width / 2;
		leg_height = torso_height * limb_torso_ratio;
		leg_height = torso_height * .95;
		head_width = torso_width / 1.5;

		Torso_Text_Rect = sf::IntRect(0,0,50,50);
		Rt_Arm_Text_Rect = sf::IntRect(0,50,50,50);
		Lf_Arm_Text_Rect = sf::IntRect(0,50,50,50);
		Rt_Leg_Text_Rect = sf::IntRect(0,100,50,50);
		Lf_Leg_Text_Rect = sf::IntRect(0,100,50,50);
		Head_Text_Rect = sf::IntRect(0,150,50,50);
	}
	if(Name_ == "Adam")
	{
		torso_width = 36;
		torso_height = 90;
		arm_width = torso_width / 3;
		arm_height = torso_height *.95;
		leg_width = torso_width / 2;
		leg_height = torso_height * limb_torso_ratio;
		head_width = torso_width / 1.5;

		Torso_Text_Rect = sf::IntRect(50,0,50,50);
		Rt_Arm_Text_Rect = sf::IntRect(50,50,50,50);
		Lf_Arm_Text_Rect = sf::IntRect(50,50,50,50);
		Rt_Leg_Text_Rect = sf::IntRect(50,100,50,50);
		Lf_Leg_Text_Rect = sf::IntRect(50,100,50,50);
		Head_Text_Rect = sf::IntRect(50,150,50,50);
	}
	if(Name_ == "Bill")
	{
		torso_width = 30;
		torso_height = 70;
		arm_width = torso_width / 3;
		arm_height = torso_height *.95;
		leg_width = torso_width / 2;
		leg_height = torso_height * limb_torso_ratio;
		head_width = torso_width / 1.5;

		Torso_Text_Rect = sf::IntRect(100,0,50,50);
		Rt_Arm_Text_Rect = sf::IntRect(100,50,50,50);
		Lf_Arm_Text_Rect = sf::IntRect(100,50,50,50);
		Rt_Leg_Text_Rect = sf::IntRect(100,100,50,50);
		Lf_Leg_Text_Rect = sf::IntRect(100,100,50,50);
		Head_Text_Rect = sf::IntRect(100,150,50,50);
	}
	if(Name_ == "Zane")
	{
		torso_width = 25;
		torso_height = 99;
		arm_width = torso_width / 3;
		arm_height = torso_height *.95;
		leg_width = torso_width / 2;
		leg_height = torso_height * limb_torso_ratio;
		head_width = torso_width / 1.5;

		Torso_Text_Rect = sf::IntRect(150,0,50,50);
		Rt_Arm_Text_Rect = sf::IntRect(150,50,50,50);
		Lf_Arm_Text_Rect = sf::IntRect(150,50,50,50);
		Rt_Leg_Text_Rect = sf::IntRect(150,100,50,50);
		Lf_Leg_Text_Rect = sf::IntRect(150,100,50,50);
		Head_Text_Rect = sf::IntRect(150,150,50,50);
	}

	movement_time_endpoint = max_movement_time_endpoint * (torso_height / max_torso_height);

	Sprite_Sheet = Sprite_Sheet_;
	speed = 500;
	max_displacement_per_frame = 50;

	Torso = TorsoSprite(Sprite_Sheet, Torso_Text_Rect, sf::Vector2f(torso_width, torso_height), leg_height - 10);

	Right_Arm.setPointCount(4);
	Right_Arm.setPoint(0,sf::Vector2f(0,0));
	Right_Arm.setPoint(1,sf::Vector2f(arm_width,0));
	Right_Arm.setPoint(2,sf::Vector2f(arm_width,arm_height));
	Right_Arm.setPoint(3,sf::Vector2f(0,arm_height));
	Right_Arm.setOrigin(arm_width / 2, arm_width / 2);
	Right_Arm.setTexture(Sprite_Sheet);
	Right_Arm.setTextureRect(Rt_Arm_Text_Rect);

	Left_Arm.setPointCount(4);
	Left_Arm.setPoint(0,sf::Vector2f(0,0));
	Left_Arm.setPoint(1,sf::Vector2f(arm_width,0));
	Left_Arm.setPoint(2,sf::Vector2f(arm_width,arm_height));
	Left_Arm.setPoint(3,sf::Vector2f(0,arm_height));
	Left_Arm.setOrigin(arm_width / 2, arm_width / 2);
	Left_Arm.setTexture(Sprite_Sheet);
	Left_Arm.setTextureRect(Lf_Arm_Text_Rect);

	Right_Leg.setPointCount(4);
	Right_Leg.setPoint(0,sf::Vector2f(0,0));
	Right_Leg.setPoint(1,sf::Vector2f(leg_width,0));
	Right_Leg.setPoint(2,sf::Vector2f(leg_width,leg_height));
	Right_Leg.setPoint(3,sf::Vector2f(0,leg_height));
	Right_Leg.setOrigin(leg_width / 2, leg_width / 2);
	Right_Leg.setTexture(Sprite_Sheet);
	Right_Leg.setTextureRect(Rt_Leg_Text_Rect);

	Left_Leg.setPointCount(4);
	Left_Leg.setPoint(0,sf::Vector2f(0,0));
	Left_Leg.setPoint(1,sf::Vector2f(leg_width,0));
	Left_Leg.setPoint(2,sf::Vector2f(leg_width,leg_height));
	Left_Leg.setPoint(3,sf::Vector2f(0,leg_height));
	Left_Leg.setOrigin(leg_width / 2, leg_width / 2);
	Left_Leg.setTexture(Sprite_Sheet);
	Left_Leg.setTextureRect(Lf_Leg_Text_Rect);

	Head.setPointCount(4);
	Head.setPoint(0,sf::Vector2f(0,0));
	Head.setPoint(1,sf::Vector2f(head_width,0));
	Head.setPoint(2,sf::Vector2f(head_width,head_width));
	Head.setPoint(3,sf::Vector2f(0,head_width));
	Head.setOrigin(head_width / 2, head_width);
	Head.setTexture(Sprite_Sheet);
	Head.setTextureRect(Head_Text_Rect);

	setSpritePosition(Initial_Pos);
}

void HumanSprite::setCardinalOrientation(CardinalOrientation CO)
{
	if(CO == EAST)
	{
		if(Cardinal_Orientation != EAST)
		{
			flipAllSpriteTextures();
		}
		Cardinal_Orientation = EAST;
	}
	else
	{
		if(Cardinal_Orientation != WEST)
		{
			flipAllSpriteTextures();
		}
		Cardinal_Orientation = WEST;
	}
}

void HumanSprite::setSpritePosition(sf::Vector2f Target)
{
	bool movement_flag = false;
	if(Sprite_Position.x < Target.x)
	{
		setCardinalOrientation(EAST);
		movement_flag = true;
	}

	if(Sprite_Position.x > Target.x)
	{
		setCardinalOrientation(WEST);
		movement_flag = true;
	}

	Sprite_Position = Target;
	Torso.setPosition(Target);
	Left_Arm.setPosition(Torso.getLeftArmJt());
	Right_Arm.setPosition(Torso.getRightArmJt());
	Left_Leg.setPosition(Torso.getLeftLegJt());
	Right_Leg.setPosition(Torso.getRightLegJt());
	Head.setPosition(Torso.getHeadJoint());

	checkLimbRotation(movement_flag);
}

void HumanSprite::flipAllSpriteTextures()
{
	Left_Arm = flipTexture(Left_Arm);
	Right_Arm = flipTexture(Right_Arm);
	Left_Leg = flipTexture(Left_Leg);
	Right_Leg = flipTexture(Right_Leg);
	Head = flipTexture(Head);
	Torso.flipTexture();
}

sf::ConvexShape HumanSprite::flipTexture(sf::ConvexShape RS)
{
	RS.setTextureRect(sf::IntRect(RS.getTextureRect().left + RS.getTextureRect().width,
		RS.getTextureRect().top,
		-(RS.getTextureRect().width),
		RS.getTextureRect().height
		));
	return RS;
}

void HumanSprite::renderToWindow(sf::RenderWindow &Window)
{
	if(Cardinal_Orientation == EAST)
	{
		Window.draw(Left_Arm);
		Window.draw(Left_Leg);
		Window.draw(Head);
		Window.draw(Torso.getSprite());
		Window.draw(Right_Arm);
		Window.draw(Right_Leg);
	}
	if(Cardinal_Orientation == WEST)
	{
		Window.draw(Right_Arm);
		Window.draw(Right_Leg);
		Window.draw(Head);
		Window.draw(Torso.getSprite());
		Window.draw(Left_Arm);
		Window.draw(Left_Leg);
	}
}

float HumanSprite::getDisplacement(sf::Time Time_Per_Frame, bool east)
{
	float displacement = speed * Time_Per_Frame.asSeconds();
	if(displacement > max_displacement_per_frame)
	{
		displacement = max_displacement_per_frame;
	}

	if(east)
	{
		return displacement;
	}
	else
	{
		return -displacement;
	}
}

void HumanSprite::checkLimbRotation(bool movement_flag)
{
	if(!movement_flag)
	{
		Right_Arm.setRotation(0);
		Left_Arm.setRotation(0);
		Right_Leg.setRotation(0);
		Left_Leg.setRotation(0);
	}
	else
	{
		if(Movement_Clock.getElapsedTime().asMilliseconds() % movement_time_endpoint * 2 < movement_time_endpoint)
		{
			Right_Arm.setRotation(-20);
			Left_Arm.setRotation(20);
			Right_Leg.setRotation(20);
			Left_Leg.setRotation(-20);
		}
		else
		{
			Right_Arm.setRotation(20);
			Left_Arm.setRotation(-20);
			Right_Leg.setRotation(-20);
			Left_Leg.setRotation(20);
		}
	}
}