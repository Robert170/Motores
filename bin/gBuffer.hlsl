sampler Texture0;
sampler Normal;
sampler EmisTexture;
sampler MetaTexture;
sampler RougTexture;

float4x4 matView;
float4x4 matWorld;
float4x4 matProjection;

float3 ObjectPosition;

struct VS_INPUT
{
  float4 Position : POSITION0;
  float2 Texcoord : TEXCOORD0;
  float3 Normal : NORMAL0;
  float3 Tangent : TANGENT0;
  float3 Bitangent : BINORMAL0;
  
};

struct VS_OUTPUT
{
  float4 Position : POSITION0;
  float3 PosView : TEXCOORD0;
  float2 Texcoord : TEXCOORD1;
  float3x3 TBN    : TEXCOORD2;
 
};

struct PS_INPUT
{
  float4 Position : POSITION0;
  float3 PosView : TEXCOORD0;
  float2 Texcoord : TEXCOORD1;
  float3x3 TBN    : TEXCOORD2;
  float2 PosScreen : VPOS;
  
};

struct PS_OUTPUT
{
  float4 Position : COLOR0;
  float4 Normal   : COLOR1;
  float4 DiffColor : COLOR2;
  float4 EmissiveColor : COLOR3;
};

VS_OUTPUT vs_gbuffer(VS_INPUT Input)
{
  VS_OUTPUT Output = (VS_OUTPUT)0;

  float4x4 newMatWorld;
  newMatWorld[0] = float4(1, 0, 0, 0);
  newMatWorld[1] = float4(0, 1, 0, 0);
  newMatWorld[2] = float4(0, 0, 1, 0);
  newMatWorld[3] = float4(ObjectPosition, 1);
  
  float4x4 matWV = mul(newMatWorld, matView);

  Output.Position = mul(Input.Position, matWV);
  Output.PosView = Output.Position.xyz;

  // Output.Position = mul(Output.Position, matView);
  Output.Position = mul(Output.Position, matProjection);
  
  Output.Texcoord = Input.Texcoord;
  
  Output.TBN[0] = normalize(mul(float4(Input.Tangent, 0.0f), matWV));
  Output.TBN[1] = normalize(mul(float4(Input.Bitangent, 0.0f), matWV));
  Output.TBN[2] = normalize(mul(float4(Input.Normal, 0.0f), matWV));

  //Output.Normal = normalize(mul(Input.Normal, newMatWorld));

  return(Output);

}


PS_OUTPUT ps_gbuffer(PS_INPUT Input)
{

  PS_OUTPUT Output = (PS_OUTPUT)0;

  Output.Position = float4(Input.PosView, 1.0f);
  Output.Normal.xyz = 2.0f * tex2D(Normal, Input.Texcoord) - 1.0f;
  Output.Normal.xyz = normalize(mul(Output.Normal.xyz, Input.TBN));
  Output.Normal.w = tex2D(RougTexture, Input.Texcoord).x;
  Output.DiffColor.xyz = tex2D(Texture0, Input.Texcoord).xyz;
  Output.DiffColor.w = tex2D(MetaTexture, Input.Texcoord).x;
  Output.EmissiveColor.xyz = tex2D(EmisTexture, Input.Texcoord).xyz;
  return Output;

}






