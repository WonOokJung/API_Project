#include "PlayerScript.h"
#include "Input_Manager.h"
#include "Transform.h"
#include "Time.h"
#include "ap_GameObject.h"

namespace ap
{
	PlayerScript::PlayerScript()
	{
	}
	PlayerScript::~PlayerScript()
	{
	}

	void PlayerScript::Initialize()
	{
	}
	void PlayerScript::Update()
	{
		if (Input_Manager::GetKey(eKeyCode::D))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x += 100.0f * Time::Deltatime();
			tr->SetPos(pos);
		}
		if (Input_Manager::GetKey(eKeyCode::A))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.x -= 100.0f * Time::Deltatime();
			tr->SetPos(pos);
		}
		if (Input_Manager::GetKey(eKeyCode::S))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y += 100.0f * Time::Deltatime();
			tr->SetPos(pos);
		}
		if (Input_Manager::GetKey(eKeyCode::W))
		{
			Transform* tr = GetOwner()->GetComponent<Transform>();
			Vector2 pos = tr->GetPosition();
			pos.y -= 100.0f * Time::Deltatime();
			tr->SetPos(pos);
		}
	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
}