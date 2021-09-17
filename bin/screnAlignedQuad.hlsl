float4x4 matView;
float4x4 matWorld;
float4x4 matProjection;

struct VS_INPUT
{
  float4 Position : POSITION0;
  float2 TexCoord : TEXCOORD0;

};

struct VS_OUTPUT
{
  float4 Position : POSITION0;
  float2 TexCoord : TEXCOORD0;

};

VS_OUTPUT vs_ssaligned(VS_INPUT Input)
{
  VS_OUTPUT Output = (VS_OUTPUT)0;

  Output.Position = Input.Position;

  Output.TexCoord = Input.TexCoord;

  return(Output);

}



