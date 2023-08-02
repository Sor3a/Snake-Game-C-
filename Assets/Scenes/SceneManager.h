#pragma once
#include<unordered_map>
#include "Scene/Scene.h"
static class SceneManager
{
public:
	static void addScene(Scene* scene,int index=-1)
	{
		if (index != -1)
			scenes[index] = scene;
		else
			scenes[scenes.size()] = scene;
	}
	static void ChangeScene(int index)
	{
		if (scenes.find(index) == scenes.end()) return;
		currentScene = scenes[index];
		currentScene->Start();
	}
	static Scene*& getCurrentScene()
	{
		return currentScene;
	}
private:
	inline static Scene* currentScene = nullptr;
	inline static std::unordered_map<int, Scene*> scenes = {};
};
//Scene* SceneManager::currentScene = nullptr;
//std::unordered_map<int, Scene*> SceneManager::scenes = {};