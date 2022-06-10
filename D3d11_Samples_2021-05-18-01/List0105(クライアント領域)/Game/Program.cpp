//=============================================================================
// Program.cpp
// �G���g���[�|�C���g
//=============================================================================
#include <Windows.h>

// �A�v���P�[�V�����̃G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// �E�B���h�E �n���h��
	HWND hWnd = NULL;

	// �N���C�A���g�̈悪�w�肵���𑜓x�ɂȂ�E�B���h�E�T�C�Y���v�Z
	RECT rect = { 0, 0, 640, 480 };
	AdjustWindowRectEx(
		&rect,
		WS_OVERLAPPEDWINDOW,	// �E�B���h�E �X�^�C��
		FALSE,
		0);	// �I�v�V�����̃E�B���h�E �X�^�C��

	// �E�B���h�E���쐬����
	hWnd = CreateWindowEx(
		0,	// �I�v�V�����̃E�B���h�E �X�^�C��
		L"Static",
		L"�^�C�g��",
		WS_OVERLAPPEDWINDOW,	// �E�B���h�E �X�^�C��
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),	// �E�B���h�E �T�C�Y
		NULL,
		NULL,	// ���j���[
		hInstance, NULL);
	if (hWnd == NULL) {
		MessageBox(NULL, L"�E�B���h�E�̍쐬�Ɏ��s���܂����B", L"�G���[", MB_OK);
		return false;
	}

	// �E�B���h�E�̕\���w�����o�����߂ɃE�B���h�E �n���h�����w�肷��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, L"�E�B���h�E���\������܂������H", L"�m�F", MB_OK);

	return 0;
}
