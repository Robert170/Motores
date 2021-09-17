sampler InputImage;

float2 fViewportDimensions;

struct PS_INPUT
{
  float2 TexCoord : TEXCOORD0;
};

float gamma = 1.0f;

float4 ps_gaussian_blurH(PS_INPUT input) : COLOR0
{
  float offset[3] = {0.0, 1.3846153846, 3.2307692308};
  float weight[3] = {0.2270270270, 0.316216162, 0.0702702703};
  
  float4 FragmentColor = pow(tex2D(InputImage, input.TexCoord), gamma) * weight[0];
  
  for(int i = 1; i < 3; i++)
  {
    FragmentColor += pow(tex2D(InputImage, input.TexCoord + (float2(offset[i], 0.0f) / fViewportDimensions)), gamma) * weight[i];
	FragmentColor += pow(tex2D(InputImage, input.TexCoord - (float2(offset[i], 0.0f) / fViewportDimensions)), gamma) * weight[i];
  }
  
  return pow(FragmentColor, 1.0f/gamma);
}


float4 ps_gaussian_blurV(PS_INPUT input) : COLOR0
{
  float offset[3] = {0.0, 1.3846153846, 3.2307692308};
  float weight[3] = {0.2270270270, 0.316216162, 0.0702702703};
  
  float4 FragmentColor = pow(tex2D(InputImage, input.TexCoord), gamma) * weight[0];
  
  for(int i = 1; i < 3; i++)
  {
    FragmentColor += pow(tex2D(InputImage, input.TexCoord + (float2(0.0f, offset[i]) / fViewportDimensions)), gamma) * weight[i];
	FragmentColor += pow(tex2D(InputImage, input.TexCoord - (float2(0.0f, offset[i]) / fViewportDimensions)), gamma) * weight[i];
  }
  
  return pow(FragmentColor, 1.0f/gamma);
}