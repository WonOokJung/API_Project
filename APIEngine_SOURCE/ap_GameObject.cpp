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
		// �Ķ��귯�� ����
		HBRUSH newBrush = CreateSolidBrush(RGB(0, 0, 255));
		// �Ķ� �귯�� dc���� �� ��� �귯�� ��ȯ
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, newBrush);

		Rectangle(hdc, 10 + mX, 10 + mY, 100 + mX, 100 + mY);

		//�ٽ� �����귯������
		SelectObject(hdc, oldBrush);

		// �Ķ� �귯�� ����
		DeleteObject(newBrush);
	}

	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}
}
