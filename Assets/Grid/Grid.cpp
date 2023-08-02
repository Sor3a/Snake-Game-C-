#include "Grid.h"
#include <cstdlib>
#include <iostream>
#include <cmath>
int Grid::x = 0;
int Grid::y = 0;
int Grid::screenMiddle = 0;
Grid::Grid(int x, int y, int screenMiddle)
{
	//move it to half of the screen
	this->x = x;
	this->y = y;
	this->screenMiddle = screenMiddle;
	didUpdate = false;
	apple = nullptr;
	grid = std::vector<std::vector<int>>(x, std::vector<int>(y, 0));
	for (int i = 0; i < y; i++)
	{
		grid[0][i] = 1;
		auto temp = new sf::RectangleShape(sf::Vector2f(10, 10));
		temp->setPosition(indexToPosition(sf::Vector2i(0, i)));
		temp->setFillColor(sf::Color::Magenta);
		shapes.emplace_back(temp);
		grid[x-1][i] = 1;
		temp = new sf::RectangleShape(sf::Vector2f(10, 10));
		temp->setPosition(indexToPosition(sf::Vector2i(x - 1, i)));
		temp->setFillColor(sf::Color::Magenta);
		shapes.emplace_back(temp);
	}
	for (int i = 0; i < x; i++)
	{
		grid[i][0] = 1;
		auto temp = new sf::RectangleShape(sf::Vector2f(10, 10));
		temp->setPosition(indexToPosition(sf::Vector2i(i, 0)));
		temp->setFillColor(sf::Color::Magenta);
		shapes.emplace_back(temp);
		grid[i][y - 1] = 1;
		temp = new sf::RectangleShape(sf::Vector2f(10, 10));
		temp->setPosition(indexToPosition(sf::Vector2i(i, y - 1)));
		temp->setFillColor(sf::Color::Magenta);
		shapes.emplace_back(temp);
	}

}
const sf::Vector2f& Grid::indexToPosition(const sf::Vector2i& index) 
{
	return sf::Vector2f(screenMiddle - x*10 / 2 + index.x * 10, screenMiddle - y*10 / 2 + index.y * 10);
}
const sf::Vector2i& Grid::PositionToIndex(const sf::Vector2f& position) 
{
	return sf::Vector2i((position.x-(screenMiddle - x*10 / 2))/10 , (position.y - (screenMiddle - y*10 / 2)) / 10);
}
void Grid::Draw(sf::RenderWindow& window)
{
	for (const auto& c : shapes)
	{
		window.draw(*(c));
	}
	if (apple != nullptr)
	{
		window.draw(*(apple));
	}
}

bool Grid::isOnGrid(snake& MySnake)
{
	auto index = PositionToIndex(MySnake.getHeadPosition());
	if(index.x<0 || index.y<0 || index.x>=x ||index.y >=y)
		return true;
	if (grid[index.x][index.y] == 2)
	{
		MySnake.EatApple();
		deleteApple();
	}
	return grid[index.x][index.y]==1;
}
void Grid::CreateApple()
{
	apple = new sf::RectangleShape(sf::Vector2f(10,10));
	int newX = abs(rand()) % (x-1);
	int newY = abs(rand()) % (y - 1);
	apple->setFillColor(sf::Color::Green);
	grid[newX][newY] = 2;
	apple->setPosition(indexToPosition(sf::Vector2i(newX, newY)));
}
void Grid::deleteApple()
{
	if (apple != nullptr)
	{
		auto index = PositionToIndex(apple->getPosition());
		grid[index.x][index.y] = 0;
		delete apple;
		apple = nullptr;
	}
}

void Grid::UpdateGrid()
{
	if (!didUpdate)
	{
		didUpdate = true;
		appleClock.restart();
	}
	//std::cout << appleClock.getElapsedTime().asSeconds() << std::endl;
	if (appleClock.getElapsedTime().asSeconds() > 5.0f)
	{
		
		deleteApple();
		CreateApple();
		didUpdate = false;
	}
}