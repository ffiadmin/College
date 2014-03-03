//=======================================================================================
// Line.cpp by Frank Luna (C) 2008 All Rights Reserved.
//=======================================================================================

#include "Line.h"
#include "Vertex.h"

Line::Line()
: mNumVertices(0), mNumFaces(0), md3dDevice(0), mVB(0), mIB(0)
{
}
 
Line::~Line()
{
	ReleaseCOM(mVB);
	ReleaseCOM(mIB);
}

void Line::init(ID3D10Device* device, float scale)
{
	md3dDevice = device;
 
	mNumVertices = 2;

	// Create vertex buffer
    Vertex vertices[] =
    {
		{D3DXVECTOR3(-1.0f, -1.0f, -1.0f), WHITE},
		{D3DXVECTOR3(-1.0f, +1.0f, -1.0f), BLACK}
    };

    D3D10_BUFFER_DESC vbd;
    vbd.Usage = D3D10_USAGE_IMMUTABLE;
    vbd.ByteWidth = sizeof(Vertex) * mNumVertices;
    vbd.BindFlags = D3D10_BIND_VERTEX_BUFFER;
    vbd.CPUAccessFlags = 0;
    vbd.MiscFlags = 0;
    D3D10_SUBRESOURCE_DATA vinitData;
    vinitData.pSysMem = vertices;
    HR(md3dDevice->CreateBuffer(&vbd, &vinitData, &mVB));
}

void Line::draw()
{
	UINT stride = sizeof(Vertex);
    UINT offset = 0;
    md3dDevice->IASetVertexBuffers(0, 1, &mVB, &stride, &offset);
	md3dDevice->Draw(mNumVertices, 0);
}