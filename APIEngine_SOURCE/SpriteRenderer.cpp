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
		pos = Renderer::mainCamera->CalculatePosition(pos);

		if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Bmp)
		{
			TransparentBlt(hdc, pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y, mTexture->GetHDC()
				, 0, 0, mTexture->GetWidth(), mTexture->GetHeight(), RGB(255, 0, 255));
		}

		else if (mTexture->GetTextureType() == graphics::Texture::eTextureType::Png)
		{
			Gdiplus::Graphics graphcis(hdc);
			graphcis.DrawImage(mTexture->GetImage(), 
					Gdiplus::Rect(pos.x, pos.y, mTexture->GetWidth() * mSize.x, mTexture->GetHeight() * mSize.y));
		}

		//Gdiplus::Graphics graphcis(hdc);
		//graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}


}
