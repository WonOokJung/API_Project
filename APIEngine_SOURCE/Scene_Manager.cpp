#include "Scene_Manager.h"

namespace ap
{
	std::map<std::wstring, Scene*> Scene_Manager::mScene = {};
	Scene* Scene_Manager::mActiveScene = nullptr;

	void Scene_Manager::Initialize()
	{
	}

	void Scene_Manager::Update()
	{
		mActiveScene->Update();
	}

	void Scene_Manager::LateUpdate()
	{
		mActiveScene->LateUpdate();
	}

	void Scene_Manager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}
}
