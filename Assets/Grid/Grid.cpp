#include "Grid.h"


Grid::Grid(int x, int y, int screenMiddle):x(x),y(y)
{
	//move it to half of the screen

	sf::RectangleShape* shape = new sf::RectangleShape(sf::Vector2f(x, 10));
	shape->setPosition(-x / 2 + screenMiddle, -y / 2 + screenMiddle);
	sf::RectangleShape* shape1 = new sf::RectangleShape(sf::Vector2f(x, 10));
	shape1->setPosition(-x / 2 + screenMiddle, y / 2 + screenMiddle);
	shapes.emplace_back(shape);
	shapes.emplace_back(shape1);

	shape = new sf::RectangleShape(sf::Vector2f(10, y));
	shape->setPosition(-x / 2 + screenMiddle, -y / 2 + screenMiddle);
	shape1 = new sf::RectangleShape(sf::Vector2f(10, y+10));
	shape1->setPosition(x / 2 + screenMiddle, -y / 2 + screenMiddle);
	shapes.emplace_back(shape);
	shapes.emplace_back(shape1);

	for (auto& c : shapes)
	{
		c->setFillColor(sf::Color(sf::Color::Magenta));
	}
}
void Grid::Draw(sf::RenderWindow& window)
{
	for (const auto& c : shapes)
	{
		window.draw(*(c));
	}
}
bool Grid::isOnGrid(sf::Vector2f pos)
{
	for (const auto& c : shapes)
	{
		auto currentPos= c->getPosition();
		float size = c->getSize().x;
		if (size == 10.0f)
		{
			if (pos.x<(currentPos.x+10) && pos.x >(currentPos.x - 10) && pos.y>(currentPos.y - y/2) )
				return true;
		}
		else
		{
			if (pos.x >(currentPos.x - x / 2) && pos.y<(currentPos.y + 10) && pos.y >(currentPos.y - 10))
				return true;
		}

	}
	return false;
}