#pragma once
#include "CommonInclude.h"

namespace ap
{
	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None
	};

	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		LEFT, RIGHT, UP, DOWN,
		END
	};

	class Input_Manager
	{


	public:
		struct sKey
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

	public:
		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return vKeys[(UINT)code].state == eKeyState::Down; }
		static bool GetKeyUp(eKeyCode code) { return vKeys[(UINT)code].state == eKeyState::Up; }
		static bool GetKey(eKeyCode code) { return vKeys[(UINT)code].state == eKeyState::Pressed; }

	private:
		//eKeyState mState[] = eKeyState::Up;
		// static: 정적, 해당 클래스 내에서만 전역적임
		static std::vector<sKey> vKeys;
	};

}