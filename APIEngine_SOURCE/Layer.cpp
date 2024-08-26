#include "Layer.h"

namespace ap
{
	Layer::Layer()
		: vGameObject{}
	{
	}

	Layer::~Layer()
	{
	}

	void Layer::Initialize()
	{
		for (GameObject* gameObj : vGameObject)
		{
			if (gameObj == nullptr)
			{
				continue;
			}
			gameObj->Initialize();
		}
	}

	void Layer::Update()
	{
		for (GameObject* gameObj : vGameObject)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Update();
		}
	}

	void Layer::LateUpdate()
	{
		for (GameObject* gameObj : vGameObject)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->LateUpdate();
		}
	}

	void Layer::Render(HDC hdc)
	{
		for (GameObject* gameObj : vGameObject)
		{
			if (gameObj == nullptr)
			{
				continue;
			}

			gameObj->Render(hdc);
		}
	}

	void Layer::AddGameObject(GameObject* gameObj)
	{
		if (gameObj == nullptr)
		{
			return;
		}

		vGameObject.push_back(gameObj);
	}
}
