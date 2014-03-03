#include "Shader.h"


Shader::Shader() : mFX(0), mfxWVPVar(0), mTech(0), mVertexLayout(0) { }

Shader::~Shader() {
	ReleaseCOM(mFX);
	ReleaseCOM(mVertexLayout);

	delete mFX;
	//delete mfxWVPVar;
	//delete mTech;
	//delete mVertexLayout;
}

void Shader::draw() {
//Restore the default states, input layout, and primitive topology
	md3dDevice->OMSetDepthStencilState(0, 0);
	float blendFactors[] = {0.0f, 0.0f, 0.0f, 0.0f};
	md3dDevice->OMSetBlendState(0, blendFactors, 0xffffffff);
    md3dDevice->IASetInputLayout(mVertexLayout);

//Set the point to the shader technique
	D3D10_TECHNIQUE_DESC techDesc;
	mTech->GetDesc(&techDesc);
	technique = techDesc;
}

void Shader::init(ID3D10Device *md3dDevice) {
	this->md3dDevice = md3dDevice;

//Collect and compile information from the shader
	ID3D10Blob *compilationErrors = 0;
	DWORD shaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;

	#if defined( DEBUG ) || defined( _DEBUG )
		shaderFlags |= D3D10_SHADER_DEBUG;
		shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
	#endif
	
	HRESULT hr = D3DX10CreateEffectFromFile(shaderNS::SHADER_FILE, 0, 0, shaderNS::PROFILE, shaderFlags, 0, md3dDevice, 0, 0, &mFX, &compilationErrors, 0);

	if(FAILED(hr)) {
		if(compilationErrors) {
			MessageBoxA(0, static_cast<char*>(compilationErrors->GetBufferPointer()), 0, 0);
			ReleaseCOM(compilationErrors);
		}

		DXTrace(__FILE__, (DWORD)__LINE__, hr, L"D3DX10CreateEffectFromFile", true);
	} 

	mfxWVPVar = mFX->GetVariableByName(shaderNS::WVP_VAR)->AsMatrix();
	mTech = mFX->GetTechniqueByName(shaderNS::TECHNIQUE_NAME);

//Build the vertex layouts
	D3D10_INPUT_ELEMENT_DESC vertexDesc[] = {
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
	};

	// Create the input layout
    D3D10_PASS_DESC PassDesc;
    mTech->GetPassByIndex(0)->GetDesc(&PassDesc);
    HR(md3dDevice->CreateInputLayout(vertexDesc, 2, PassDesc.pIAInputSignature, PassDesc.IAInputSignatureSize, &mVertexLayout));
}