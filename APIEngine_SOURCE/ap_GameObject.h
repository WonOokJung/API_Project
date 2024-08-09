#pragma once
#include "CommonInclude.h"

namespace ap
{
	class GameObject
	{
	public:
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}
		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }



	private:
		// 오브젝트 좌표
		float mX;
		float mY;

	public:
		GameObject();
		~GameObject();
	};
}

