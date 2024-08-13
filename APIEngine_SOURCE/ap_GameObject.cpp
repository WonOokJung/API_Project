#include "ap_GameObject.h"
#include "Input_Manager.h"
#include "Time.h"



namespace ap
{
	void GameObject::Update()
	{
		const float speed = 100.0f;
		if (Input_Manager::GetKey(eKeyCode::A) || Input_Manager::GetKey(eKeyCode::LEFT))
		{
			mX -= speed * Time::Deltatime();
		}

		if (Input_Manager::GetKey(eKeyCode::D) || Input_Manager::GetKey(eKeyCode::RIGHT))
		{
			mX += speed * Time::Deltatime();
		}

		if (Input_Manager::GetKey(eKeyCode::W) || Input_Manager::GetKey(eKeyCode::UP))
		{
			mY -= speed * Time::Deltatime();
		}

		if (Input_Manager::GetKey(eKeyCode::S) || Input_Manager::GetKey(eKeyCode::DOWN))
		{
			mY += speed * Time::Deltatime();
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

		Rectangle(hdc, 100 + mX, 100 + mY, 150 + mX, 150 + mY);

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
