//=============================================================================
// Program.cpp
// �G���g���[�|�C���g
//=============================================================================
#include <Windows.h>

// �A�v���P�[�V�����̃G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)// �����R�[�h�@nCmdLine --��ʍŏ��ő剻
{
	// �E�B���h�E �n���h��
	HWND hWnd = NULL;

	// �E�B���h�E���쐬����
	hWnd = CreateWindowEx(
		0,						// �I�v�V�����̃E�B���h�E �X�^�C��  EX
		L"Static",				// �V�X�e���Ŏ��O��`����Ă���E�B���h�E �N���X ���ɂ����Ȃ�STATIC
		L"�^�C�g��",			// �E�B���h�E �e�L�X�g
		WS_OVERLAPPEDWINDOW,	// �E�B���h�E �X�^�C��
		CW_USEDEFAULT, CW_USEDEFAULT,	// �E�B���h�E�̈ʒu
		640, 480,	// �E�B���h�E �T�C�Y
		NULL,		// �e�E�B���h�E
		NULL,		// ���j���[
		hInstance,	// �C���X�^���X �n���h��
		NULL);		// �ǉ��̃A�v���P�[�V���� �f�[�^
	if (hWnd == NULL) {
		MessageBox(NULL, L"�E�B���h�E�̍쐬�Ɏ��s���܂����B", L"�G���[", MB_OK);
		return -1;
	}

	// �E�B���h�E�̕\���w�����o�����߂ɃE�B���h�E �n���h�����w�肷��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, L"�E�B���h�E���\������܂������H", L"�m�F", MB_OK);

	return 0;
}
