#include "TitleScene.h"
#include "PlayScene.h"
#include <cassert>
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input_Manager.h"
#include "Scene_Manager.h"

namespace ap
{
	TitleScene::TitleScene()
	{
	}
	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
	}
	void TitleScene::Update()
	{
		Scene::Update();
	}
	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();

		if (Input_Manager::GetKeyDown(eKeyCode::N))
		{
			Scene_Manager::LoadScene(L"PlayScene");
			//assert(false);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t str[50] = L"Title Scene";

		TextOut(hdc, 500, 0, str, 13);
	}
	void TitleScene::OnEnter()
	{
	}
	void TitleScene::OnExit()
	{
	}
}