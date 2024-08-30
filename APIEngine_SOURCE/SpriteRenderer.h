#pragma once
#include "Entity.h"
#include "Component.h"
#include "Texture.h"

namespace ap
{
	class SpriteRenderer : public Component
	{
	public:
		void Initialize() override;
		void Update()  override;
		void LateUpdate()  override;
		void Render(HDC hdc)  override;

		void SetTexture(graphics::Texture* texture) { mTexture = texture; }
		void SetSize(math::Vector2 size) { mSize = size; }

	private:
		graphics::Texture* mTexture;
		math::Vector2 mSize;

	public:
		SpriteRenderer();
		~SpriteRenderer();
	};

}
