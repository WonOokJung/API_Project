#pragma once
#include "Resource.h"

namespace ap::graphics
{
	class Texture : public Resource
	{
	public:
		enum class eTextureType
		{
			Bmp,
			Png,
			None,
		};

	public:
		HRESULT Load(const std::wstring& path) override;

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }
		HDC GetHDC() { return mHDC; }
		eTextureType GetTextureType() { return mType; }
		Gdiplus::Image* GetImage() { return mImgae; }

	private:
		Gdiplus::Image* mImgae;
		HBITMAP mBitMap;
		HDC mHDC;
		eTextureType mType;

		UINT mWidth;
		UINT mHeight;

	public:
		Texture();
		~Texture();
	};
}
