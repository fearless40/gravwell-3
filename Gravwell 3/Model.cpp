#include "stdafx.h"
#include <d3d11.h>
#include "D3D11.h"
#include "Mesh.h"
#include "VertexTypeDescription.h"
#include "VertexShader.h"
#include "Model.h"
#include "MeshManager.h"
#include "VertexBufferManager.h"
#include "VertexShaderManager.h"
#include "ConstantBufferArrayManager.h"


Model::Model() :
	mIOffset(0),
	mINumber(0),
	mIVertexOffset(0)
{
}
	

Model::~Model() 
{
	// memory release is automatic
}


#ifdef _DEBUG
void Model::render(D3D11 * d3d)
{

	Mesh & mesh = MeshManager::fromHandle( mMesh );

	d3d->getDeviceContext()->IASetInputLayout( mesh.mLayout );

	d3d->getDeviceContext()->IASetPrimitiveTopology( mesh.mTopology  );

	d3d->getDeviceContext()->VSSetShader( VertexShaderManager::fromHandle( mVSShader ), 0, 0 );

	d3d->getDeviceContext()->IASetVertexBuffers(0, 1, MeshManager::getVertexBuffers(mMesh), mesh.mStrides, mesh.mVOffset );

	d3d->getDeviceContext()->IASetIndexBuffer( MeshManager::getIndexBuffer(mMesh), DXGI_FORMAT_R32_UINT, mIOffset );

	d3d->getDeviceContext()->DrawIndexed( mINumber, 0, 0 ); 
}

#endif