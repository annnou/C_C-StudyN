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
	// MB_OKCANCEL���w�肷��ƁwOK�x�{�^���ƁwCANCEL�x�{�^����\��
	if (MessageBox(NULL, L"�����Ƀ��b�Z�[�W���\������܂��B", L"����",
		MB_OKCANCEL) == IDOK) {
		MessageBox(NULL, L"OK����܂����B", L"����", MB_OK);
	}
	else {
		MessageBox(NULL, L"�L�����Z������܂����B", L"����", MB_OK);
	}

	return 0;
}