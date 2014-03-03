#pragma once
#define ReleaseCOM(x) { if(x) { x->Release(); x = 0; } }

#include <cwchar>
#include <D3D10Effect.h>
#include "d3dUtil.h"
#include <D3DX10Async.h>
#include <DxErr.h>

namespace shaderNS {
	const char    PROFILE[]        = "fx_4_0";
	const wchar_t SHADER_FILE[]    = L"color.fx";
	const char    TECHNIQUE_NAME[] = "ColorTech";
	const char    WVP_VAR[]        = "gWVP";
}

class Shader {
public : 
	Shader();
	~Shader();

	void draw();
	void init(ID3D10Device *md3dDevice);

//Shader variables and techniques
	ID3D10Device *md3dDevice;
	ID3D10Effect *mFX;
	ID3D10EffectMatrixVariable *mfxWVPVar;
	ID3D10EffectTechnique *mTech;
	ID3D10InputLayout *mVertexLayout;
	D3D10_TECHNIQUE_DESC technique;
};