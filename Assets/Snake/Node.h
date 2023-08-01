#pragma once
#include <SFML/Graphics.hpp>
class Node
{
private:
	sf::Vector2f currentPosition;
	sf::RectangleShape shape;
public:
	Node* next;
	Node(const sf::Vector2f& newPos, Node* next);
	Node(const sf::Vector2f& newPos);
	Node();
	void AddToPosition(const sf::Vector2f& newPos);
	void changePosition(const sf::Vector2f& newPos);
	void Draw(sf::RenderWindow& window);
	const sf::Vector2f& getPosition();
};

