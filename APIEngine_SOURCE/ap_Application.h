#pragma once
#include "ap_GameObject.h"

namespace ap
{
	class Application
	{
	public:
		void Initialize(HWND hwnd, UINT width, UINT height);
		void Run();

		void Update();
		void LateUpdate();
		void Render();

	private:
		HWND mHwnd;
		HDC mHdc;
		HDC mBackHdc;

		// HBITMAP: 압축이 되지 않은 그림파일	
		HBITMAP mBackBuffer;

		float mSpeed;

		// 해상도
		UINT mWidth;
		UINT mHeight;

		GameObject mPlayer;

	public:
		Application();
		~Application();

	private:
		RECT rct;
		LPRECT lpRect;
	};
}

