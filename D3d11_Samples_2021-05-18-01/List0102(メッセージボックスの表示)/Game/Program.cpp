//=============================================================================
// Program.cpp
// 
//=============================================================================
#include <Windows.h>

// �G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// ���b�Z�[�W�{�b�N�X��\��
	MessageBox(
		NULL,	// �E�B���h�E �n���h���iList0103�ŉ���j
		L"�����Ƀ��b�Z�[�W���\������܂��B",
		L"�^�C�g��",
		MB_ABORTRETRYIGNORE);	// �wOK�x�{�^���̂ݕ\��

	return 0;
}