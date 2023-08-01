#include "snake.h";
#include<iostream>
snake::snake():snake(0.01f)
{
}

snake::snake(float s):speed(s)
{
	directionVecs[left] = sf::Vector2f(-speed, 0.0f);
	directionVecs[right] = sf::Vector2f(speed, 0.0f);
	directionVecs[top] = sf::Vector2f(0.00f, -speed);
	directionVecs[down] = sf::Vector2f(0.00f, speed);
	SnakeHead = new Node(sf::Vector2f(250, 250));
	SnakeTail = SnakeHead;
	currentDirection = directionVecs[right];

}

void snake::UpdateSnake(const sf::Time& delta)
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

	SnakeHead->AddToPosition(sf::Vector2f(currentDirection.x * delta.asSeconds(), currentDirection.y * delta.asSeconds()));
	
	
	Node* temp = SnakeHead->next;
	sf::Clock clock;
	sf::Time delta2;
	bool canUpdate = true;
	while (temp!=nullptr) //update other snake
	{
		
		//std::cout << delta2.asMilliseconds() << std::endl;
		sf::Vector2f pos = temp->getPosition();
		
		if (canUpdate)
		{
			delta2 = clock.restart();
			canUpdate = false;
		}
		std::cout << clock.getElapsedTime().asSeconds() << std::endl;
		if (clock.getElapsedTime().asSeconds() > 0.01f/counter)
		{
			temp->changePosition(oldPos);
			oldPos = pos;
			temp = temp->next;
			canUpdate = true;
		}

	}
}

void snake::EatApple()
{
	if (counter == 50) return;
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
		std::cout << distance << std::endl;
		if (distance  < 0.05f) return true;
		temp = temp->next;
	}
	return false;
}