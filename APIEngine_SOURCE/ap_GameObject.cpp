#include "ap_GameObject.h"
#include "Input_Manager.h"
#include "Time.h"



namespace ap
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
		for (Component* comp : vComponents)
		{
			delete comp;
			comp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : vComponents)
		{
			comp->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : vComponents)
		{
			comp->Update();
		}
		//KeyInput();
	}
	void GameObject::LateUpdate()
	{
		for (Component* comp : vComponents)
		{
			comp->LateUpdate();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		for (Component* comp : vComponents)
		{
			comp->Render(hdc);
		}
	}

	/*
	void GameObject::KeyInput()
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
	*/

}
