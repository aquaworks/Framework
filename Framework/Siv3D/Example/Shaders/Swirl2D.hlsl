
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
	f32 g_strength;
	f32 g_angle;
};
/*
struct ParamSwirl
{
	f32 strength;
	f32 angle;
	Float2 _unused;
};
*/

f324 PS(VS_OUTPUT input) : SV_Target
{
	f322 uv = input.tex - 0.5;

	const f32 len = length(uv);

	const f32 rad = len * g_strength + g_angle;

	const f32 c = cos(rad), s = sin(rad);

	uv = mul(uv, f322x2(c, -s, s, c)) + 0.5;

	const f324 srcColor = texture0.Sample(sampler0, uv);

	return srcColor * input.color;
}
