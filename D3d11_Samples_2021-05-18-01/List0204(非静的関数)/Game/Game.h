//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>

// �A�v���P�[�V�����S�̂�\���܂��B
struct Game {
	// �E�B���h�E�̃^�C�g��
	LPCWSTR WindowTitle = L"�^�C�g��";
	// �E�B���h�E�̕�
	int ScreenWidth = 640;
	// �E�B���h�E�̍���
	int ScreenHeight = 480;
	// �E�B���h�E�̃n���h��
	HWND hWnd = NULL;

	// ��ÓI�֐�
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	bool InitWindow();
	int Run();
};
