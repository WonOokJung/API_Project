#include "Input_Manager.h"

namespace ap
{
	std::vector<Input_Manager::sKey> Input_Manager::vKeys = {};

	int ASCHII[(UINT)eKeyCode::END]
	{
		'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
		'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
		'Z', 'X', 'C', 'V', 'B', 'N', 'M',
		VK_LEFT, VK_RIGHT, VK_UP, VK_DOWN,
	};

	void ap::Input_Manager::Initialize()
	{
		typedef int DOGUEINT;

		DOGUEINT a = 0;

		vKeys.resize((UINT)eKeyCode::END);

		for (size_t i = 0; i < (UINT)eKeyCode::END; ++i)
		{
			sKey key = {};
			key.bPressed = false;
			key.state = eKeyState::None;
			key.keyCode = (eKeyCode)i;

			vKeys.push_back(key);
		}
	}

	void ap::Input_Manager::Update()
	{
		for (size_t i = 0; i < vKeys.size(); ++i)
		{
			//키가 눌렸다
			if (GetAsyncKeyState(ASCHII[i]) & 0x8000)
			{
				if (vKeys[i].bPressed == true)
				{
					vKeys[i].state = eKeyState::Pressed; 
				}
				else
				{
					vKeys[i].state = eKeyState::Down;
				}

				vKeys[i].bPressed = true;
			}
			//키가 안눌렸다
			else
			{
				if (vKeys[i].bPressed == true)
				{
					vKeys[i].state = eKeyState::Up;
				}
				else
				{
					vKeys[i].state = eKeyState::None;
				}

				vKeys[i].bPressed = false;
			}
		}
	}
}
