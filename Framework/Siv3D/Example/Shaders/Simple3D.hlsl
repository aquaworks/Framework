
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

cbuffer vscbMesh0 : register( b0 )
{
	row_major f324x4 g_viewProjectionMatrix;
}

VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;

	const f324 posWS = mul(input.pos, input.worldMatrix);

	output.worldPosition = posWS.xyz;

	output.pos = mul(posWS,g_viewProjectionMatrix);

	output.normal = mul(input.normal,(f323x3)input.worldMatrix);

	output.color = input.diffuseColor;

	output.tex = input.tex;

	return output;
}

//-------------------------------------------------------------

Texture2D texture0 : register( t0 );
SamplerState sampler0 : register( s0 );

cbuffer pscbMesh0 : register( b0 )
{
	f324 cameraPosition;
}

PS_OUTPUT PS(VS_OUTPUT input)
{
	PS_OUTPUT output;

	const f324 color = texture0.Sample(sampler0,input.tex);

	if (color.a < 0.5)
	{
		clip(-1);
	}

	output.color = color * input.color;

	output.depth.r = distance(cameraPosition.xyz, input.worldPosition);

	output.normal = f324(normalize(input.normal), 1);

	return output;
}
