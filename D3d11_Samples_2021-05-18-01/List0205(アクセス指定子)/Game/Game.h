//=============================================================================
// Game.h
// 
//=============================================================================
#pragma once

#include <Windows.h>

// �A�v���P�[�V�����S�̂�\���܂��B
struct Game {
//public:	// �A�N�Z�X�w��q���ȗ�����ƍ\���̂ł�public�ɂȂ�܂��B
	// �A�v���P�[�V���������������܂��B
	void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight);
	// ���b�Z�[�W���[�v�����s���܂��B
	int Run();

private:	// ���̍\���̂̃����o�[�̂݃A�N�Z�X�ł���
	// �E�B���h�E�̃^�C�g��
	LPCWSTR WindowTitle = L"�^�C�g��";
	// �E�B���h�E�̕�
	int ScreenWidth = 640;
	// �E�B���h�E�̍���
	int ScreenHeight = 480;
	// �E�B���h�E�̃n���h��
	HWND hWnd = NULL;

	bool InitWindow();
};
