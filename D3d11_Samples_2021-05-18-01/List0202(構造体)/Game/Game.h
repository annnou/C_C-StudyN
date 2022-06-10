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
};

// �֐��̃v���g�^�C�v�錾
void Initialize(Game* game, LPCWSTR windowTitle, int screenWidth, int screenHeight);
int Run(Game* game);
