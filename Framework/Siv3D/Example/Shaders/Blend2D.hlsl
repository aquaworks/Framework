
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
	f323 g_color;
	f32 g_blend;
};
/*
struct ParamDraw
{
	Float3 color;
	f32 blend;
};
*/

f324 PS(VS_OUTPUT input) : SV_Target
{
	const f324 srcColor = texture0.Sample(sampler0, input.tex) * input.color;

	return f324(lerp(srcColor.rgb, g_color, g_blend), srcColor.a);
}
