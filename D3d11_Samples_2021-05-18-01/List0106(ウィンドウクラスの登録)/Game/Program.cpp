//=============================================================================
// Program.cpp
// �G���g���[�|�C���g
//=============================================================================
#include <Windows.h>

// �E�B���h�E�̃n���h��
HWND hWnd = NULL;

// �A�v���P�[�V�����̃G���g���[�|�C���g
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
	// �E�B���h�E �N���X��o�^����
	const wchar_t CLASS_NAME[] = L"GameWindow";

	WNDCLASSEX wndClass = {};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = DefWindowProc;	// �V�X�e������̃��b�Z�[�W����
	wndClass.hInstance = hInstance;
	wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND + 5;
	wndClass.lpszClassName = CLASS_NAME;

	if (!RegisterClassEx(&wndClass)) {
		MessageBox(NULL, L"�E�B���h�E �N���X�̓o�^�Ɏ��s���܂����B", L"�G���[", MB_OK);
		return -1;
	}

	// �N���C�A���g�̈悪�w�肵���𑜓x�ɂȂ�E�B���h�E�T�C�Y���v�Z
	RECT rect = { 0, 0, 640, 480 };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, FALSE, 0);

	// �E�B���h�E���쐬����
	hWnd = CreateWindowEx(0,
		CLASS_NAME,	// �E�B���h�E �N���X
		L"�^�C�g��",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),
		NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		MessageBox(NULL, L"�E�B���h�E�̍쐬�Ɏ��s���܂����B", L"�G���[", MB_OK);
		return -1;
	}

	// �E�B���h�E��\��
	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	MessageBox(hWnd, L"�E�B���h�E���\������܂������H", L"�m�F", MB_OK);

	return 0;
}
