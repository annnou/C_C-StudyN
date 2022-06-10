//=============================================================================
// Program.cpp
// エントリーポイント
//=============================================================================
#include <Windows.h>

// アプリケーションのエントリーポイント
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)// 文字コード　nCmdLine --画面最小最大化
{
	// ウィンドウ ハンドル
	HWND hWnd = NULL;

	// ウィンドウを作成する
	hWnd = CreateWindowEx(
		0,						// オプションのウィンドウ スタイル  EX
		L"Static",				// システムで事前定義されているウィンドウ クラス 何にもしないSTATIC
		L"タイトル",			// ウィンドウ テキスト
		WS_OVERLAPPEDWINDOW,	// ウィンドウ スタイル
		CW_USEDEFAULT, CW_USEDEFAULT,	// ウィンドウの位置
		640, 480,	// ウィンドウ サイズ
		NULL,		// 親ウィンドウ
		NULL,		// メニュー
		hInstance,	// インスタンス ハンドル
		NULL);		// 追加のアプリケーション データ
	if (hWnd == NULL) {
		MessageBox(NULL, L"ウィンドウの作成に失敗しました。", L"エラー", MB_OK);
		return -1;
	}

	// ウィンドウの表示指示を出すためにウィンドウ ハンドルを指定する
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, L"ウィンドウが表示されましたか？", L"確認", MB_OK);

	return 0;
}
