#include "SpriteRenderer.h"
#include "ap_GameObject.h"
#include "Transform.h"
#include "Texture.h"
#include "Renderer.h"

namespace ap
{
	ap::SpriteRenderer::SpriteRenderer()
		: Component(enums::eComponentType::SpriteRenderer)
		, mSize(Vector2::One)
		, mTexture(nullptr)
		
	{
	}

	ap::SpriteRenderer::~SpriteRenderer()
	{
	}

	void ap::SpriteRenderer::Initialize()
	{
	}

	void ap::SpriteRenderer::Update()
	{
	}

	void ap::SpriteRenderer::LateUpdate()
	{
	}

	void ap::SpriteRenderer::Render(HDC hdc)
	{
		if (mTexture == nullptr)
		{
			assert(false);
		}
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 Scale = tr->GetScale();

		pos = Renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth() * mSize.x * Scale.x, mTexture->GetHeight() * mSize.y * Scale.y, mTexture->GetHDC()
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			// 내가 원하는 픽셀을 투명화 시킬때
			Gdiplus::ImageAttributes imgAtt = {};
			// 투명화 시킬 픽셀의 색 범위 지정
			imgAtt.SetColorKey(Gdiplus::Color(200, 200, 200), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-pos.x, -pos.y);

			graphics.DrawImage(mTexture->GetImage(),
					Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x * Scale.x, mTexture->GetHeight() * mSize.y * Scale.y)
					, 0, 0
					, mTexture->GetWidth(), mTexture->GetHeight()
					, Gdiplus::UnitPixel, nullptr);
		}

		//Gdiplus::Graphics graphcis(hdc);
		//graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}


}
