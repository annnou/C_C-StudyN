#include "BasicShader.hlsli"

// ���C�g�̈ʒu���W(���s���� w = 0)
static const float4 lightPosition = float4(1.0f, 2.0f, -2.0f, 0.0f);
//// ���C�g�̈ʒu���W(�_���� w = 1)
//static const float4 lightPosition = float4(1.0f, 2.0f, -2.0f, 1.0f);
// �}�e���A���̕\�ʃJ���[
static const float4 diffuseColor = float4(1, 1, 0, 1);

VSOutput main(VSInput input)
{
	VSOutput output;
	// WVP�ϊ�
	output.position = mul(input.position, WorldViewProjection);

	// �ʂ���������w�����K���x�N�g��L(���s����)
	float3 light = normalize(lightPosition.xyz);
	// ���[���h��ԏ�̖@���x�N�g��N
	float3 worldNormal = normalize(mul(input.normal, (float3x3)World));
	// �����o�[�g����
	float diffuse = max(dot(light, worldNormal), 0);
	output.color = float4(diffuse * diffuseColor.xyz, diffuseColor.w);

	return output;
}
