//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>

// アプリケーション全体を表します。
struct Game {
//public:	// アクセス指定子を省略すると構造体ではpublicになります。
	// アプリケーションを初期化します。
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	// メッセージループを実行します。
	int Run();

private:	// この構造体のメンバーのみアクセスできる
	// ウィンドウのタイトル
	LPCWSTR WindowTitle = L"タイトル";
	// ウィンドウの幅
	int ScreenWidth = 640;
	// ウィンドウの高さ
	int ScreenHeight = 480;
	// ウィンドウのハンドル
	HWND hWnd = NULL;

	bool InitWindow();
};
