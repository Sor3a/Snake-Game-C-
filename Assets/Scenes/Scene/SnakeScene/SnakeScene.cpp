
#include "SnakeScene.h"


void SnakeScene::Start()
{
    clock = sf::Clock();
    clock1 = sf::Clock(); 
    g = Grid(x, y, mid);
    mySnake = snake(SnakeSpeed);
}
SnakeScene::SnakeScene(int gridX , int gridY, int middleSceen, float snakeSpeed ):
	clock(), clock1(),g(gridX, gridY, middleSceen),mySnake(snakeSpeed),x(gridX),y(gridY),mid(middleSceen),
    SnakeSpeed(snakeSpeed)
{
	didUpdate = false;
}

void SnakeScene::Update()
{
	sf::Time delta = clock.restart();
	if (!didUpdate) {
		didUpdate = true;
		clock1.restart();
	}
    if (clock1.getElapsedTime().asSeconds() > 0.05f)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            mySnake.EatApple();
        if (g.isOnGrid(mySnake) || mySnake.hitHimSelf())
        {
            SceneManager::ChangeScene(1);
        }
        mySnake.UpdateSnake(delta);

        //if (clock.getElapsedTime().asSeconds() > 0.1f)
        didUpdate = false;
    }
    g.UpdateGrid();
}

void SnakeScene::Draw(sf::RenderWindow& window)
{
    mySnake.Draw(window);
    g.Draw(window);
}