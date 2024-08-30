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

		// HBITMAP: ������ ���� ���� �׸�����	
		HBITMAP mBackBuffer;

		float mSpeed;

		// �ػ�
		UINT mWidth;
		UINT mHeight;

		//GameObject mPlayer;
		//std::vector<GameObject*> vGameObject;
		
		//������ ���� ������Ʈ�� ����ִ� ����
		
	
	public:
		Application();
		~Application();

	private:
		RECT rct;
		LPRECT lpRect;
	};
}

