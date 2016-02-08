
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
	f324 srcColor = texture0.Sample(sampler0, input.tex);

	srcColor.rgb = f323(1.0, 1.0, 1.0) - srcColor.rgb;

	return srcColor * input.color;
}
