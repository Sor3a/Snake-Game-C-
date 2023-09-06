
#include <iostream>
#include"Assets/Scenes/Scene/SnakeScene/SnakeScene.h"
#include"Assets/Scenes/Scene/ReplayGameScene/lostScene.h"
#include <thread>
#include <mutex>

std::mutex m;

void updateScene(bool& windowOpen, Scene*& scene_)
{
    while (windowOpen)
    {
        std::lock_guard<std::mutex> guard(m);
        scene_->Update();
        scene_ = SceneManager::getCurrentScene(); // update if the scene has changed

    };
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Snake");

    //Scene creations
    LostScene lostScene;
    SnakeScene SnakeScene(40,40,250); //parameters : size of grid x,y and then the middle of the screen
    SceneManager::addScene(&SnakeScene,0);
    SceneManager::addScene(&lostScene, 1);
    SceneManager::ChangeScene(0);
    Scene* scene = SceneManager::getCurrentScene();

    bool windowOpen = true;
    std::thread UpdatingSceneThread(updateScene,std::ref(windowOpen),std::ref(scene));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();

        m.lock();
        scene->Draw(window);
        m.unlock();
        
        

        window.display();
    }
    windowOpen = false;
    UpdatingSceneThread.join();
    return 0;
}
