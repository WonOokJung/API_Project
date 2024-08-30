#include "Player.h"
#include "Input_Manager.h"
#include "Transform.h"
#include "Time.h"

namespace ap
{
	void Player::Initialize()
	{
		GameObject::Initialize();
	}

	void Player::Update()
	{
		GameObject::Update();
	}

	void Player::LateUpdate()
	{
		GameObject::LateUpdate();

	}

	void Player::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}
}