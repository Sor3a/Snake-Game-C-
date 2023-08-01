
#include <iostream>
#include "Assets/Snake/snake.h"
#include"Assets/Grid/Grid.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");
    //sf::CircleShape shape(100.f);

    //sf::RectangleShape myShape(sf::Vector2f(10, 10));

    //shape.setFillColor(sf::Color::Green);
    //myShape.setFillColor(sf::Color::Blue);

    snake mySnake(100.0f);
    sf::Clock clock; //for updateFunction and time to update
    Grid g(300, 300, 250);
    bool didUpdate = false;
    while (window.isOpen())
    {
        sf::Time delta = clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            mySnake.EatApple();
        if (g.isOnGrid(mySnake.getHeadPosition()) || mySnake.hitHimSelf())
        {
            std::cout << "on" << std::endl;
        }
        mySnake.UpdateSnake(delta);

        //if (clock.getElapsedTime().asSeconds() > 0.1f)
        didUpdate = false;

        mySnake.Draw(window);
        g.Draw(window);


        window.display();
    }

    return 0;
}
