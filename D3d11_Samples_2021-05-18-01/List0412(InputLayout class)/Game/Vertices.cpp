//=============================================================================
// Vertices.cpp
// 
//=============================================================================
#include "Game.h"

namespace {
	const D3D11_INPUT_ELEMENT_DESC VertexPosition_InputElementDescs[1] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
	const D3D11_INPUT_ELEMENT_DESC VertexPositionNormal_InputElementDescs[2] = {
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,                            0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "NORMAL",   0, DXGI_FORMAT_R32G32B32_FLOAT, 0, D3D11_APPEND_ALIGNED_ELEMENT, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};
}

// この頂点情報をD3D11_INPUT_ELEMENT_DESCで表した配列を取得します。
const D3D11_INPUT_ELEMENT_DESC* VertexPosition::GetInputElementDescs()
{
	return VertexPosition_InputElementDescs;
}

// GetInputElementDescs()関数で取得される配列の要素数を取得します。
UINT VertexPosition::GetInputElementDescsLength()
{
	return ARRAYSIZE(VertexPosition_InputElementDescs);
}

// この頂点情報をD3D11_INPUT_ELEMENT_DESCで表した配列を取得します。
const D3D11_INPUT_ELEMENT_DESC* VertexPositionNormal::GetInputElementDescs()
{
	return VertexPositionNormal_InputElementDescs;
}

// GetInputElementDescs()関数で取得される配列の要素数を取得します。
UINT VertexPositionNormal::GetInputElementDescsLength()
{
	return ARRAYSIZE(VertexPositionNormal_InputElementDescs);
}
