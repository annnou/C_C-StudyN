

#include "Game.h"

//今後これがポインタにかかわってくるのでこの時点で
//この書き方がおかしいらしいのは意図がある
HWND hWnd = NULL;
LPCWSTR WindowTitle = L"TITLE VIEW";
int ScreenWidth = 640;
int ScreenHeight = 480;

//関数プロトタイプ宣言
bool InitWindow();
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM Param);

void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight)
{
	WindowTitle = windowTitle;
	ScreenWidth = screenWidth;
	ScreenHeight = screenHeight;
}

//window create
//success return true
bool InitWindow()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);

	// ウィンドウ クラスを登録する
	const wchar_t CLASS_NAME[] = L"GameWindow";
	WNDCLASSEX wndClass = {};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = WindowProc;	// ウィンドウ プロシージャーを指定
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wndClass.lpszClassName = CLASS_NAME;
	if (!RegisterClassEx(&wndClass)) {
		OutputDebugString(L"ウィンドウ クラスの登録に失敗しました。");
		return false;
	}

	// クライアント領域が指定した解像度になるウィンドウサイズを計算
	RECT rect = { 0, 0, ScreenWidth, ScreenHeight };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, FALSE, 0);

	// ウィンドウを作成する
	hWnd = CreateWindowEx(0,
		CLASS_NAME,	// ウィンドウ クラス
		WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),
		NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		OutputDebugString(L"ウィンドウの作成に失敗しました。");
		return false;
	}

	// ウィンドウを表示
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);


	return true;
}

// ウィンドウ・メッセージを処理するプロシージャー
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CLOSE:
		// ウィンドウを閉じる
		if (MessageBox(hWnd, L"ウィンドウを閉じますか？", L"情報", MB_OKCANCEL) == IDOK) {
			DestroyWindow(hWnd);
		}
		return 0;

	case WM_DESTROY:
		// アプリケーションを終了
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		// 参考：Windows APIによる図形描画
		PAINTSTRUCT ps;
		auto hdc = BeginPaint(hWnd, &ps);
		RECT rect = {};
		rect.left = 200;
		rect.top = 100;
		rect.right = 300;
		rect.bottom = 200;
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hWnd, &ps);
	}
	break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int Run()
{
	// ウィンドウを作成
	if (!InitWindow()) {
		MessageBox(NULL, L"ウィンドウの作成に失敗しました。", L"エラー", MB_OK);
		return -1;
	}

	// メッセージループを実行
	MSG msg = {};
	while (true) {
		// このウィンドウのメッセージが存在するかを確認
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			// メッセージを取得
			if (!GetMessage(&msg, NULL, 0, 0)) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		//ここで3Dプログラミングのフレーム更新処理
		//3D GAME 作成ならここ頑張りたい

	}

	return (int)msg.wParam;
}