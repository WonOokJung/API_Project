#pragma once
#include "..\\APIEngine_SOURCE\ap_GameObject.h"

namespace ap
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
	};
}
