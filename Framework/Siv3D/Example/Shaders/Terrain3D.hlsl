
struct VS_INPUT
{
	f324 pos : POSITION;
	f323 normal : NORMAL;
	f322 tex : TEXCOORD0;
	row_major f324x4 worldMatrix : MATRIX;
	f324 diffuseColor : COLOR;
};

struct VS_OUTPUT
{
	f324 pos : SV_POSITION;
	f323 normal : TEXCOORD0;
	f323 worldPosition : TEXCOORD1;
	f324 color : TEXCOORD2;
	f322 tex : TEXCOORD3;
};

struct PS_OUTPUT
{
	f324 color : SV_Target0;
	f32  depth : SV_Target1;
	f324 normal : SV_Target2;
};

//-------------------------------------------------------------

Texture2D texture0 : register( t0 );
SamplerState sampler0 : register( s0 );

cbuffer vscbMesh0 : register( b0 )
{
	row_major f324x4 g_viewProjectionMatrix;
}

VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;

	const f32 hScale = 5.0;
	const f32 dUV = 1.0 / 128;
	const f32 n = texture0.SampleLevel(sampler0,input.tex + f322(0, -dUV), 0).r;
	const f32 s = texture0.SampleLevel(sampler0,input.tex + f322(0, dUV), 0).r;
	const f32 w = texture0.SampleLevel(sampler0,input.tex + f322(-dUV, 0), 0).r;
	const f32 e = texture0.SampleLevel(sampler0,input.tex + f322(dUV, 0), 0).r;
	const f32 h = texture0.SampleLevel(sampler0,input.tex + f322(0, 0), 0).r;
	const f32 d = 160.0 / 128 / hScale;

	input.pos.y *= h * hScale;

	const f324 posWS = mul(input.pos, input.worldMatrix);

	output.pos = mul(posWS,g_viewProjectionMatrix);

	output.normal = normalize(f323(w-e, 2*d, s-n));

	output.worldPosition = posWS.xyz;

	output.color = input.diffuseColor;

	output.tex = input.tex;

	return output;
}

//-------------------------------------------------------------


cbuffer pscbMesh0 : register( b0 )
{
	f323 g_cameraPosition;
	uint g_fogType;
	f324 g_fogParam;
	f324 g_fogColor;
}

PS_OUTPUT PS(VS_OUTPUT input)
{
	PS_OUTPUT output;

	const f324 color = texture0.Sample(sampler0, input.tex * 8);

	if (color.a < 0.5)
	{
		clip(-1);
	}

	output.color = color * input.color;

	output.depth.r = distance(g_cameraPosition.xyz, input.worldPosition);

	output.normal = f324(normalize(input.normal), 1);

	return output;
}
