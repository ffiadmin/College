//=============================================================================
// Exam 1 Starter Kit
//
// Based on code by Frank Luna and William Birmingham
//=============================================================================

#include "d3dApp.h"
#include "Box.h"
#include "GameObject.h"
#include "Line.h"
#include "LineObject.h"
#include <d3dx9math.h>


class ColoredCubeApp : public D3DApp
{
public:
	ColoredCubeApp(HINSTANCE hInstance);
	~ColoredCubeApp();

	void initApp();
	void onResize();
	void updateScene(float dt);
	void drawScene(); 

private:
	void buildFX();
	void buildVertexLayouts();
 
private:
	// geometry defs go here

	// GameObject defs to here

	// world matrices defs go here for all the displayed geometry

	Line rline, gline, bline;
	LineObject xLine, yLine, zLine;
	Box wBox, gBox;
	GameObject whiteBox, spinner;

	float spinAmount;

	ID3D10Effect* mFX;
	ID3D10EffectTechnique* mTech;
	ID3D10InputLayout* mVertexLayout;
	ID3D10EffectMatrixVariable* mfxWVPVar;
	ID3D10EffectVariable* mfxFLIPVar;

	D3DXMATRIX mView;
	D3DXMATRIX mProj;
	D3DXMATRIX mWVP;


	float mTheta;
	float mPhi;

	// Camera stuff
	Vector3 cameraPos;
	Vector3 lookAt;
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif


	ColoredCubeApp theApp(hInstance);
	
	theApp.initApp();

	return theApp.run();
}

ColoredCubeApp::ColoredCubeApp(HINSTANCE hInstance)
: D3DApp(hInstance), mFX(0), mTech(0), mVertexLayout(0),
  mfxWVPVar(0), mTheta(0.0f), mPhi(PI*0.25f)
{
	D3DXMatrixIdentity(&mView);
	D3DXMatrixIdentity(&mProj);
	D3DXMatrixIdentity(&mWVP); 
}

ColoredCubeApp::~ColoredCubeApp()
{
	if( md3dDevice )
		md3dDevice->ClearState();

	ReleaseCOM(mFX);
	ReleaseCOM(mVertexLayout);
}

void ColoredCubeApp::initApp()
{
	D3DApp::initApp();
	
	//add inits here 
	rline.init(md3dDevice, 5.0f, RED);
	gline.init(md3dDevice, 5.0f, GREEN);
	bline.init(md3dDevice, 5.0f, CYAN);  //Can't see BLUE
	xLine.init(&rline, Vector3(0,0,0), 1);
	xLine.setPosition(Vector3(5,0,0));
	yLine.init(&gline, Vector3(0,0,0), 1);
	yLine.setPosition(Vector3(0,5,0));
	yLine.setRotationZ(ToRadian(90));
	zLine.init(&bline, Vector3(0,0,0), 1);
	zLine.setPosition(Vector3(0,0,5));
	zLine.setRotationY(ToRadian(90));

	wBox.init(md3dDevice, 1.0f, WHITE);
	gBox.init(md3dDevice, 1.0f, GREEN);
  
  //Box, COllision radius, 3D position, 3D velocity, speed, scale
	whiteBox.init(&wBox, sqrt(2.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0, 0, 0), 0, 1);
	spinner.init(&gBox, sqrt(2.0f), D3DXVECTOR3(0.0f, 2.0f, 0.0f), D3DXVECTOR3(0, 0, 0), 0, 1);

	buildFX();
	buildVertexLayouts();

	spinAmount = 0;

	HWND foo = getMainWnd();
	lookAt = Vector3(0,0,0);
}

void ColoredCubeApp::onResize()
{
	D3DApp::onResize();
	float aspect = (float)mClientWidth/mClientHeight;
	D3DXMatrixPerspectiveFovLH(&mProj, 0.25f*PI, aspect, 1.0f, 1000.0f);
}

void ColoredCubeApp::updateScene(float dt)
{
	D3DApp::updateScene(dt);
	spinAmount += 1*dt;
	if (spinAmount > 360)
		spinAmount = 0;
	// All updates go here

	xLine.update(dt);
	yLine.update(dt);
	zLine.update(dt);
	spinner.update(dt);
	whiteBox.update(dt);

	// Build the camera matrices

	D3DXVECTOR3 pos(15.0f,15.0f,15.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&mView, &pos, &target, &up);
}

void ColoredCubeApp::drawScene()
{
	D3DApp::drawScene();

	// Restore default states, input layout and primitive topology 
	// because mFont->DrawText changes them.  Note that we can 
	// restore the default states by passing null.
	md3dDevice->OMSetDepthStencilState(0, 0);
	float blendFactors[] = {0.0f, 0.0f, 0.0f, 0.0f};
	md3dDevice->OMSetBlendState(0, blendFactors, 0xffffffff);
    md3dDevice->IASetInputLayout(mVertexLayout);

	// DON'T Change the color of the geometry
	int foo[1];
	foo[0] = 0;
	mfxFLIPVar->SetRawValue(&foo[0], 0, sizeof(int));

	D3D10_TECHNIQUE_DESC techDesc;
	mTech->GetDesc(&techDesc);
	
	// LINE drawing goes here
	mWVP = xLine.getWorldMatrix()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	xLine.setMTech(mTech);
	xLine.draw();

	mWVP = yLine.getWorldMatrix() *mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	yLine.setMTech(mTech);
	yLine.draw();

	mWVP = zLine.getWorldMatrix() *mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	zLine.setMTech(mTech);
	zLine.draw();

	// GameObject drawing goes here
	mWVP = whiteBox.getWorldMatrix()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	whiteBox.setMTech(mTech);
	whiteBox.draw();

	static float r;
	D3DXMATRIX w;
	D3DXMATRIX w2;
	D3DXMATRIX w3;
	D3DXMatrixIdentity(&w);
	D3DXMatrixIdentity(&w2);
	D3DXMatrixIdentity(&w3);
	D3DXMatrixRotationX(&w, r);
	D3DXMatrixTranslation(&w2, 0.0f, 2.0f, 3.0f);
	D3DXMatrixRotationY(&w3, r);
	w *= w2 * w3;
	r += 0.001f;

	spinner.setWorldMatrix(w);
	mWVP = spinner.getWorldMatrix()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	spinner.setMTech(mTech);
	spinner.draw();

	// We specify DT_NOCLIP, so we do not care about width/height of the rect.
	RECT R = {5, 5, 0, 0};
	mFont->DrawText(0, mFrameStats.c_str(), -1, &R, DT_NOCLIP, BLACK);

	mSwapChain->Present(0, 0);
}

void ColoredCubeApp::buildFX()
{
	DWORD shaderFlags = D3D10_SHADER_ENABLE_STRICTNESS;
#if defined( DEBUG ) || defined( _DEBUG )
    shaderFlags |= D3D10_SHADER_DEBUG;
	shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
#endif
 
	ID3D10Blob* compilationErrors = 0;
	HRESULT hr = 0;
	hr = D3DX10CreateEffectFromFile(L"color.fx", 0, 0, 
		"fx_4_0", shaderFlags, 0, md3dDevice, 0, 0, &mFX, &compilationErrors, 0);
	if(FAILED(hr))
	{
		if( compilationErrors )
		{
			MessageBoxA(0, (char*)compilationErrors->GetBufferPointer(), 0, 0);
			ReleaseCOM(compilationErrors);
		}
		DXTrace(__FILE__, (DWORD)__LINE__, hr, L"D3DX10CreateEffectFromFile", true);
	} 

	mTech = mFX->GetTechniqueByName("ColorTech");
	
	mfxWVPVar = mFX->GetVariableByName("gWVP")->AsMatrix();
	mfxFLIPVar = mFX->GetVariableByName("flip");

}

void ColoredCubeApp::buildVertexLayouts()
{
	// Create the vertex input layout.
	D3D10_INPUT_ELEMENT_DESC vertexDesc[] =
	{
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D10_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR",    0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D10_INPUT_PER_VERTEX_DATA, 0}
	};

	// Create the input layout
    D3D10_PASS_DESC PassDesc;
    mTech->GetPassByIndex(0)->GetDesc(&PassDesc);
    HR(md3dDevice->CreateInputLayout(vertexDesc, 2, PassDesc.pIAInputSignature,
		PassDesc.IAInputSignatureSize, &mVertexLayout));
}
 