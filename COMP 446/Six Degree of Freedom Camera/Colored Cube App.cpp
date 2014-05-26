//=============================================================================
// Color Cube App.cpp by Frank Luna (C) 2008 All Rights Reserved.
//
// Demonstrates coloring.
//
// Controls:
//		'A'/'D'/'W'/'S' - Rotate 
//
//=============================================================================

//#include "d3dApp.h"
#include "d3dApp.h"
#include "Box.h"
#include "GameObject.h"
#include "Line.h"
#include "Quad.h"
#include <d3dx9math.h>
#include "input.h"
#include "Camera.h"



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
	Quad quad1;
	Line xLine, yLine, zLine;
	Box mBox, redBox;
	GameObject gameObject1, gameObject2, gameObject3, spinner;

	float spinAmount;
	float deltaYaw;
	float deltaPitch;

	ID3D10Effect* mFX;
	ID3D10EffectTechnique* mTech;
	ID3D10InputLayout* mVertexLayout;
	ID3D10EffectMatrixVariable* mfxWVPVar;
	//my addition
	ID3D10EffectVariable* mfxFLIPVar;

	D3DXMATRIX mView;
	D3DXMATRIX mProj;
	D3DXMATRIX mWVP;

	//my edits
	D3DXMATRIX worldBox1, worldBox2;

	float mTheta;
	float mPhi;

	// Camera stuff
	Vector3 cameraPos;
	Vector3 lookAt;

	//Camera Object stuff
	Camera camera;
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
	
	mBox.init(md3dDevice, 1.0f, WHITE);
	redBox.init(md3dDevice, 1.0f, RED);
	xLine.init(md3dDevice, 5.0f, GREEN);
	xLine.setPosition(Vector3(0,0,0));
	yLine.init(md3dDevice, 5.0f, GREEN);
	yLine.setPosition(Vector3(0,0,0));
	yLine.setRotYAngle(ToRadian(90));
	zLine.init(md3dDevice, 5.0f, GREEN);
	zLine.setPosition(Vector3(0,0,0));
	zLine.setRotZAngle(D3DXToRadian(90));
	quad1.init(md3dDevice, 10, CYAN);
	quad1.setPosition(Vector3(0,-1.2,0));

	spinAmount = 0;

	spinner.init(&redBox, 0, Vector3(0,4,0), Vector3(0,0,0), 0,1);

	//game object init;

	gameObject1.init(&mBox, sqrt(2.0f), Vector3(0,0,0), Vector3(1,0,0), 0,1);
	gameObject2.init(&redBox, sqrt(2.0f), Vector3(4,0,0), Vector3(0,0,0), 0,1);
	gameObject3.init(&redBox, sqrt(2.0f), Vector3(-4,0,0), Vector3(0,0,0), 0,1);

	buildFX();
	buildVertexLayouts();

	//my changes

	spinAmount = 0;



	//Camera Object
	camera.init(Vector3(25,25,25), Vector3(0,0,0), Vector3(0,0,0));
	camera.setPerspective();
	// camera
	cameraPos = Vector3(10,10,10);
}

void ColoredCubeApp::onResize()
{
	D3DApp::onResize();
	//Camera Object
	camera.setPerspective();
	float aspect = (float)mClientWidth/mClientHeight;
	D3DXMatrixPerspectiveFovLH(&mProj, 0.25f*PI, aspect, 1.0f, 1000.0f);
}

void ColoredCubeApp::updateScene(float dt)
{
	D3DApp::updateScene(dt);
	gameObject1.update(dt);
	gameObject2.update(dt);
	gameObject3.update(dt);
	spinner.update(dt);
	xLine.update(dt);
	yLine.update(dt);
	zLine.update(dt);
	quad1.update(dt);

	if (gameObject1.collided(&gameObject2) || gameObject1.collided(&gameObject3))
		gameObject1.setVelocity(-1*gameObject1.getVelocity());

	spinAmount += dt ;
	if (ToRadian(spinAmount*40)>2*PI)
		spinAmount = 0;
	Vector3 dir = Vector3(0,0,0);
	


	//Camera Object
	camera.update(dt);

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

	//Get Camera viewMatrix
	 mView = camera.getViewMatrix();
	 mProj = camera.getProjectionMatrix();

	// Line

	int foo[1];
	foo[0] = 0;
	mfxFLIPVar->SetRawValue(&foo[0], 0, sizeof(int));
	mWVP = xLine.getWorld()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
    D3D10_TECHNIQUE_DESC techDesc;
    mTech->GetDesc( &techDesc );
    for(UINT p = 0; p < techDesc.Passes; ++p)
    {
        mTech->GetPassByIndex( p )->Apply(0);
       xLine.draw();
    }

	mWVP = yLine.getWorld() *mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
    mTech->GetDesc( &techDesc );
	for(UINT p = 0; p < techDesc.Passes; ++p)
    {
        mTech->GetPassByIndex( p )->Apply(0);
       yLine.draw();
    }

	mWVP = zLine.getWorld() *mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
    mTech->GetDesc( &techDesc );
	for(UINT p = 0; p < techDesc.Passes; ++p)
    {
        mTech->GetPassByIndex( p )->Apply(0);
       zLine.draw();
    }

	mWVP = quad1.getWorld()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
    mTech->GetDesc( &techDesc );
	for(UINT p = 0; p < techDesc.Passes; ++p)
    {
        mTech->GetPassByIndex( p )->Apply(0);
       quad1.draw();
    }
	mWVP = gameObject1.getWorldMatrix()  *mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	gameObject1.setMTech(mTech);
	gameObject1.draw();

	mWVP = gameObject2.getWorldMatrix()*mView*mProj;
	mfxWVPVar->SetMatrix((float*)&mWVP);
	gameObject2.setMTech(mTech);
	gameObject2.draw();
	mWVP = gameObject3.getWorldMatrix()*mView*mProj;

	foo[0] = 1;
	mfxFLIPVar->SetRawValue(&foo[0], 0, sizeof(int));
	mfxWVPVar->SetMatrix((float*)&mWVP);
	gameObject3.setMTech(mTech);
	gameObject3.draw();
     
	if (ToRadian(spinAmount*40) > PI)
		foo[0] = 1;
	else
		foo[0] = 0;
	mfxFLIPVar->SetRawValue(&foo[0], 0, sizeof(int));
	Matrix spin;
	RotateY(&spin, ToRadian(spinAmount*40));
	Matrix translate;
	Translate(&translate, 5, 0, 0);
	mWVP = spinner.getWorldMatrix() *translate * spin  *mView*mProj;
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
	//shaderFlags |= D3D10_SHADER_SKIP_OPTIMIZATION;
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
 