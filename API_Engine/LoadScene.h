#pragma once
#include "..\\APIEngine_SOURCE\Scene_Manager.h"
#include "PlayScene.h" 
#include "TitleScene.h"

namespace ap
{
	void LoadScene()
	{
		Scene_Manager::CreateScene<TitleScene>(L"TitleScene");
		Scene_Manager::CreateScene<PlayScene>(L"PlayScene");

		//Scene_Manager::LoadScene(L"TitleScene");
		Scene_Manager::LoadScene(L"PlayScene");
	}
}