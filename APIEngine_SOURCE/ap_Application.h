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

		// HBITMAP: ������ ���� ���� �׸�����	
		HBITMAP mBackBuffer;

		float mSpeed;

		// �ػ�
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

