

#include "Game.h"

//���ケ�ꂪ�|�C���^�ɂ�������Ă���̂ł��̎��_��
//���̏����������������炵���͈̂Ӑ}������
HWND hWnd = NULL;
LPCWSTR WindowTitle = L"TITLE VIEW";
int ScreenWidth = 640;
int ScreenHeight = 480;

//�֐��v���g�^�C�v�錾
bool InitWindow();
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM Param);

void Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight)
{
	WindowTitle = windowTitle;
	ScreenWidth = screenWidth;
	ScreenHeight = screenHeight;
}

//window create
//success return true
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
		OutputDebugString(L"�E�B���h�E �N���X�̓o�^�Ɏ��s���܂����B");
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
		OutputDebugString(L"�E�B���h�E�̍쐬�Ɏ��s���܂����B");
		return false;
	}

	// �E�B���h�E��\��
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);


	return true;
}

// �E�B���h�E�E���b�Z�[�W����������v���V�[�W���[
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_CLOSE:
		// �E�B���h�E�����
		if (MessageBox(hWnd, L"�E�B���h�E����܂����H", L"���", MB_OKCANCEL) == IDOK) {
			DestroyWindow(hWnd);
		}
		return 0;

	case WM_DESTROY:
		// �A�v���P�[�V�������I��
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		// �Q�l�FWindows API�ɂ��}�`�`��
		PAINTSTRUCT ps;
		auto hdc = BeginPaint(hWnd, &ps);
		RECT rect = {};
		rect.left = 200;
		rect.top = 100;
		rect.right = 300;
		rect.bottom = 200;
		FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hWnd, &ps);
	}
	break;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

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

		//������3D�v���O���~���O�̃t���[���X�V����
		//3D GAME �쐬�Ȃ炱���撣�肽��

	}

	return (int)msg.wParam;
}