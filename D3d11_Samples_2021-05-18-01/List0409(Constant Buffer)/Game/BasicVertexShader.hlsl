cbuffer ConstantBuffer
{
	matrix World;         //���[���h�ϊ��s��
	matrix View;          //�r���[�ϊ��s��
	matrix Projection;    //�����ˉe�ϊ��s��
	matrix WorldViewProjection;	// WVP�s��
}

struct VSInput
{
	float4 position : POSITION;
	float3 normal : NORMAL;
};

struct VSOutput
{
	float4 position : SV_POSITION;
	float4 color : COLOR0;
};

VSOutput main(VSInput input)
{
	VSOutput output;
	output.position = mul(input.position, WorldViewProjection);
	output.color = float4(1.0f, 0.0f, 0.0f, 0.0f);
	return output;
}
