#pragma once
#include "Scene.h"

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

		HDC GetHDC() { return mHdc; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		void ClearRenderTarget();
		void CopyRenderTarget(HDC source, HDC dest);
		void SetBackBuffer(HWND hwnd, UINT width, UINT height);

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

		//GameObject mPlayer;
		//std::vector<GameObject*> vGameObject;
		
		//각각의 씬이 오브젝트를 들고있는 형태
		
	
	public:
		Application();
		~Application();

	private:
		RECT rct;
		LPRECT lpRect;
	};
}

