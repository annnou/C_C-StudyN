//=============================================================================
// Game.cpp
// 
//=============================================================================
#include "Game.h"

// �E�B���h�E�̃n���h��
HWND hWnd = NULL;
// �E�B���h�E�̃^�C�g��
LPCWSTR WindowTitle = L"�^�C�g��";
// �E�B���h�E�̕�
int ScreenWidth = 640;
// �E�B���h�E�̍���
int ScreenHeight = 480;

// �֐��̃v���g�^�C�v�錾
bool InitWindow();
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// �A�v���P�[�V���������������܂��B
void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight)
{
	// �E�B���h�E�̃^�C�g��
	WindowTitle = windowTitle;
	// �E�B���h�E�̕�
	ScreenWidth = screenWidth;
	// �E�B���h�E�̍���
	ScreenHeight = screenHeight;
}

// �E�B���h�E���쐬���܂��B
bool InitWindow()
{
	HINSTANCE hInstance = GetModuleHandle(NULL);
	// �E�B���h�E �N���X��o�^����
	const wchar_t CLASS_NAME[] = L"GameWindow";
	WNDCLASSEX wndClass = {};
	wndClass.cbSize = sizeof(WNDCLASSEX);
	wndClass.lpfnWndProc = WindowProc;	// �E�B���h�E �v���V�[�W���[���w��
	wndClass.hInstance = hInstance;
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndClass.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
	wndClass.lpszClassName = CLASS_NAME;
	if (!RegisterClassEx(&wndClass)) {
		return false;
	}

	// �N���C�A���g�̈悪�w�肵���𑜓x�ɂȂ�E�B���h�E�T�C�Y���v�Z
	RECT rect = { 0, 0, ScreenWidth, ScreenHeight };
	AdjustWindowRectEx(&rect, WS_OVERLAPPEDWINDOW, FALSE, 0);

	// �E�B���h�E���쐬����
	hWnd = CreateWindowEx(0,
		CLASS_NAME,	// �E�B���h�E �N���X
		WindowTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),
		NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		return false;
	}

	// �E�B���h�E��\��
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	return true;
}

// �E�B���h�E ���b�Z�[�W����������v���V�[�W���[
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CLOSE:
		// �E�B���h�E�����
		if (MessageBox(hWnd, L"�E�B���h�E����܂����H", L"���b�Z�[�W", MB_OKCANCEL) == IDOK) {
			DestroyWindow(hWnd);
		}
		return 0;

	case WM_DESTROY:
		// �A�v���P�[�V�������I��
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

// ���b�Z�[�W���[�v�����s���܂��B
int Run()
{
	// �E�B���h�E���쐬
	if (!InitWindow()) {
		MessageBox(NULL, L"�E�B���h�E�̍쐬�Ɏ��s���܂����B", L"�G���[", MB_OK);
		return -1;
	}

	// ���b�Z�[�W���[�v�����s
	MSG msg = {};
	while (true) {
		// ���̃E�B���h�E�̃��b�Z�[�W�����݂��邩���m�F
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE)) {
			// ���b�Z�[�W���擾
			if (!GetMessage(&msg, NULL, 0, 0)) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}
