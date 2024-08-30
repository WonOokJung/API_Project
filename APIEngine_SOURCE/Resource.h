#pragma once
#include "Entity.h"

namespace ap
{
	class Resource abstract : public Entity
	{
	public:
		virtual HRESULT Load(const std::wstring& path) = 0; // 순수가상함수 -> 실제 메모리에 할당 불가능
															  // 상속받아서 써라

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		enums::eResourceType mType;
		std::wstring mPath;

	public:
		Resource(enums::eResourceType type);
		virtual ~Resource() {}
	};
}
