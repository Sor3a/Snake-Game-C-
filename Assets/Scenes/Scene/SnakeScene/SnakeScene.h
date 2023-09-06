#pragma once

#include "../../SceneManager.h"
#include "../../../Grid/Grid.h"
class SnakeScene : public Scene
{
public:
	SnakeScene(int gridX=40,int gridY=40,int middleSceen=250,float snakeSpeed=100.0f);
	void Start();
	void Update();
	void Draw(sf::RenderWindow& window);

private:

	sf::Clock clock1;

	snake mySnake;
	Grid g;

	bool didUpdate;

	int x, y, mid;
	float SnakeSpeed;

};
