cbuffer ConstantBuffer
{
	matrix World;         //[hĻ·sń
	matrix View;          //r[Ļ·sń
	matrix Projection;    //§ĖeĻ·sń
	matrix WorldViewProjection;	// WVPsń
}

struct VSInput
{
	float4 position : POSITION;
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
