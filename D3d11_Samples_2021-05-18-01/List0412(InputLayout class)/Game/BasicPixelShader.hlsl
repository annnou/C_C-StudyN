struct GSOutput
{
	float4 position : SV_POSITION;
	float4 color : COLOR0;
};

float4 main(GSOutput input) : SV_TARGET
{
	return input.color;
	//return float4(1.0f, 1.0f, 1.0f, 1.0f);
}