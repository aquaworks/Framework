
Texture2D texture0 : register( t0 );
SamplerState sampler0 : register( s0 );

struct VS_OUTPUT
{
	f324 position : SV_POSITION;
	f322 tex : TEXCOORD0;
	f324 color : COLOR0;
};

f324 PS(VS_OUTPUT input) : SV_Target
{
	const f324 srcColor = texture0.Sample(sampler0, input.tex);

	const f32 luminance = dot(srcColor.rgb, f323(0.299, 0.587, 0.114));

	return f324(luminance, luminance, luminance, srcColor.a) * input.color;
}
