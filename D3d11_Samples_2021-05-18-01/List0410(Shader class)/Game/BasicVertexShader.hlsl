cbuffer ConstantBuffer
{
	matrix World;         //���[���h�ϊ��s��
	matrix View;          //�r���[�ϊ��s��
	matrix Projection;    //�����ˉe�ϊ��s��
	matrix WorldViewProjection;	// WVP�s��
}

float4 main(float4 pos : POSITION) : SV_POSITION
{
	float4 output;
	//output = mul(pos, World);
	//output = mul(output, View);
	//output = mul(output, Projection);
	output = mul(pos, WorldViewProjection);
	return output;
}
