#include "PlayScene.h"
#include "ap_GameObject.h"
#include "Player.h"
#include "TitleScene.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input_Manager.h"
#include "Scene_Manager.h"
#include "apObject.h"

namespace ap
{
	PlayScene::PlayScene()
	{
	}
	PlayScene::~PlayScene()
	{
	}

	void PlayScene::Initialize()
	{
		/*bg = new Player();
		Transform* tr
			= bg->AddComponent<Transform>();
		tr->SetPos(Vector2(0, 0));

		tr->SetName(L"TR");

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\dnr16\\source\\repos\\API_Project\\Resources\\CloudOcean.png");

		AddGameObject(bg, eLayerType::BackGround);*/

		bg = object::Instantiate<Player>(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));

		SpriteRenderer* sr
			= bg->AddComponent<SpriteRenderer>();
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\dnr16\\source\\repos\\API_Project\\Resources\\CloudOcean.png");
	}
	void PlayScene::Update()
	{
		Scene::Update();
	}
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input_Manager::GetKeyDown(eKeyCode::N))
		{
			Scene_Manager::LoadScene(L"TitleScene");
		}
	}
	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[12] = L"Play Scene";

		TextOut(hdc, 0, 0, str, 11);
	}
	void PlayScene::OnEnter()
	{
		/*Transform* tr = bg->GetComponent<Transform>();
		tr->SetPos(Vector2(0, 0));*/
	}
	void PlayScene::OnExit()
	{
	}
}