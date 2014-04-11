//=============================================================================
// lighting.fx by Frank Luna (C) 2008 All Rights Reserved.
//
// Transforms and lights geometry.
//=============================================================================

#include "lighthelper.fx"
 
cbuffer cbPerFrame
{
	Light gLightPara;
	Light gLightPt1;
	Light gLightSpot;
	Light gLightPt2;

	float3 gEyePosW;
};

cbuffer cbPerObject
{
	float4x4 gWorld;
	float4x4 gWVP;
};

struct VS_IN
{
	float3 posL    : POSITION;
	float3 normalL : NORMAL;
	float4 diffuse : DIFFUSE;
	float4 spec    : SPECULAR;
};

struct VS_OUT
{
	float4 posH    : SV_POSITION;
    float3 posW    : POSITION;
    float3 normalW : NORMAL;
    float4 diffuse : DIFFUSE;
    float4 spec    : SPECULAR;
};

VS_OUT VS(VS_IN vIn)
{
	VS_OUT vOut;
	
	// Transform to world space space.
	vOut.posW    = mul(float4(vIn.posL, 1.0f), gWorld);
	vOut.normalW = mul(float4(vIn.normalL, 0.0f), gWorld);
		
	// Transform to homogeneous clip space.
	vOut.posH = mul(float4(vIn.posL, 1.0f), gWVP);
	
	// Output vertex attributes for interpolation across triangle.
	vOut.diffuse = vIn.diffuse;
	vOut.spec    = vIn.spec;
	
	return vOut;
}
 
float4 PS(VS_OUT pIn) : SV_Target
{
	// Interpolating normal can make it not be of unit length so normalize it.
    pIn.normalW = normalize(pIn.normalW);
   
   
    SurfaceInfo v = {pIn.posW, pIn.normalW, pIn.diffuse, pIn.spec};
    
    float4 para = float4(ParallelLight(v, gLightPara, gEyePosW), pIn.diffuse.a);
	float4 pt1 = float4(PointLight(v, gLightPt1, gEyePosW), pIn.diffuse.a);
	float4 spot = float4(Spotlight(v, gLightSpot, gEyePosW), pIn.diffuse.a);
	float4 pt2 = float4(PointLight(v, gLightPt2, gEyePosW), pIn.diffuse.a);

	return para + pt1 + spot + pt2;
}

technique10 LightTech
{
    pass P0
    {
        SetVertexShader( CompileShader( vs_4_0, VS() ) );
        SetGeometryShader( NULL );
        SetPixelShader( CompileShader( ps_4_0, PS() ) );
    }
}



