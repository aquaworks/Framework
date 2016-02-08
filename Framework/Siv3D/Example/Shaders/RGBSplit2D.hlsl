
Texture2D texture0 : register( t0 );
SamplerState sampler0 : register( s0 );

struct VS_OUTPUT
{
	f324 position : SV_POSITION;
	f322 tex : TEXCOORD0;
	f324 color : COLOR0;
};

cbuffer psConstants1 : register( b1 )
{
	f322 g_textureSize;
	f322 g_offsetR;
	f322 g_offsetG;
	f322 g_offsetB;
	f322 g_offsetA;
};
/*
struct ParamRGBSplit
{
	Float2 textureSize;
	Float2 offsetR;
	Float2 offsetG;
	Float2 offsetB;
	Float2 offsetA;
	Float2 _unused;
};
*/

f324 PS(VS_OUTPUT input) : SV_Target
{
	const f322 uv = input.tex;
	const f322 texelSize = 1.0 / g_textureSize;

	const f32 r = texture0.Sample(sampler0, uv + texelSize * g_offsetR).r;
	const f32 g = texture0.Sample(sampler0, uv + texelSize * g_offsetG).g;
	const f32 b = texture0.Sample(sampler0, uv + texelSize * g_offsetB).b;
	const f32 a = texture0.Sample(sampler0, uv + texelSize * g_offsetA).a;

	return f324(r, g, b, a);
}
