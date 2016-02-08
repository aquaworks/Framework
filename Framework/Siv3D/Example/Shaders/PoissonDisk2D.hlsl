
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
	f32 g_radius;
};
/*
struct ParamPoissonDisk
{
	Float2 textureSize;
	f32 radius;
	f32 _unused;
};
*/

static const f322 poisson[12] =
{
       f322(-0.326212, -0.40581),
       f322(-0.840144, -0.07358),
       f322(-0.695914, 0.457137),
       f322(-0.203345, 0.620716),
       f322(0.96234, -0.194983),
       f322(0.473434, -0.480026),
       f322(0.519456, 0.767022),
       f322(0.185461, -0.893124),
       f322(0.507431, 0.064425),
       f322(0.89642, 0.412458),
       f322(-0.32194, -0.932615),
       f322(-0.791559, -0.59771)
};

f324 PS(VS_OUTPUT input) : SV_Target
{
	const f322 uv = input.tex;

	const f322 texelSize = 1.0 / g_textureSize;

	f324 cSampleAccum = texture0.Sample(sampler0, uv);

	for(uint tap = 0; tap < 12; ++tap)
	{
		const f322 coord = uv.xy + texelSize * poisson[tap] * g_radius;

		cSampleAccum += texture0.Sample(sampler0,coord);
	}

	return cSampleAccum / 13.0;
}
