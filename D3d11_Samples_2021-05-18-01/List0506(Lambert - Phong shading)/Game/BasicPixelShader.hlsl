#include "BasicShader.hlsli"

// ライトの位置座標(平行光源 w = 0, 点光源 w = 1)
static const float4 lightPosition = float4(1.0f, 2.0f, -2.0f, 1.0f);
// マテリアルの表面カラー
static const float4 materialDiffuse = float4(1, 1, 0, 1);

float4 main(PSInput input) : SV_TARGET
{
	float4 worldPosition = input.worldPosition;
	// 面から光源を指す正規化ベクトルL(平行光源(w=0)と点光源(w=1))
	float3 light = normalize(lightPosition.xyz - lightPosition.w * worldPosition.xyz);

	// ワールド空間上の法線ベクトルN
	float3 worldNormal = input.worldNormal;
	// ランバート反射
	float diffuse = max(dot(light, worldNormal), 0);
	float4 diffuseColor = float4(diffuse * materialDiffuse.xyz, materialDiffuse.w);

	return diffuseColor;
}