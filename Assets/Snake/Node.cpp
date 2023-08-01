#include "Node.h"

Node::Node():shape(sf::Vector2f(10, 10))
{
	changePosition(sf::Vector2f(0, 0));
	next = nullptr;
}
Node::Node(const sf::Vector2f& newPos):shape(sf::Vector2f(10, 10))
{
	changePosition(newPos);
	next = nullptr;
}

Node::Node(const sf::Vector2f& newPos, Node* next):shape(sf::Vector2f(10, 10))
{
	changePosition(newPos);
	this->next = next;
}

void Node::changePosition(const sf::Vector2f& newPos)
{
	currentPosition = newPos;
	shape.setPosition(currentPosition);
}
void Node::AddToPosition(const sf::Vector2f& newPos)
{
	currentPosition += newPos;
	shape.setPosition(currentPosition);
}

void Node::Draw(sf::RenderWindow& window)
{
	window.draw(shape);
}
const sf::Vector2f& Node::getPosition()
{
	return currentPosition;
}