#include "Scene.h"

namespace ap
{
	Scene::Scene()
		: vLayers{}
	{
		vLayers.resize((UINT)enums::eLayerType::Max);
	
		for (size_t i = 0u; i < (UINT)enums::eLayerType::Max; ++i)
		{
			vLayers[i] = new Layer;
		}
	}
	Scene::~Scene()
	{
	}

	void Scene::Initialize()
	{
		for (Layer* layer : vLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Initialize();
		}
	}

	void Scene::Update()
	{
		for (Layer* layer : vLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Update();
		}
	}

	void Scene::LateUpdate()
	{
		for (Layer* layer : vLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->LateUpdate();
		}
	}

	void Scene::Render(HDC hdc)
	{
		for (Layer* layer : vLayers)
		{
			if (layer == nullptr)
			{
				continue;
			}

			layer->Render(hdc);
		}
	}

	void Scene::OnEnter()
	{
	}

	void Scene::OnExit()
	{
	}
	void Scene::AddGameObject(GameObject* gameObj, const enums::eLayerType layerType)
	{
		vLayers[(UINT)layerType]->AddGameObject(gameObj);
	}
}