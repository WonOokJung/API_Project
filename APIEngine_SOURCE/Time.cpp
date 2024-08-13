#include "Time.h"

namespace ap
{
	LARGE_INTEGER Time::CpuFrequency = {};
	LARGE_INTEGER Time::PrevFrequency = {};
	LARGE_INTEGER Time::CurrentFrequency = {};
	float Time::DeltatimeValue = 0.0f;

	void Time::Initialize()
	{
		//CPU���� ������
		QueryPerformanceFrequency(&CpuFrequency);
		
		//���α׷��� ���� �Ǿ��� �� ���� ������
		QueryPerformanceCounter(&PrevFrequency);
	}
	void Time::Update()
	{
		QueryPerformanceCounter(&CurrentFrequency);

		// ��ŸŸ�� : 1�����Ӵ� �ɸ��� �ð�
		// ���α׷��� �������� �ɸ� ���������� ���α׷��� ó���� ���������� �ɸ� �������� ������ �츮 CPU�� ������������ ������
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

		// ��ŸŸ��
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