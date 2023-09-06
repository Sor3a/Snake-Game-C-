#include "snake.h";
#include<iostream>
#include "../Grid/Grid.h"
snake::snake():snake(0.01f)
{
}

snake::snake(float s):speed(s)
{
	directionVecs[left] = sf::Vector2i(-1, 0);
	directionVecs[right] = sf::Vector2i(1, 0);
	directionVecs[top] = sf::Vector2i(0, -1);
	directionVecs[down] = sf::Vector2i(0, 1);
	SnakeHead = new Node(sf::Vector2f(250, 250));
	SnakeHead->changeColor(sf::Color::Cyan);
	SnakeTail = SnakeHead;
	currentDirection = directionVecs[right];

}

void snake::UpdateSnake()
{
	sf::Vector2f oldPos = SnakeHead->getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // update the head
	{
		currentDirection = directionVecs[left];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		currentDirection = directionVecs[right];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		currentDirection = directionVecs[top];
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		currentDirection = directionVecs[down];
	}

	auto newPos = Grid::indexToPosition(Grid::PositionToIndex(oldPos) + currentDirection);
	SnakeHead->changePosition(newPos);


	Node* temp = SnakeHead->next;


	while (temp != nullptr) //update other snake
	{
		sf::Vector2f pos = temp->getPosition();
		temp->changePosition(oldPos);
		oldPos = pos;
		temp = temp->next;
	}
}

void snake::EatApple()
{
	Node* n = new Node(sf::Vector2f(-5250, -5250));
	SnakeTail->next = n;
	SnakeTail = n;
	counter++;
}

void snake::Draw(sf::RenderWindow& window)
{
	Node* temp = SnakeHead;
	while (temp!=nullptr)
	{
		temp->Draw(window);
		temp = temp->next;
	}
}
sf::Vector2f snake::getHeadPosition()
{
	return SnakeHead->getPosition();
}
float snake::GetDistance(const sf::Vector2f& pos1, const sf::Vector2f& pos2)
{
	return sqrt(pow(pos2.x - pos1.x, 2) + pow(pos2.y - pos1.y, 2) * 1.0);
	
}
bool snake::hitHimSelf()
{
	auto headPos = SnakeHead->getPosition();
	Node* temp = SnakeHead->next;

	while (temp!=nullptr)
	{
		float distance = GetDistance(headPos, temp->getPosition());
		//std::cout << distance << std::endl;
		if (distance  < 10.0f) return true;
		temp = temp->next;
	}
	return false;
}