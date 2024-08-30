#pragma once
#include "Script.h"

namespace ap
{
	class PlayerScript : public Script
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:

	public:
		PlayerScript();
		~PlayerScript();

	};
}

