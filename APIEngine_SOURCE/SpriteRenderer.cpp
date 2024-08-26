#include "SpriteRenderer.h"
#include "ap_GameObject.h"
#include "Transform.h"

namespace ap
{
	ap::SpriteRenderer::SpriteRenderer()
		: mImgae(nullptr)
		, mWidth(0)
		, mHeight(0)
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
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Gdiplus::Graphics graphcis(hdc);
		graphcis.DrawImage(mImgae, Gdiplus::Rect(pos.x, pos.y, mWidth, mHeight));
	}

	void SpriteRenderer::ImageLoad(const std::wstring& path)
	{
		mImgae = Gdiplus::Image::FromFile(path.c_str());
		mWidth = mImgae->GetWidth();
		mHeight = mImgae->GetHeight();
	}
}
