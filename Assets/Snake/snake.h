#pragma once
#include "Node.h"
#include <unordered_map>
enum directions
{
	left = 1,
	right,
	top,
	down,
};
class snake 
{
private:
	int counter = 0;
	std::unordered_map<directions, sf::Vector2f> directionVecs;
	Node* SnakeHead;
	Node* SnakeTail;
	float speed;
	sf::Vector2f currentDirection;
	float GetDistance(const sf::Vector2f& pos1, const sf::Vector2f& pos2);
public:
	snake();
	snake(float s);
	void UpdateSnake(const sf::Time& delta);
	void EatApple();
	void Draw(sf::RenderWindow& window);
	sf::Vector2f getHeadPosition();
	bool hitHimSelf();
};
