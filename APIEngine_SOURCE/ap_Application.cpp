#include "ap_Application.h"
#include "Input_Manager.h"
#include "Time.h"

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
		RECT rect = { 0, 0, width, height };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		mWidth = rect.right - rect.left;
		mHeight = rect.bottom - rect.top;
		
		SetWindowPos(mHwnd, nullptr, 0, 0, mWidth, mHeight, 0);
		ShowWindow(mHwnd, true);

		// ������ �ػ󵵿� �´� ����� ����
		mBackBuffer = CreateCompatibleBitmap(mHdc, width, height);

		// ���λ����� ����۸� ����ų DC����
		mBackHdc = CreateCompatibleDC(mHdc);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mBackHdc, mBackBuffer);
		DeleteObject(oldBitmap);

		mPlayer.SetPosition(0.f, 0.f);

		Input_Manager::Initialize();
		Time::Initialize();
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

		mPlayer.Update();
	}

	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Rectangle(mBackHdc, 0, 0, mWidth, mHeight);

		Time::Render(mBackHdc);
		mPlayer.Render(mBackHdc);

		// �׷��� DC�� ���� DC��
		BitBlt(mHdc, 0, 0, mWidth, mHeight, 
			 mBackHdc, 0, 0, SRCCOPY);
	}

}
