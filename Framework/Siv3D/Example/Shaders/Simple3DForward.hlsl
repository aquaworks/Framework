
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
	f323 worldPosition : TEXCOORD0;
	f324 color : TEXCOORD1;
	f322 tex : TEXCOORD2;
};

//-------------------------------------------------------------

struct Light
{
	f323 position;
	uint type;
	f324 diffuseColor;
	f324 attenuation;
};

cbuffer vscbMesh0 : register( b0 )
{
	row_major f324x4 g_viewProjectionMatrix;

	f324 g_ambientColor;

	Light g_lights[4];
}

f32 CalculateDirectionalLight(f323 surfaceNormal, f323 direction)
{
	return saturate(dot(surfaceNormal, direction.xyz)); 
}

f32 CalculatePointLight(f323 surfaceNormal, f323 surfacePosition, f323 lightPosition, f323 lightAttenuation)
{
	f323 lightDirection = (lightPosition - surfacePosition);
	const f32 d = length(lightDirection);
	const f32 Kc = lightAttenuation.x;
	const f32 Kl = lightAttenuation.y;
	const f32 Kq = lightAttenuation.z;
	const f32 f_att = 1.0/(Kc+Kl*d+Kq*d*d);
	lightDirection = normalize(lightDirection);
	const f32 diffuseInfluence = saturate(dot(lightDirection,surfaceNormal)) * f_att;
	return diffuseInfluence;
}

VS_OUTPUT VS(VS_INPUT input)
{
	VS_OUTPUT output;

	const f324 posWS = mul(input.pos, input.worldMatrix);

	output.worldPosition = posWS.xyz;

	output.pos = mul(posWS,g_viewProjectionMatrix);

	output.tex = input.tex;

	const f323 surfaceNormal = normalize(mul(input.normal,(f323x3)input.worldMatrix));

	output.color = g_ambientColor;

	[unroll]
	for(uint i = 0; i < 4; ++i)
	{
		output.color.rgb += 
		(g_lights[i].type ? 
		CalculatePointLight(surfaceNormal, output.worldPosition, g_lights[i].position.xyz, g_lights[i].attenuation.xyz)
		: CalculateDirectionalLight(surfaceNormal, g_lights[i].position.xyz)) * g_lights[i].diffuseColor.rgb;
	}

	output.color *= input.diffuseColor;

	return output;
}

//-------------------------------------------------------------

Texture2D texture0 : register( t0 );
SamplerState sampler0 : register( s0 );

cbuffer pscbMesh0 : register( b0 )
{
	f323 g_cameraPosition;
	uint g_fogType;
	f324 g_fogParam;
	f324 g_fogColor;
}

f324 PS(VS_OUTPUT input) : SV_Target
{
	return texture0.Sample(sampler0,input.tex) * input.color;
}
