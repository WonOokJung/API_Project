#pragma once
#include "..\\APIEngine_SOURCE\Resources.h"
#include "..\\APIEngine_SOURCE\Texture.h"

namespace ap
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\dnr16\\source\\repos\\API_Project\\Resources\\CloudOcean.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"C:\\Users\\dnr16\\source\\repos\\API_Project\\Resources\\PackMan.png");
	}
}
