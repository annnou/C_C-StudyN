cbuffer ConstantBuffer
{
	matrix World;         //ワールド変換行列
	matrix View;          //ビュー変換行列
	matrix Projection;    //透視射影変換行列
	matrix WorldViewProjection;	// WVP行列
}

// 頂点シェーダーへの入力
struct VSInput
{
	float4 position : POSITION;
	float3 normal : NORMAL;
};

// 頂点シェーダーからの出力
struct VSOutput
{
	float4 position : SV_POSITION;
	float4 worldPosition : POSITION;
	float3 worldNormal : NORMAL;
};

// ジオメトリーシェーダーへの入力
typedef VSOutput GSInput;

// ジオメトリーシェーダーからの出力
struct GSOutput
{
	float4 position : SV_POSITION;
	float4 worldPosition : POSITION;
	float3 worldNormal : NORMAL;
};

// ピクセルシェーダーへの入力
typedef GSOutput PSInput;
