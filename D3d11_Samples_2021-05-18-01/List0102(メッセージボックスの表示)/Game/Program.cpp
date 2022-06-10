//=============================================================================
// Program.cpp
// 
//=============================================================================
#include <Windows.h>

// エントリーポイント
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// メッセージボックスを表示
	MessageBox(
		NULL,	// ウィンドウ ハンドル（List0103で解説）
		L"ここにメッセージが表示されます。",
		L"タイトル",
		MB_ABORTRETRYIGNORE);	// 『OK』ボタンのみ表示

	return 0;
}