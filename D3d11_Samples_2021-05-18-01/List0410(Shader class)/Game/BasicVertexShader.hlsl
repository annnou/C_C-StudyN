cbuffer ConstantBuffer
{
	matrix World;         //[hĻ·sń
	matrix View;          //r[Ļ·sń
	matrix Projection;    //§ĖeĻ·sń
	matrix WorldViewProjection;	// WVPsń
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
