#pragma once
#include "Entity.h"
#include "CommonInclude.h"
#include "ap_GameObject.h"

namespace ap
{
	class Layer
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		void AddGameObject(GameObject* gameObj);
	private:
		//eLayerType mType;
		std::vector<GameObject*> vGameObject;

	public:
		Layer();
		~Layer();
	};
}

