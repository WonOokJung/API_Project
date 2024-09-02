#include "Animation.h"
#include "Time.h"
#include "Transform.h"
#include "ap_GameObject.h"
#include "Animator.h"
#include "Renderer.h"
#include "Camera.h"

namespace ap
{
	Animation::Animation()
		: Resource(enums::eResourceType::Animation)
		, mAnimator(nullptr)
		, mTexture(nullptr)
		, vAnimationSheet{}
		, mIndex(-1)
		, mTime(0.0f)
		, mbComplete(false)
	{
	}

	Animation::~Animation()
	{
	}

	HRESULT Animation::Load(const std::wstring& path)
	{
		return E_NOTIMPL;
	}

	void Animation::Update()
	{
		if (mbComplete)
		{
			return;
		}

		mTime += Time::Deltatime();

		if (vAnimationSheet[mIndex].duration < mTime)
		{
			mTime = 0.0f;
			if (mIndex < vAnimationSheet.size() - 1)
			{
				mIndex++;
			}
			else
			{
				mbComplete = true;
			}
		}
	}

	void Animation::Render(HDC hdc)
	{
		// ���ĺ����� ����Ϸ��� �ش� �̹����� ���� ä���� �־�� �Ѵ�.
		if (mTexture == nullptr)
		{
			return;
		}

		GameObject* gameobj = mAnimator->GetOwner();
		Transform* tr = gameobj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		float rotation = tr->GetRotation();
		Vector2 Scale = tr->GetScale();

		if (Renderer::mainCamera)
		{
			pos = Renderer::mainCamera->CalculatePosition(pos);
		}

		graphics::Texture::eTextureType type = mTexture->GetTextureType();
		Sprite sprite = vAnimationSheet[mIndex];

		if (type == graphics::Texture::eTextureType::Bmp)
		{
			BLENDFUNCTION func = {};
			func.BlendOp = AC_SRC_OVER;
			func.BlendFlags = 0;
			func.AlphaFormat = AC_SRC_ALPHA;
			func.SourceConstantAlpha = 255;

			HDC imgHDC = mTexture->GetHDC();

			// hdc, x��ġ, y��ġ, �׸� ����x, y, �̹����� DC, �̹��� ũ��, ����, ����ä��
			AlphaBlend(hdc, pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f)
				, sprite.size.x * Scale.x, sprite.size.y * Scale.y
				, imgHDC, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
		}
		else if (type == graphics::Texture::eTextureType::Png)
		{
			// ���� ���ϴ� �ȼ��� ����ȭ ��ų��
			Gdiplus::ImageAttributes imgAtt = {};

			// ����ȭ ��ų �ȼ��� �� ���� ����
			imgAtt.SetColorKey(Gdiplus::Color(230, 230, 230), Gdiplus::Color(255, 255, 255));

			Gdiplus::Graphics graphics(hdc);

			graphics.TranslateTransform(pos.x, pos.y);
			graphics.RotateTransform(rotation);
			graphics.TranslateTransform(-pos.x, -pos.y);


			graphics.DrawImage(
				mTexture->GetImage()
				, Gdiplus::Rect(pos.x - (sprite.size.x / 2.0f), pos.y - (sprite.size.y / 2.0f)
					, sprite.size.x * Scale.x, sprite.size.y * Scale.y)
				, sprite.leftTop.x, sprite.leftTop.y
				, sprite.size.x * Scale.x, sprite.size.y * Scale.y
				, Gdiplus::UnitPixel, nullptr
			);
		}

	}

	void Animation::CreateAnimation(const std::wstring name, graphics::Texture* spriteSheet, Vector2 leftTop, Vector2 size, Vector2 offset, UINT spriteLength, float duration)
	{
		mTexture = spriteSheet;
		for (size_t i = 0u; i < spriteLength; ++i)
		{
			Sprite sprite = {};
			sprite.leftTop.x = leftTop.x + (size.x * i);
			sprite.leftTop.y = leftTop.y;
			sprite.size = size;
			sprite.offset = offset;
			sprite.duration = duration;

			vAnimationSheet.push_back(sprite);
		}
	}

	void Animation::Reset()
	{
		mTime = 0.0f;
		mIndex = 0;
		mbComplete = false;
	}
}
