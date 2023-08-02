#include "lostScene.h"
#include "../../SceneManager.h"

LostScene::LostScene()
{
	font.loadFromFile("arial_narrow_7.ttf");
	text = sf::Text("YOU LOST", font, 50);
	text1 = sf::Text("PRESS R TO RESTART", font, 30);
}
void LostScene::Start()
{
	text.setPosition(sf::Vector2f(150, 200));
	text1.setPosition(sf::Vector2f(100, 250));
}
void LostScene::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
		SceneManager::ChangeScene(0);
}
void LostScene::Draw(sf::RenderWindow& window)
{
	window.draw(text);
	window.draw(text1);
}