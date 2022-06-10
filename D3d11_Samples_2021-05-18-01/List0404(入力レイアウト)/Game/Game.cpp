//=============================================================================
// Game.cpp
// 
//=============================================================================
#include <d3dcompiler.h>	// �V�F�[�_�[�R���p�C���[
#include <DirectXMath.h>
#include <DirectXColors.h>
#include "Game.h"

using namespace DirectX;

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

// �O���t�B�b�N�f�o�C�X���쐬���܂��B
bool Game::InitGraphicsDevice()
{
	HRESULT hr = S_OK;

	// �f�o�C�X�쐬���̃I�v�V�����t���O
	UINT creationFlags = 0;
#if defined(_DEBUG)
	// DEBUG�r���h�̍ۂ�Direct3D�̃f�o�b�O�\���@�\����������
	creationFlags |= D3D11_CREATE_DEVICE_DEBUG;
#endif

	// �쐬����X���b�v�`�F�[���ɂ��Ă̋L�q
	DXGI_SWAP_CHAIN_DESC swapChainDesc = {};
	swapChainDesc.BufferDesc.Width = ScreenWidth;
	swapChainDesc.BufferDesc.Height = ScreenHeight;
	swapChainDesc.BufferDesc.RefreshRate = { 60, 1 };
	swapChainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swapChainDesc.SampleDesc = { 1, 0 };
	swapChainDesc.BufferUsage =
		DXGI_USAGE_RENDER_TARGET_OUTPUT |
		DXGI_USAGE_SHADER_INPUT;	// �V�F�[�_�[���\�[�X�Ƃ��Ďg�p���邱�Ƃ�ݒ�
	swapChainDesc.BufferCount = 2;
	swapChainDesc.OutputWindow = hWnd;
	swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
	swapChainDesc.Windowed = TRUE;

	// �f�o�C�X�A�f�o�C�X�R���e�L�X�g�A�X���b�v�`�F�[�����쐬
	hr = D3D11CreateDeviceAndSwapChain(
		NULL, D3D_DRIVER_TYPE_HARDWARE, 0, creationFlags, NULL, 0, D3D11_SDK_VERSION, &swapChainDesc,
		&swapChain, &graphicsDevice, &featureLevel, &immediateContext);
	if (FAILED(hr)) {
		return false;
	}

	// �o�b�N�o�b�t�@�[���擾
	ID3D11Texture2D* backBuffer = nullptr;
	hr = swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
	if (FAILED(hr)) {
		return false;
	}
	// �o�b�N�o�b�t�@�[�ɃA�N�Z�X���邽�߂̃����_�[�^�[�Q�b�g �r���[���쐬
	hr = graphicsDevice->CreateRenderTargetView(backBuffer, NULL, &renderTargetViews[0]);
	if (FAILED(hr)) {
		return false;
	}
	// �o�b�N�o�b�t�@�[�ɃV�F�[�_�[����A�N�Z�X���邽�߂̃��\�[�X �r���[���쐬
	hr = graphicsDevice->CreateShaderResourceView(
		backBuffer,
		NULL,
		&renderTargetResourceView);
	if (FAILED(hr)) {
		return false;
	}
	SAFE_RELEASE(backBuffer);

	// �e�N�X�`���ƃV�F�[�_�[���\�[�X�r���[�̃t�H�[�}�b�g��ݒ�
	DXGI_FORMAT textureFormat = depthStencilFormat;
	DXGI_FORMAT resourceFormat = depthStencilFormat;
	switch (depthStencilFormat)
	{
	case DXGI_FORMAT_D16_UNORM:
		textureFormat = DXGI_FORMAT_R16_TYPELESS;
		resourceFormat = DXGI_FORMAT_R16_UNORM;
		break;
	case DXGI_FORMAT_D24_UNORM_S8_UINT:
		textureFormat = DXGI_FORMAT_R24G8_TYPELESS;
		resourceFormat = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
		break;
	case DXGI_FORMAT_D32_FLOAT:
		textureFormat = DXGI_FORMAT_R32_TYPELESS;
		resourceFormat = DXGI_FORMAT_R32_FLOAT;
		break;
	case DXGI_FORMAT_D32_FLOAT_S8X24_UINT:
		textureFormat = DXGI_FORMAT_R32G8X24_TYPELESS;
		resourceFormat = DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS;
		break;
	}
	// �[�x�X�e���V�����쐬
	ID3D11Texture2D* depthStencil = nullptr;
	D3D11_TEXTURE2D_DESC depthStencilDesc = {};
	depthStencilDesc.Width = swapChainDesc.BufferDesc.Width;
	depthStencilDesc.Height = swapChainDesc.BufferDesc.Height;
	depthStencilDesc.MipLevels = 1;
	depthStencilDesc.ArraySize = 1;
	depthStencilDesc.Format = textureFormat;
	depthStencilDesc.SampleDesc = swapChainDesc.SampleDesc;
	depthStencilDesc.Usage = D3D11_USAGE_DEFAULT;
	depthStencilDesc.BindFlags =
		D3D11_BIND_DEPTH_STENCIL |
		D3D11_BIND_SHADER_RESOURCE;	// �V�F�[�_�[���\�[�X�Ƃ��Ďg�p���邱�Ƃ�ݒ�
	depthStencilDesc.CPUAccessFlags = 0;
	depthStencilDesc.MiscFlags = 0;
	hr = graphicsDevice->CreateTexture2D(&depthStencilDesc, NULL, &depthStencil);
	if (FAILED(hr)) {
		return false;
	}
	// �[�x�X�e���V���ɃA�N�Z�X���邽�߂̃r���[���쐬
	D3D11_DEPTH_STENCIL_VIEW_DESC depthStencilViewDesc = {};
	depthStencilViewDesc.Format = depthStencilFormat;
	if (depthStencilDesc.SampleDesc.Count > 0) {
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
	}
	else {
		depthStencilViewDesc.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
		depthStencilViewDesc.Texture2D.MipSlice = 0;
	}
	depthStencilViewDesc.Texture2D.MipSlice = 0;
	hr = graphicsDevice->CreateDepthStencilView(depthStencil, &depthStencilViewDesc, &depthStencilView);
	if (FAILED(hr)) {
		return false;
	}
	// �[�x�X�e���V���ɃV�F�[�_�[����A�N�Z�X���邽�߂̃��\�[�X �r���[���쐬
	D3D11_SHADER_RESOURCE_VIEW_DESC depthStencilResourceViewDesc = {};
	depthStencilResourceViewDesc.Format = resourceFormat;
	if (depthStencilDesc.SampleDesc.Count > 0) {
		depthStencilResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2DMS;
	}
	else {
		depthStencilResourceViewDesc.ViewDimension = D3D11_SRV_DIMENSION_TEXTURE2D;
		depthStencilResourceViewDesc.Texture2D.MostDetailedMip = 0;
		depthStencilResourceViewDesc.Texture2D.MipLevels = 1;
	}
	hr = graphicsDevice->CreateShaderResourceView(
		depthStencil,
		&depthStencilResourceViewDesc,
		&depthStencilResourceView);
	if (FAILED(hr)) {
		return false;
	}
	SAFE_RELEASE(depthStencil);

	// �r���[�|�[�g
	viewports[0].Width = static_cast<FLOAT>(ScreenWidth);
	viewports[0].Height = static_cast<FLOAT>(ScreenHeight);
	viewports[0].MinDepth = 0.0f;
	viewports[0].MaxDepth = 1.0f;
	viewports[0].TopLeftX = 0.0f;
	viewports[0].TopLeftY = 0.0f;

	return true;
}

// �O���t�B�b�N���\�[�X��������܂��B
void Game::ReleaseGraphicsDevice()
{
	SAFE_RELEASE(depthStencilResourceView);
	SAFE_RELEASE(depthStencilView);
	SAFE_RELEASE(renderTargetResourceView);
	SAFE_RELEASE(renderTargetViews[0]);
	SAFE_RELEASE(swapChain);
	SAFE_RELEASE(immediateContext);
	SAFE_RELEASE(graphicsDevice);
}

// ���b�Z�[�W���[�v�����s���܂��B
int Game::Run()
{
	// �E�B���h�E���쐬
	if (!InitWindow()) {
		MessageBox(NULL, L"�E�B���h�E���������ł��܂���ł����B", L"���b�Z�[�W", MB_OK);
		return -1;
	}
	// �O���t�B�b�N�f�o�C�X���쐬
	if (!InitGraphicsDevice()) {
		MessageBox(NULL, L"�O���t�B�b�N�f�o�C�X���������ł��܂���ł����B", L"���b�Z�[�W", MB_OK);
		return -1;
	}

	HRESULT hr = S_OK;

	// ��̒��_�Ɋ܂܂��f�[�^�̌^
	struct VertexPosition
	{
		DirectX::XMFLOAT3 position;	// �ʒu���W
	};
	// ���_�f�[�^�̔z��
	VertexPosition vertices[] = {
		{ { -1.0f, 0.0f, 0.0f }, },
		{ {  0.0f, 1.0f, 0.0f }, },
		{ {  1.0f, 0.0f, 0.0f }, },
	};

	// �쐬���钸�_�o�b�t�@�[�ɂ��Ă̋L�q
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.ByteWidth = sizeof vertices;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;
	// ���_�o�b�t�@�[���쐬
	ID3D11Buffer* vertexBuffer = nullptr;
	hr = graphicsDevice->CreateBuffer(&bufferDesc, NULL, &vertexBuffer);
	if (FAILED(hr) || vertexBuffer == nullptr) {
		OutputDebugString(L"���_�o�b�t�@�[���쐬�ł��܂���ł����B");
		return -1;
	}
	// �o�b�t�@�[�Ƀf�[�^��]��
	immediateContext->UpdateSubresource(vertexBuffer, 0, NULL, vertices, 0, 0);

	ID3DBlob* bytecode = nullptr;		// �R���p�C�����ꂽ�V�F�[�_�[�̃o�C�g�R�[�h
	ID3DBlob* errorMessage = nullptr;	// �G���[���b�Z�[�W
	// ���_�V�F�[�_�[���R���p�C��
	hr = D3DCompileFromFile(
		L"BasicVertexShader.hlsl",	// HLSL�V�F�[�_�[�t�@�C����
		NULL,
		D3D_COMPILE_STANDARD_FILE_INCLUDE,
		"main",						// �G���g���[�|�C���g
		"vs_5_0",					// �R���p�C������V�F�[�_�[�̃^�[�Q�b�g
		D3DCOMPILE_DEBUG, 0,
		&bytecode, &errorMessage);
	if (FAILED(hr) && errorMessage != nullptr) {
		LPCSTR message = nullptr;
		message = static_cast<LPCSTR>(errorMessage->GetBufferPointer());
		OutputDebugStringA(message);
	}
	SAFE_RELEASE(errorMessage);

	// ���_�V�F�[�_�[�̍쐬
	ID3D11VertexShader* vertexShader = nullptr;
	hr = graphicsDevice->CreateVertexShader(
		bytecode->GetBufferPointer(),
		bytecode->GetBufferSize(),
		NULL,
		&vertexShader);
	if (FAILED(hr)) {
		OutputDebugString(L"���_�V�F�[�_�[���쐬�ł��܂���ł����B");
	}

	/*
	// ���_�o�b�t�@�[�̓��͗v�f�ɂ��Ă̋L�q
	D3D11_INPUT_ELEMENT_DESC inputElementDesc = {};
	inputElementDesc.SemanticName = "POSITION";
	inputElementDesc.SemanticIndex = 0;
	inputElementDesc.Format = DXGI_FORMAT_R32G32B32_FLOAT;
	inputElementDesc.InputSlot = 0;
	inputElementDesc.AlignedByteOffset = 0;
	inputElementDesc.InputSlotClass = D3D11_INPUT_PER_VERTEX_DATA;
	inputElementDesc.InstanceDataStepRate = 0;
	*/

	//struct VertexPosition
	//{
	//	DirectX::XMFLOAT3 position;	// �ʒu���W
	//};
	D3D11_INPUT_ELEMENT_DESC inputElementDescs[] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	// ���̓��C�A�E�g���쐬
	ID3D11InputLayout* inputLayout = nullptr;
	hr = graphicsDevice->CreateInputLayout(
		inputElementDescs,				// ���͗v�f�ɂ��Ă̋L�q
		ARRAYSIZE(inputElementDescs),	// inputElementDescs�z��̐�
		bytecode->GetBufferPointer(),	// ���͂��󂯎�钸�_�V�F�[�_�[�̃o�C�g�R�[�h
		bytecode->GetBufferSize(),		// �o�C�g�R�[�h�̃T�C�Y
		&inputLayout);
	if (FAILED(hr)) {
		OutputDebugString(L"���̓��C�A�E�g���쐬�ł��܂���ł����B");
	}

	// ID3D11VertexShader��ID3D11InputLayout���쐬������o�C�g�R�[�h�͍폜���Ă��ǂ�
	SAFE_RELEASE(bytecode);


	// ���b�Z�[�W���[�v�����s
	MSG msg = {};
	while (true) {
		// �����_�[�^�[�Q�b�g��ݒ�
		immediateContext->OMSetRenderTargets(1, renderTargetViews, depthStencilView);
		// ��ʂ��N���A�[
		immediateContext->ClearRenderTargetView(renderTargetViews[0], clearColor);
		immediateContext->ClearDepthStencilView(depthStencilView,
			D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
		// �r���[�|�[�g��ݒ�
		immediateContext->RSSetViewports(1, viewports);

		// ���_�o�b�t�@�[��ݒ�
		ID3D11Buffer* vertexBuffers[1] = { vertexBuffer };
		UINT strides[1] = { sizeof(VertexPosition) };
		UINT offsets[1] = { 0 };
		immediateContext->IASetVertexBuffers(
			0,
			ARRAYSIZE(vertexBuffers),
			vertexBuffers, strides, offsets);
		// ���_�V�F�[�_�[��ݒ�
		immediateContext->VSSetShader(vertexShader, NULL, 0);


		// ���_�o�b�t�@�[�ƒ��_�V�F�[�_�[�̑g�����ɑΉ��������̓��C�A�E�g��ݒ�
		immediateContext->IASetInputLayout(inputLayout);


		// �o�b�N�o�b�t�@�[�ɕ`�悵���C���[�W���f�B�X�v���C�ɕ\��
		HRESULT hr = S_OK;
		hr = swapChain->Present(1, 0);
		if (FAILED(hr))
		{
			MessageBox(hWnd,
				L"�O���t�B�b�N�f�o�C�X�������I�Ɏ��O���ꂽ���A�h���C�o�[���A�b�v�f�[�g����܂����B",
				L"�G���[", MB_OK);
			return -1;
		}

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


	SAFE_RELEASE(vertexBuffer);
	SAFE_RELEASE(vertexShader);
	SAFE_RELEASE(inputLayout);

	ReleaseGraphicsDevice();

	return (int)msg.wParam;
}
