#include "Time.h"

namespace ap
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltatimeValue = 0.0f;

	void Time::Initialize()
	{
		//CPU고유 진동수
		QueryPerformanceFrequency(&CpuFrequency);
		
		//프로그램이 시작 되었을 때 현재 진동수
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		// 델타타임 : 1프레임당 걸리는 시간
		// 프로그램이 끝났을때 걸린 진동수에서 프로그램이 처음에 시작했을때 걸린 진동수를 뺴준후 우리 CPU의 고유진동수로 나누기
		float differenceFrequency
			= static_cast<float>(CurrentFrequency.QuadPart - PrevFrequency.QuadPart);

		DeltatimeValue = differenceFrequency / static_cast<float>(CpuFrequency.QuadPart);
		PrevFrequency.QuadPart = CurrentFrequency.QuadPart;

	}
	void Time::Render(HDC hdc)
	{
		static float time = 0.0f;

		time += DeltatimeValue;
		float fps = 1.0f / DeltatimeValue;

		// 델타타임
		wchar_t str[50] = L"";
		wchar_t str2[50] = L"";

		swprintf_s(str, 50, L"Time : %f", time);
		swprintf_s(str2, 50, L"FPS : %d", (int)fps);
		int len = wcsnlen_s(str, 50);
		int len2 = wcsnlen_s(str2, 50);


		TextOut(hdc, 0, 0, str, len);
		TextOut(hdc, 0, 20, str2, len2);
	}
}