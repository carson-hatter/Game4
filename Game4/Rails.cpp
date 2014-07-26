#include "Rails.h"

Rails::Rails()
{

}

void Rails::updateRail(std::vector<sf::ConvexShape> Foreground_Pieces, unsigned int top_left_pt_index, unsigned int top_right_pt_index)
{
	Rail.clear();

	for(unsigned int i = 0; i < Foreground_Pieces.size(); i++)
	{
		if(i == 0)
		{
			Rail.push_back(Foreground_Pieces[i].getTransform().transformPoint(Foreground_Pieces[i].getPoint(top_left_pt_index)));
		}
		Rail.push_back(Foreground_Pieces[i].getTransform().transformPoint(Foreground_Pieces[i].getPoint(top_right_pt_index)));
	}
}

sf::Vector2f Rails::getMovementDestination(float displacement, sf::Vector2f Starting_Pt)
{
	sf::Vector2f To_Return;

	for(unsigned int i = 0; i < (Rail.size() - 1); i++)
	{
		if((Starting_Pt.x >= Rail[i].x) && (Starting_Pt.x <= Rail[i + 1].x))
		{
			float distance_between_endpts = MyGeometry::findDistance(Rail[i], Rail[i + 1]);
			float theta = MyGeometry::findTheta(Rail[i], Rail[i+1]);

			if(distance_between_endpts <= displacement)
			{
				float hypotenuse = displacement;
				To_Return.x = cos(theta) * hypotenuse;
				To_Return.y = sin(theta) * hypotenuse;
			}
			else
			{
				float hypotenuse = MyGeometry::findHypotenuse(Starting_Pt, Rail[i+1]);
				displacement -= hypotenuse;

				theta = MyGeometry::findTheta(Rail[i+1], Rail[i+2]);
				hypotenuse = displacement;
				To_Return.x = cos(theta) * hypotenuse;
				To_Return.y = sin(theta) * hypotenuse;
			}
		}
	}

	return To_Return;
}

sf::Vector2f Rails::getValidCoord(float x_coord)
{
	sf::Vector2f To_Return;
	
	sf::Vector2f p1 (x_coord, 0);
	sf::Vector2f p2 (x_coord, 10000);

	for(unsigned int i = 0; i < Rail.size() - 1; i++)
	{
		sf::Vector2f p3(Rail[i]);
		sf::Vector2f p4(Rail[i+1]);

		if((p1.x <= p4.x) && (p1.x >= p3.x))
		{

			float x1 = p1.x, x2 = p2.x, x3 = p3.x, x4 = p4.x;
			float y1 = p1.y, y2 = p2.y, y3 = p3.y, y4 = p4.y;

			float d = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);

			// Get the x and y
			float pre = (x1*y2 - y1*x2), post = (x3*y4 - y3*x4);
			float x = ( pre * (x3 - x4) - (x1 - x2) * post ) / d;
			float y = ( pre * (y3 - y4) - (y1 - y2) * post ) / d;
			
			To_Return = sf::Vector2f(x,y);
		}
	}
	return To_Return;
}