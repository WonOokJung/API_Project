#pragma once
#include "Entity.h"
#include "Component.h"

namespace ap
{
	using namespace math;
	class Transform : public Component
	{
	public:
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetPos(Vector2 pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
		Vector2 GetPosition() { return mPosition; }

	private:
		Vector2 mPosition;

	public:
		Transform();
		~Transform();
	};
}
