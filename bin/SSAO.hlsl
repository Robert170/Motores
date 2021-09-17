sampler PositionSampler;
sampler NormalSampler;

float2 ViewportDimensions;

float g_Sample_radius;
float g_Intensity;
float g_Scale;
float g_Bias;

struct PS_INPUT
{
  float2 TexCoord : TEXCOORD0;
};

struct PS_OUTPUT
{
  float4 Color : COLOR0;
};

float4 GetPosition(in float2 uv)
{
  return tex2D(PositionSampler, uv);
}

float3 GetNormal(in float2 uv)
{
  return normalize(tex2D(NormalSampler, uv).xyz);
}

float2 GetRandom(in float2 uv)
{
  float noiseX = (frac(sin(dot(uv, float2(15.8989f, 76.132f) * 1.0f)) * 46336.23745f));
  float noiseY = (frac(sin(dot(uv, float2(11.9899f, 62.223f) * 2.0f)) * 34748.34744f));
  float noiseZ = (frac(sin(dot(uv, float2(13.3238f, 63.122f) * 3.0f)) * 59998.47362f));

  return normalize(float3(noiseX, noiseY, noiseZ));
}

float DoAmbientOcclusion(in float2 tcoord, in float2 uv, in float3 p, in float3 cnorm)
{
  float3 diff = GetPosition(tcoord + uv) - p; //saca una coordenada en espacio de mundo
  const float3 v = normalize(diff);
  const float d = length(diff) * g_Scale;
  return max(0.0f, dot(cnorm, v) - g_Bias) * (1.0 / (1.0 + d)) * g_Intensity;
}

PS_OUTPUT ps_ssao(PS_INPUT input)
{
  PS_OUTPUT Output;
  Output.Color = float4(1, 1, 1, 1);

  const float2 vec[4] =
  {
    float2(1, 0), float2(-1, 0), float2(0, 1), float2(0, -1),
  };

  float4 p = GetPosition(input.TexCoord);

  float3 n = GetNormal(input.TexCoord);
  float2 rand = GetRandom(input.TexCoord);

  float ao = 0.0f;
  float2 rad = g_Sample_radius / p.z;

  int iterators = 4;

  for (int j = 0; j < iterators; ++j)
  {
    float2 coord1 = reflect(vec[j], rand) * rad;
    float2 coord2 = float2(coord1.x * 0.707 - coord1.y * 0.707,
                           coord1.x * 0.707 + coord1.y * 0.707);

    ao += DoAmbientOcclusion(input.TexCoord, coord1 * 0.25, p.xyz, n);
    ao += DoAmbientOcclusion(input.TexCoord, coord2 * 0.5, p.xyz, n);
    ao += DoAmbientOcclusion(input.TexCoord, coord1 * 0.75, p.xyz, n);
    ao += DoAmbientOcclusion(input.TexCoord, coord2, p.xyz, n);
  }

  ao /= (iterators * 4);
  Output.Color.rgb = 1 - ao.xxx;

  return Output;
}