#pragma once
#include "ap_GameObject.h"

namespace ap
{
	class Application
	{
	public:
		void Initialize(HWND hwnd);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;

		float mSpeed;


		GameObject mPlayer;

	public:
		Application();
		~Application();
	};
}

