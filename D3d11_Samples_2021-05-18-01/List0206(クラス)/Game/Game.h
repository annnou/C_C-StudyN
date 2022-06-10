//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>

// �A�v���P�[�V�����S�̂�\���܂��B
class Game {
//private:	// �N���X�ŃA�N�Z�X�w��q���ȗ������private�ɂȂ�܂��B
	// �E�B���h�E�̃^�C�g��
	LPCWSTR WindowTitle = L"�^�C�g��";
	// �E�B���h�E�̕�
	int ScreenWidth = 640;
	// �E�B���h�E�̍���
	int ScreenHeight = 480;
	// �E�B���h�E�̃n���h��
	HWND hWnd = NULL;

public:
	// �A�v���P�[�V���������������܂��B
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	// ���b�Z�[�W���[�v�����s���܂��B
	int Run();

private:
	bool InitWindow();
};
