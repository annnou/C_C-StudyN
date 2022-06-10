#include "BasicShader.hlsli"

// ���C�g�̈ʒu���W(���s���� w = 0, �_���� w = 1)
static const float4 lightPosition = float4(1.0f, 2.0f, -2.0f, 1.0f);
// �}�e���A���̕\�ʃJ���[
static const float4 materialDiffuse = float4(1, 1, 0, 1);

float4 main(PSInput input) : SV_TARGET
{
	float4 worldPosition = input.worldPosition;
	// �ʂ���������w�����K���x�N�g��L(���s����(w=0)�Ɠ_����(w=1))
	float3 light = normalize(lightPosition.xyz - lightPosition.w * worldPosition.xyz);

	// ���[���h��ԏ�̖@���x�N�g��N
	float3 worldNormal = input.worldNormal;
	// �����o�[�g����
	float diffuse = max(dot(light, worldNormal), 0);
	float4 diffuseColor = float4(diffuse * materialDiffuse.xyz, materialDiffuse.w);

	return diffuseColor;
}