#include "ap_GameObject.h"

namespace ap
{
	void GameObject::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mX -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mX += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mY -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mY += 0.01f;
		}
	}
	void GameObject::LateUpdate()
	{

	}
	void GameObject::Render(HDC hdc)
	{
		// 파란브러쉬 생성
		HBRUSH newBrush = CreateSolidBrush(RGB(0, 0, 255));
		// 파란 브러쉬 dc생성 및 흰색 브러쉬 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		Rectangle(hdc, 10 + mX, 10 + mY, 100 + mX, 100 + mY);

		//다시 원본브러쉬선택
		SelectObject(hdc, oldBrush);

		// 파랑 브러쉬 삭제
		DeleteObject(newBrush);
	}

	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}
}
