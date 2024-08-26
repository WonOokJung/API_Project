#pragma once
#include "..\\APIEngine_SOURCE\Scene.h"

namespace ap
{
	class TitleScene : public Scene
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnEnter() override;
		void OnExit() override;

	public:
		TitleScene();
		~TitleScene();
	};
}

