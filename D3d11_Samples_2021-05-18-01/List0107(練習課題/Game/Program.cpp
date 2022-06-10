//=============================================================================
// Program.cpp
// エントリーポイント
//=============================================================================
#include "Game.h"

// アプリケーションのエントリーポイント
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	Initialize(L"Gameタイトル", 640, 480);
	Run();

	return 0;
}
