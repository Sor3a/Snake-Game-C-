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
	void AddToPosition(const sf::Vector2i& newPos);
	void changePosition(const sf::Vector2f& newPos);
	void Draw(sf::RenderWindow& window);
	void changeColor(sf::Color color);
	const sf::Vector2f& getPosition();
};

