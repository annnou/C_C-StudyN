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
	Initialize(L"Game�^�C�g��", 640, 480);
	Run();

	return 0;
}
