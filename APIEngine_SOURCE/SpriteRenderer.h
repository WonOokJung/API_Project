#pragma once
#include "Entity.h"
#include "Component.h"

namespace ap
{
	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void ImageLoad(const std::wstring& path);

	private:
		Gdiplus::Image* mImgae;
		UINT mWidth;
		UINT mHeight;

	public:
		SpriteRenderer();
		~SpriteRenderer();
	};

}
