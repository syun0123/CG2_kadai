//float4 main(float4 pos : POSITION) : SV_POSITION
//{
//    return pos;
//}


/*struct VertexShaderOutput
{
    float32_t4 position : SV_POSITION;
};*/

struct TransformatiomMatrix
{
    float32_t4x4 WVP;
};
ConstantBuffer<TransformatiomMatrix> gTransformationMatrix : register(b0);
struct VertexShaderOutput
{
    float32_t4 position : SV_POSITION0;
};

VertexShaderOutput main(VertexShaderInput input)
{
    VertexShaderOutput output;
    output.position = mul(input.position, gTransformationMatrix.WVP);
    return output;
}
