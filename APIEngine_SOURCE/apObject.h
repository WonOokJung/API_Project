#pragma once
#include "Component.h"
#include "ap_GameObject.h"
#include "Layer.h"
#include "Scene.h"
#include "Scene_Manager.h"
#include "Transform.h"

namespace ap::object 
{
	template <typename T>
	static T* Instantiate(ap::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = Scene_Manager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(ap::enums::eLayerType type, math::Vector2 pos)
	{
		T* gameObject = new T();
		Scene* activeScene = Scene_Manager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);
		
		Transform* transfom = gameObject->GetComponent<Transform>();
		transfom->SetPos(pos);

		return gameObject;
	}
}