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
		// 알파블랜더를 사용하려면 해당 이미지에 알파 채널이 있어야 한다.
		if (mTexture == nullptr)
		{
			return;
		}

		GameObject* gameobj = mAnimator->GetOwner();
		Transform* tr = gameobj->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Renderer::mainCamera)
		{
			pos = Renderer::mainCamera->CalculatePosition(pos);
		}

		BLENDFUNCTION func = {};
		func.BlendOp = AC_SRC_OVER;
		func.BlendFlags = 0;
		func.AlphaFormat = AC_SRC_ALPHA;
		func.SourceConstantAlpha = 255;

		Sprite sprite = vAnimationSheet[mIndex];
		HDC imgHDC = mTexture->GetHDC();

		// hdc, x위치, y위치, 그릴 길이x, y, 이미지의 DC, 이미지 크기, 길이, 알파채널
		AlphaBlend(hdc, pos.x, pos.y, sprite.size.x * 5, sprite.size.y * 5
			, imgHDC, sprite.leftTop.x, sprite.leftTop.y, sprite.size.x, sprite.size.y, func);
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
