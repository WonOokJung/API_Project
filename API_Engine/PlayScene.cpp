#include "PlayScene.h"
#include "ap_GameObject.h"
#include "Player.h"
#include "TitleScene.h"
#include "Transform.h"
#include "SpriteRenderer.h"
#include "Input_Manager.h"
#include "Scene_Manager.h"
#include "apObject.h"
#include "Texture.h"
#include "Resources.h"
#include "PlayerScript.h"
#include "Renderer.h"
#include "Animator.h"

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
		//게임 오브젝트 만들기 전에 전부 Load시켜놓는다
		/*
		sr->SetName(L"SR");
		sr->ImageLoad(L"C:\\Users\\dnr16\\source\\repos\\API_Project\\Resources\\CloudOcean.png");

		AddGameObject(bg, eLayerType::BackGround);*/

		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::None, Vector2(800.0f, 450.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		Renderer::mainCamera = cameraComp;
		//camera->AddComponent<PlayerScript>();

		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		mPlayer->AddComponent<PlayerScript>();

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* animator = mPlayer->AddComponent<Animator>();
		animator->CreateAnimation(L"CatFrontMove", catTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		animator->PlayAnimation(L"CatFrontMove", true);

		GameObject* backGround = object::Instantiate<GameObject>(enums::eLayerType::BackGround);
		SpriteRenderer* bg = backGround->AddComponent<SpriteRenderer>();
		graphics::Texture* bgTexture = Resources::Find<graphics::Texture>(L"BG");
		bg->SetTexture(bgTexture);


		Scene::Initialize();
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