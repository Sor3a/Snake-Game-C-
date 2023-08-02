
#include <iostream>
#include"Assets/Scenes/Scene/SnakeScene/SnakeScene.h"
#include "Assets/Scenes/SceneManager.h"
#include"Assets/Scenes/Scene/ReplayGameScene/lostScene.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Snake");

    //Scene creations
    LostScene lostScene;
    SnakeScene SnakeScene(80,80,500);
    SceneManager::addScene(&SnakeScene,0);
    SceneManager::addScene(&lostScene, 1);
    SceneManager::ChangeScene(0);
    Scene* scene = SceneManager::getCurrentScene();
    //scene->Start();


    while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        scene->Update();
        scene->Draw(window);
        scene = SceneManager::getCurrentScene(); // update if the scene has changed

        window.display();
    }

    return 0;
}
