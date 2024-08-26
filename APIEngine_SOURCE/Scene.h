#pragma once
#include "Entity.h"
#include "ap_GameObject.h"
#include "Layer.h"

namespace ap
{
	class Scene : public Entity
	{
	public:
		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		virtual void OnEnter();
		virtual void OnExit();

		void AddGameObject(GameObject* gameObj, const enums::eLayerType layerType);
		Layer* GetLayer(const enums::eLayerType layerType) { return vLayers[(UINT)layerType]; }

	private:
		//std::vector<GameObject*> vGameObject;
		std::vector<Layer*> vLayers;


	public:
		Scene();
		~Scene();
	};
}