#include "SmoothView.h"

sf::FloatRect SmoothView::getGlobalBounds()
{
	sf::FloatRect To_Return;
	To_Return.left = View.getCenter().x - (View.getSize().x / 2);
	To_Return.top = View.getCenter().y - (View.getSize().y / 2);
	To_Return.width = View.getSize().x;
	To_Return.height = View.getSize().y;
	return To_Return;
}

void SmoothView::move(sf::Vector2f Desired_Position, sf::Time Time_Per_Frame)
{
	unsigned int close_enough_radius = 2;
	
	if((abs(View.getCenter().x - Desired_Position.x) < close_enough_radius) && (abs(View.getCenter().y - Desired_Position.y) < close_enough_radius))
	{
		View.setCenter(Desired_Position);
		return;
	}	
	
	float theta, x_diff, y_diff;
	x_diff = Desired_Position.x - View.getCenter().x;
	y_diff = Desired_Position.y - View.getCenter().y;

	float temp_speed = 1000 * Time_Per_Frame.asSeconds();

	theta = atan2(y_diff, x_diff);

	View.move(temp_speed * cos(theta), temp_speed * sin(theta));
}

SmoothView::SmoothView(sf::View Default_View)
{
	Default_Size = Default_View.getSize();
	View.setSize(Default_Size.x, Default_Size.y);
	View.setCenter(Default_View.getCenter());
}

void SmoothView::zoom(float desired_zoom_level, sf::Time Time_Per_Frame)
{
	if(desired_zoom_level <= 1)
	{
		float temp_speed = 2.0f;
		float current_zoom_level = View.getSize().x / Default_Size.x;

		float zoom_diff = 0;

		//if(current_zoom_level > desired_zoom_level)
		//{
		//	zoom_diff = current_zoom_level - desired_zoom_level;
		//}
		//if(current_zoom_level < desired_zoom_level)
		//{
			zoom_diff = desired_zoom_level - current_zoom_level;
		//}

		if(abs(zoom_diff) < 0.05)
		{
			return;
		}

		float zoom_factor_per_frame = zoom_diff * temp_speed * Time_Per_Frame.asSeconds();
		/*NEEDS TESTING*/View.setSize(View.getSize().x + (View.getSize().x * zoom_factor_per_frame), View.getSize().y + (View.getSize().y * zoom_factor_per_frame));
	}
}