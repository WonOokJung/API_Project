#pragma once
#include "CommonInclude.h"

namespace ap
{
	class Entity
	{
	public:
		void SetName(const std::wstring& name) { mName = name; }
		std::wstring& GetName() { return mName; }


	private:
		std::wstring mName;

	public:
		Entity();
		virtual ~Entity();
	};
}
