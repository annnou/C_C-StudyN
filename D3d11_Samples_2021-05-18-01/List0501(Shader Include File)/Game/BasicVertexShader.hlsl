#include "BasicShader.hlsli"

VSOutput main(VSInput input)
{
	VSOutput output;
	output.position = mul(input.position, WorldViewProjection);
	output.color = float4(1.0f, 0.0f, 0.0f, 0.0f);
	return output;
}
