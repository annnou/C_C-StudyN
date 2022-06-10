cbuffer ConstantBuffer
{
	matrix World;         //ワールド変換行列
	matrix View;          //ビュー変換行列
	matrix Projection;    //透視射影変換行列
	matrix WorldViewProjection;	// WVP行列
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
