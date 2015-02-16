
#pragma once

#include "MeshBuilder.h"
#include "VertexTypeManager.h"

namespace Procedural {

	typedef MeshBuilder<VertexTypeManager::VertexPosNormalUV, __int32> MeshBuilderType;
	typedef DirectX::XMFLOAT3 Vector3;

	typedef VertexTypeManager::VertexPosNormalUV vertex;

	extern RefCountPointer<MeshCPU> MakeBox();
	extern RefCountPointer<MeshCPU> MakePlane();

};
