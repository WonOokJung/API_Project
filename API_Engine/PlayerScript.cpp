#include "PlayerScript.h"
#include "Input_Manager.h"
#include "Transform.h"
#include "Time.h"
#include "ap_GameObject.h"
#include "Animator.h"

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
		if (mAnimator == nullptr)
		{
			mAnimator = GetOwner()->GetComponent<Animator>();
		}

		switch (mState)
		{
		case ap::PlayerScript::eState::SitDown:
			sitDown();
			break;
		case ap::PlayerScript::eState::Walk:
			move();
			break;
		case ap::PlayerScript::eState::Sleep:
			break;
		case ap::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

	}
	void PlayerScript::LateUpdate()
	{
	}
	void PlayerScript::Render(HDC hdc)
	{
	}
	void PlayerScript::sitDown()
	{
		if (Input_Manager::GetKeyDown(eKeyCode::D))
		{
			mState = ap::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"RightWalk", true);
		}
		if (Input_Manager::GetKeyDown(eKeyCode::A))
		{
			mState = ap::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"LeftWalk", true);
		}
		if (Input_Manager::GetKeyDown(eKeyCode::S))
		{
			mState = ap::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"DownWalk", true);
		}
		if (Input_Manager::GetKeyDown(eKeyCode::W))
		{
			mState = ap::PlayerScript::eState::Walk;
			mAnimator->PlayAnimation(L"UpWalk", true);
		}
	}
	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input_Manager::GetKey(eKeyCode::D))
		{
			pos.x += 100.0f * Time::Deltatime();
		}
		if (Input_Manager::GetKey(eKeyCode::A))
		{
			pos.x -= 100.0f * Time::Deltatime();
		}
		if (Input_Manager::GetKey(eKeyCode::S))
		{
			pos.y += 100.0f * Time::Deltatime();
		}
		if (Input_Manager::GetKey(eKeyCode::W))
		{
			pos.y -= 100.0f * Time::Deltatime();
		}

		tr->SetPos(pos);

		if (Input_Manager::GetKeyUp(eKeyCode::D) || Input_Manager::GetKeyUp(eKeyCode::A)
			|| Input_Manager::GetKeyUp(eKeyCode::S) || Input_Manager::GetKeyUp(eKeyCode::W))
		{
			mState = ap::PlayerScript::eState::SitDown;
			mAnimator->PlayAnimation(L"SitDown", false);
		}

	}
}