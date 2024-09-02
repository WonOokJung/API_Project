#include "Transform.h"

namespace ap
{
	Transform::Transform()
		: Component(enums::eComponentType::Transform)
		, mScale(Vector2::One)
		, mRotation(0.0f)
	{
	}
	Transform::~Transform()
	{
	}
	void Transform::LateUpdate()
	{
	}
	void Transform::Render(HDC hdc)
	{
	}
}