#include "Component.h"

namespace ap
{
	Component::Component(enums::eComponentType type)
		:mType(type)
	{
	}
	Component::~Component()
	{
	}

	void ap::Component::Initialize()
	{
	}

	void ap::Component::Update()
	{
	}

	void ap::Component::LateUpdate()
	{
	}

	void ap::Component::Render(HDC hdc)
	{
	}
}