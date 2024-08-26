#pragma once
#include "..\\APIEngine_SOURCE\Scene.h"

namespace ap
{
	class PlayScene : public Scene
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	private:
		class Player* bg;

	public:
		PlayScene();
		~PlayScene();

	};
}

