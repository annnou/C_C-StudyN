//=============================================================================
// InputLayout.cpp
// 
//=============================================================================
#include "Game.h"

// ���̃N���X�̐V�����C���X�^���X���쐬���܂��B
InputLayout* InputLayout::Create(
	ID3D11Device* graphicsDevice,
	const D3D11_INPUT_ELEMENT_DESC* inputElementDescs, UINT numElements,
	const void* shaderBytecodeWithInputSignature, SIZE_T bytecodeLength)
{
	// ���̃N���X�̃������[���m��
	auto result = new InputLayout();
	if (result == nullptr) {
		OutputDebugString(L"�������[���m�ۂł��܂���ł����B");
		return nullptr;
	}

	// ���̓��C�A�E�g���쐬
	auto hr = graphicsDevice->CreateInputLayout(
		inputElementDescs, numElements,
		shaderBytecodeWithInputSignature, bytecodeLength,
		&result->inputLayout);
	if (FAILED(hr)) {
		OutputDebugString(L"���̓��C�A�E�g���쐬�ł��܂���ł����B");
		return nullptr;
	}

	return result;
}

// ���\�[�X��������܂��B
void InputLayout::Release()
{
	SAFE_RELEASE(inputLayout);
	delete this;
}

// D3D11�̃l�C�e�B�u�|�C���^�[���擾���܂��B
ID3D11InputLayout* InputLayout::GetNativePointer()
{
	return inputLayout;
}
