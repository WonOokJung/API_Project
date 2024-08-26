#include "ap_Application.h"
#include "Input_Manager.h"
#include "Time.h"
#include "Scene_Manager.h"

namespace ap
{
	Application::Application()
		: mHwnd(nullptr)
		, mHdc(nullptr)
		, mSpeed(0.0f)
		, mWidth(0)
		, mHeight(0)
		, mBackHdc(NULL)
		, mBackBuffer(NULL)
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize(HWND hwnd, UINT width, UINT height)
	{
		mHwnd = hwnd;
		mHdc = GetDC(hwnd);

		SetBackBuffer(hwnd, width, height);

		Input_Manager::Initialize();
		Time::Initialize();
		Scene_Manager::Initialize();
	}

	void Application::Run()
	{
		Update();
		LateUpdate();
		Render();
	}

	void Application::Update()
	{
		Input_Manager::Update();
		Time::Update();
		Scene_Manager::Update();
	}

	void Application::LateUpdate()
	{
		Scene_Manager::LateUpdate();
	}

	void Application::Render()
	{
		ClearRenderTarget();

		Time::Render(mBackHdc);
		Scene_Manager::Render(mBackHdc);

		CopyRenderTarget(mBackHdc, mHdc);

	}


	void Application::ClearRenderTarget()
	{
		Rectangle(mBackHdc, -1, -1, mWidth + 1, mHeight + 1);
	}

	void Application::CopyRenderTarget(HDC source, HDC dest)
	{
		// 그려진 DC를 앞의 DC로
		BitBlt(dest, 0, 0, mWidth, mHeight, source, 0, 0, SRCCOPY);
	}

	void Application::SetBackBuffer(HWND hwnd, UINT width, UINT height)
	{
		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;

		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// 윈도우 해상도에 맞는 백버퍼 생성
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// 새로생성한 백버퍼를 가르킬 DC생성
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);
	}

}
