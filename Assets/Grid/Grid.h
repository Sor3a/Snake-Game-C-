#pragma once
#include<vector>
#include <SFML/Graphics.hpp>
#include "../Snake/snake.h"
class Grid
{
	static int x, y;
	static int screenMiddle;
	std::vector<std::vector<int>> grid;
	sf::Clock appleClock;
	std::vector<sf::RectangleShape*> shapes;
	bool didUpdate;
	sf::RectangleShape* apple;
	void CreateApple();
	void deleteApple();
public:

	void UpdateGrid();
	Grid(int x, int y, int screenMiddle);
	bool isOnGrid(snake& MySnake);
	void Draw(sf::RenderWindow& window);
	const static sf::Vector2f& indexToPosition(const sf::Vector2i& index);
	const static sf::Vector2i& PositionToIndex(const sf::Vector2f& position);
};
