//=============================================================================
// Program.cpp
// エントリーポイント
//=============================================================================
#include <Windows.h>

// アプリケーションのエントリーポイント
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// ウィンドウ ハンドル
	HWND hWnd = NULL;

	// クライアント領域が指定した解像度になるウィンドウサイズを計算
	RECT rect = { 0, 0, 640, 480 };
	AdjustWindowRectEx(
		&rect,
		WS_OVERLAPPEDWINDOW,	// ウィンドウ スタイル
		FALSE,
		0);	// オプションのウィンドウ スタイル

	// ウィンドウを作成する
	hWnd = CreateWindowEx(
		0,	// オプションのウィンドウ スタイル
		L"Static",
		L"タイトル",
		WS_OVERLAPPEDWINDOW,	// ウィンドウ スタイル
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),	// ウィンドウ サイズ
		NULL,
		NULL,	// メニュー
		hInstance, NULL);
	if (hWnd == NULL) {
		MessageBox(NULL, L"ウィンドウの作成に失敗しました。", L"エラー", MB_OK);
		return false;
	}

	// ウィンドウの表示指示を出すためにウィンドウ ハンドルを指定する
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, L"ウィンドウが表示されましたか？", L"確認", MB_OK);

	return 0;
}
