//=============================================================================
// Program.cpp
// �G���g���[�|�C���g
//=============================================================================
#include "Game.h"

// �A�v���P�[�V�����̃G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// �A�v���P�[�V�����̋N���ݒ�
	Initialize(L"Game�^�C�g��", 640, 480);
	// ���b�Z�[�W ���[�v�����s
	Run();

	return 0;
}
