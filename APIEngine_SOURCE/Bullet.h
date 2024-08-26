#pragma once
#include "ap_GameObject.h"

namespace ap
{
	class Bullet : public GameObject
	{
	public:
		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
	};
}

