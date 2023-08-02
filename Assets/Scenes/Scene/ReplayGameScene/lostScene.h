#pragma once
#include "../Scene.h"
class LostScene :public Scene
{
	sf::Font font;
	sf::Text text;
	sf::Text text1;
public:
	LostScene();
	void Start();
	void Update();
	void Draw(sf::RenderWindow& window);
};
