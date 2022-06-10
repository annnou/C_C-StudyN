//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>

// アプリケーション全体を表します。
struct Game {
	// ウィンドウのタイトル
	LPCWSTR WindowTitle = L"タイトル";
	// ウィンドウの幅
	int ScreenWidth = 640;
	// ウィンドウの高さ
	int ScreenHeight = 480;
	// ウィンドウのハンドル
	HWND hWnd = NULL;

	// 非静的関数
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	bool InitWindow();
	int Run();
};
