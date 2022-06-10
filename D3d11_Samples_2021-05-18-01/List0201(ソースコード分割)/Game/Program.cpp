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
	// アプリケーションの起動設定
	Initialize(L"Gameタイトル", 640, 480);
	// メッセージ ループを実行
	Run();

	return 0;
}
