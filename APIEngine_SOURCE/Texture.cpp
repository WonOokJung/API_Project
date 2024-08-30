#include "Texture.h"
#include "ap_Application.h"
#include <cassert>

// extern �ش� ���������� ������ �˸��� Ű����
extern ap::Application app;

namespace ap::graphics
{
	Texture::Texture()
		: Resource(enums::eResourceType::Texture)
	{
	}
	Texture::~Texture()
	{
	}

	HRESULT Texture::Load(const std::wstring& path)
	{
		std::wstring ext = path.substr(path.find_last_of(L".") + 1);
		//BMP�ϋ�
		if (ext == L"bmp")
		{
			mType = eTextureType::Bmp;
			mBitMap = (HBITMAP)LoadImageW(nullptr, path.c_str(), IMAGE_BITMAP, 0, 0
											, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
			if (mBitMap == nullptr)
			{
				assert(false);
				return S_FALSE;
			}

			BITMAP info = {};
			GetObject(mBitMap, sizeof(BITMAP), &info);

			mWidth = info.bmWidth;
			mHeight = info.bmHeight;

			HDC mainDC = app.GetHDC();
			mHDC = CreateCompatibleDC(mainDC);

			HBITMAP oldBitmap = (HBITMAP)SelectObject(mHDC, mBitMap);
			DeleteObject(oldBitmap);
		}

		//PNG�ϋ�
		else if (ext == L"png")
		{
			mType = eTextureType::Png;
			mImgae = Gdiplus::Image::FromFile(path.c_str());
			if(mImgae == nullptr)
			{
				return S_FALSE;
			}
			mWidth = mImgae->GetWidth();
			mHeight = mImgae->GetHeight();
		}
		return S_OK;
	}
}