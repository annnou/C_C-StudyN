#include "BasicShader.hlsli"

float4 main(PSInput input) : SV_TARGET
{
	float4 worldPosition = input.worldPosition;
	// 面から光源を指す正規化ベクトルL(平行光源(w=0)と点光源(w=1))
	float3 light = normalize(LightPosition.xyz - LightPosition.w * worldPosition.xyz);

	// ワールド空間上の法線ベクトルN
	float3 worldNormal = input.worldNormal;
	// ランバート反射
	float diffuse = max(dot(light, worldNormal), 0);
	float4 diffuseColor = float4(diffuse * MaterialDiffuse.xyz, MaterialDiffuse.w);

	return diffuseColor;
}