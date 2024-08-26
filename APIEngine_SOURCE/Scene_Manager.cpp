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
	Scene* Scene_Manager::LoadScene(const std::wstring& name)

	{
		if (mActiveScene)
		{
			mActiveScene->OnExit();
		}

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;

		mActiveScene->OnEnter();

		return iter->second;
	}
}
