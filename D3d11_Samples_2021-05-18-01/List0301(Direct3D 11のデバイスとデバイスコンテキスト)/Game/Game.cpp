//=============================================================================
// Game.cpp
// 
//=============================================================================
#include <d3d11.h>
#include "Game.h"

// �֐��̃v���g�^�C�v�錾
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// �A�v���P�[�V���������������܂��B
void Game::Initialize(LPCWSTR windowTitle, int screenWidth, int screenHeight)
{
	// �E�B���h�E�̃^�C�g��
	WindowTitle = windowTitle;
	// �E�B���h�E�̕�
	ScreenWidth = screenWidth;
	// �E�B���h�E�̍���
	ScreenHeight = screenHeight;
}

// �E�B���h�E���쐬���܂��B
bool Game::InitWindow()
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
	auto hWnd = CreateWindowEx(
		0, CLASS_NAME, WindowTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		(rect.right - rect.left), (rect.bottom - rect.top),
		NULL, NULL, hInstance, NULL);
	if (hWnd == NULL) {
		return false;
	}

	// �E�B���h�E��\��
	ShowWindow(hWnd, SW_SHOWNORMAL);
	UpdateWindow(hWnd);

	this->hWnd = hWnd;

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
int Game::Run()
{
	// �E�B���h�E���쐬
	if (!InitWindow()) {
		MessageBox(NULL, L"�E�B���h�E�̍쐬�Ɏ��s���܂����B", L"���b�Z�[�W", MB_OK);
		return -1;
	}


	// Direct3D 11�̃f�o�C�X
	ID3D11Device* graphicsDevice = nullptr;
	// Direct3D 11�̃f�o�C�X �R���e�L�X�g
	ID3D11DeviceContext* immediateContext = nullptr;
	// Direct3D 11�̋@�\���x��
	D3D_FEATURE_LEVEL featureLevel = {};


	HRESULT hr;	// �֐��̎��s���ʂ��󂯎��ϐ�

	// �f�o�C�X�쐬���̃I�v�V�����t���O
	UINT creationFlags = 0;
#if defined(_DEBUG)
	// DEBUG�r���h�̍ۂ�Direct3D�̃f�o�b�O�\���@�\����������
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// �쐬����@�\���x���B��]���Ɏw�肷��
	const D3D_FEATURE_LEVEL featureLevels[] = {
		D3D_FEATURE_LEVEL_11_0,
		D3D_FEATURE_LEVEL_10_1,
		D3D_FEATURE_LEVEL_10_0,
		D3D_FEATURE_LEVEL_9_3,
		D3D_FEATURE_LEVEL_9_2,
		D3D_FEATURE_LEVEL_9_1,
	};

	// �f�o�C�X�A�f�o�C�X�R���e�L�X�g���쐬
	hr = D3D11CreateDevice(
		NULL,						// �r�f�I�A�_�v�^�[�BNULL���w�肷��ƃf�t�H���g�A�_�v�^�[
		D3D_DRIVER_TYPE_HARDWARE,	// �쐬����h���C�o�[�̎��
		0,							// �\�t�g�E�F�A���X�^���C�U�[����������DLL�̃n���h��
		creationFlags,				// �f�o�C�X�쐬���̃I�v�V�����t���O
		featureLevels,				// �쐬����@�\���x���BNULL���w�肵�ďȗ��ł���
		6,							// featureLevels�z��̐�
		D3D11_SDK_VERSION,			// ���ł�D3D11_SDK_VERSION
		&graphicsDevice,			// [�o��]Direct3D 11 �f�o�C�X
		&featureLevel,				// ���ۂɍ쐬���ꂽ�@�\���x��
		&immediateContext);			// [�o��]Direct3D 11 �f�o�C�X �R���e�L�X�g
	if (FAILED(hr)) {
		MessageBox(hWnd, L"Direct3D 11�f�o�C�X���쐬�ł��܂���ł����B", L"�G���[", MB_OK);
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


	// ���\�[�X�����
	/*
	if (immediateContext != nullptr) {
		immediateContext->Release();
		immediateContext = nullptr;
	}
	if (graphicsDevice != nullptr) {
		graphicsDevice->Release();
		graphicsDevice = nullptr;
	}
	*/
	SAFE_RELEASE(immediateContext);
	SAFE_RELEASE(graphicsDevice);

	return (int)msg.wParam;
}
