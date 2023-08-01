#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
class Grid
{
	int x, y;
	std::vector<sf::RectangleShape*> shapes;
public:
	Grid(int x, int y, int screenMiddle);
	bool isOnGrid(sf::Vector2f pos);
	void Draw(sf::RenderWindow& window);
};
