#pragma once
#include "CommonInclude.h"
#include "Component.h"

namespace ap
{
	class GameObject
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		//void KeyInput();

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->SetOwner(this);
			vComponents.push_back(comp);

			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : vComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}

			return component;
		}


	private:
		// 컴포넌트 목록
		std::vector<Component*> vComponents;

	public:
		GameObject();
		~GameObject();
	};
}

