//=============================================================================
// Buffers.cpp
// 
//=============================================================================
#include "Game.h"

// ���̃N���X�̐V�����C���X�^���X���쐬���܂��B
VertexBuffer* VertexBuffer::Create(
	ID3D11Device* graphicsDevice, UINT byteWidth)
{
	// ���̃N���X�̃������[���m��
	auto result = new VertexBuffer();
	if (result == nullptr) {
		OutputDebugString(L"�������[���m�ۂł��܂���ł����B");
		return nullptr;
	}

	// �쐬����o�b�t�@�[�ɂ��Ă̋L�q
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.ByteWidth = byteWidth;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;
	graphicsDevice->CreateBuffer(&bufferDesc, nullptr, &result->buffer);

	return result;
}

// ���\�[�X��������܂��B
void VertexBuffer::Release()
{
	SAFE_RELEASE(buffer);
	delete this;
}

// D3D11�̃l�C�e�B�u�|�C���^�[���擾���܂��B
ID3D11Buffer* VertexBuffer::GetNativePointer()
{
	return buffer;
}

// �o�b�t�@�[�Ƀf�[�^��ݒ肵�܂��B
void VertexBuffer::SetData(void* data)
{
	// ID3D11Device���擾
	ID3D11Device* graphicsDevice = nullptr;
	buffer->GetDevice(&graphicsDevice);
	// ID3D11DeviceContext���擾
	ID3D11DeviceContext* immediateContext = nullptr;
	graphicsDevice->GetImmediateContext(&immediateContext);

	// �o�b�t�@�[��data��]��(�R�s�[)����
	immediateContext->UpdateSubresource(
		buffer, 0, NULL, data, 0, 0);

	// �擾�����C���^�[�t�F�C�X�����
	SAFE_RELEASE(immediateContext);
	SAFE_RELEASE(graphicsDevice);
}

// ���̃N���X�̐V�����C���X�^���X���쐬���܂��B
IndexBuffer* IndexBuffer::Create(
	ID3D11Device* graphicsDevice, UINT indexCount)
{
	// ���̃N���X�̃������[���m��
	auto result = new IndexBuffer();
	if (result == nullptr) {
		OutputDebugString(L"�������[���m�ۂł��܂���ł����B");
		return nullptr;
	}

	// �쐬����o�b�t�@�[�ɂ��Ă̋L�q
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.ByteWidth = indexCount * sizeof(UINT32);
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;
	graphicsDevice->CreateBuffer(&bufferDesc, nullptr, &result->buffer);

	return result;
}

// ���\�[�X��������܂��B
void IndexBuffer::Release()
{
	SAFE_RELEASE(buffer);
	delete this;
}

// D3D11�̃l�C�e�B�u�|�C���^�[���擾���܂��B
ID3D11Buffer* IndexBuffer::GetNativePointer()
{
	return buffer;
}

// �o�b�t�@�[�Ƀf�[�^��ݒ肵�܂��B
void IndexBuffer::SetData(UINT32* data)
{
	// ID3D11Device���擾
	ID3D11Device* graphicsDevice = nullptr;
	buffer->GetDevice(&graphicsDevice);
	// ID3D11DeviceContext���擾
	ID3D11DeviceContext* immediateContext = nullptr;
	graphicsDevice->GetImmediateContext(&immediateContext);

	// �o�b�t�@�[��data��]��(�R�s�[)����
	immediateContext->UpdateSubresource(
		buffer, 0, NULL, data, 0, 0);

	// �擾�����C���^�[�t�F�C�X�����
	SAFE_RELEASE(immediateContext);
	SAFE_RELEASE(graphicsDevice);
}

// ���̃N���X�̐V�����C���X�^���X���쐬���܂��B
ConstantBuffer* ConstantBuffer::Create(
	ID3D11Device* graphicsDevice, UINT byteWidth)
{
	// ���̃N���X�̃������[���m��
	auto result = new ConstantBuffer();
	if (result == nullptr) {
		OutputDebugString(L"�������[���m�ۂł��܂���ł����B");
		return nullptr;
	}

	// �쐬����o�b�t�@�[�ɂ��Ă̋L�q
	D3D11_BUFFER_DESC bufferDesc = {};
	bufferDesc.ByteWidth = byteWidth;
	bufferDesc.Usage = D3D11_USAGE_DEFAULT;
	bufferDesc.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = 0;
	graphicsDevice->CreateBuffer(&bufferDesc, nullptr, &result->buffer);

	return result;
}

// ���\�[�X��������܂��B
void ConstantBuffer::Release()
{
	SAFE_RELEASE(buffer);
	delete this;
}

// D3D11�̃l�C�e�B�u�|�C���^�[���擾���܂��B
ID3D11Buffer* ConstantBuffer::GetNativePointer()
{
	return buffer;
}

// �o�b�t�@�[�Ƀf�[�^��ݒ肵�܂��B
void ConstantBuffer::SetData(void* data)
{
	// ID3D11Device���擾
	ID3D11Device* graphicsDevice = nullptr;
	buffer->GetDevice(&graphicsDevice);
	// ID3D11DeviceContext���擾
	ID3D11DeviceContext* immediateContext = nullptr;
	graphicsDevice->GetImmediateContext(&immediateContext);

	// �o�b�t�@�[��data��]��(�R�s�[)����
	immediateContext->UpdateSubresource(
		buffer, 0, NULL, data, 0, 0);

	// �擾�����C���^�[�t�F�C�X�����
	SAFE_RELEASE(immediateContext);
	SAFE_RELEASE(graphicsDevice);
}
