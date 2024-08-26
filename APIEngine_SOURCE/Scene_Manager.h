#pragma once
#include "Scene.h"

namespace ap
{
	class Scene_Manager
	{
	public:
		static void Initialize();
		static void Update();
		static void LateUpdate();
		static void Render(HDC hdc);

		template <typename T>
		static Scene* CreateScene(const std::wstring& name)
		{
			T* scene = new T();
			scene->SetName(name);
			mActiveScene = scene;

			scene->Initialize();

			mScene.insert(std::make_pair(name, scene));

			return scene;
		}

		static Scene* LoadScene(const std::wstring& name);

		static Scene* GetActiveScene() { return mActiveScene; }
 
	private:		
		static std::map<std::wstring, Scene*> mScene;
		static Scene* mActiveScene;

	public:

	};
}

