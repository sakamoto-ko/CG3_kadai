#include "Particle.hlsli"

struct Material
{
    float32_t4 color;
    int32_t enableLighting;
    float32_t4x4 uvTransform;
    float32_t shininess;
};

struct Camera
{
    float32_t3 worldPosition;
};

ConstantBuffer<Material> gMaterial : register(b0);

//ConstantBuffer<Camera> gCamera : register(b2);

Texture2D<float32_t4> gTexture : register(t0);

SamplerState gSampler : register(s0);

ConstantBuffer<DirectionalLight> gDirectionalLight : register(b1);

struct PixelShaderOutput
{
    float32_t4 color : SV_TARGET0;
};

PixelShaderOutput main(VertexShaderOutput input)
{
    PixelShaderOutput output;
    float32_t4 textureColor = gTexture.Sample(gSampler, input.texcoord);

    //float32_t3 toEye = normalize(gCamera.worldPosition = input.worldPosition);
    
    if (output.color.a == 0.0)
    {
        discard;
    }
    
    if (gMaterial.enableLighting != 0)
    {
        float cos = saturate(dot(normalize(input.normal), -gDirectionalLight));
        output.color = gMaterial.color * textureColor * gDirectionalLight.color * cos * gDirectionalLight.intensity;
    }
    else
    {
        output.color = gMaterial.color * textureColor;
    }
    
    return output;
}