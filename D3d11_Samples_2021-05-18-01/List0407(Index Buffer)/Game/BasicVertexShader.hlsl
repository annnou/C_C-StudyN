// float4	データ型
// pos		変数名
// POSITION	セマンティック(データの意味、役割、使命)
float4 main(float4 pos : POSITION) : SV_POSITION
{
	float4 output;
	output = pos;
	//output.x += -0.5;
	return output;
}
// SV_POSITION
//		頂点シェーダーが計算結果として出力する位置座標
//		ジオメトリーシェーダーの入力となる
