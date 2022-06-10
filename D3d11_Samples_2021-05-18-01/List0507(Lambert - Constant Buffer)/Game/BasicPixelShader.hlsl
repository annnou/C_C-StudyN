#include "BasicShader.hlsli"

float4 main(PSInput input) : SV_TARGET
{
	float4 worldPosition = input.worldPosition;
	// �ʂ���������w�����K���x�N�g��L(���s����(w=0)�Ɠ_����(w=1))
	float3 light = normalize(LightPosition.xyz - LightPosition.w * worldPosition.xyz);

	// ���[���h��ԏ�̖@���x�N�g��N
	float3 worldNormal = input.worldNormal;
	// �����o�[�g����
	float diffuse = max(dot(light, worldNormal), 0);
	float4 diffuseColor = float4(diffuse * MaterialDiffuse.xyz, MaterialDiffuse.w);

	return diffuseColor;
}