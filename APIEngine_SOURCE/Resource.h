#pragma once
#include "Entity.h"

namespace ap
{
	class Resource abstract : public Entity
	{
	public:
		virtual HRESULT Load(const std::wstring& path) = 0; // ���������Լ� -> ���� �޸𸮿� �Ҵ� �Ұ���
															  // ��ӹ޾Ƽ� ���

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
