#include "..\stdafx.h"
#include "../Types/RenderTypes.h"
#include "Model.h"

using namespace Scene;
using namespace UITypes;

Model::Model() :
    vertices(8),
    indexes(6 * 6)
{

}

Model::~Model()
{

}

void Model::Initialize()
{
    SimpleVertex initVertices[] =
    { //  relative position             vertex color
        { Vector3(-1.0f, 1.0f, -1.0f),  Vector4(0.0f, 0.0f, 1.0f, 1.0f) },
        { Vector3(1.0f, 1.0f, -1.0f),   Vector4(0.0f, 1.0f, 0.0f, 1.0f) },
        { Vector3(1.0f, 1.0f, 1.0f),    Vector4(0.0f, 1.0f, 1.0f, 1.0f) },
        { Vector3(-1.0f, 1.0f, 1.0f),   Vector4(1.0f, 0.0f, 0.0f, 1.0f) },
        { Vector3(-1.0f, -1.0f, -1.0f), Vector4(1.0f, 0.0f, 1.0f, 1.0f) },
        { Vector3(1.0f, -1.0f, -1.0f),  Vector4(1.0f, 1.0f, 0.0f, 1.0f) },
        { Vector3(1.0f, -1.0f, 1.0f),   Vector4(1.0f, 1.0f, 1.0f, 1.0f) },
        { Vector3(-1.0f, -1.0f, 1.0f),  Vector4(0.0f, 0.0f, 0.0f, 1.0f) },
    };

    for (int i = 0; i < sizeof(initVertices) / sizeof(SimpleVertex); i++)
    {
        this->vertices[i] = initVertices[i];
    }

    unsigned short initIndices[] =
    {
        3,1,0,
        2,1,3,

        0,5,4,
        1,5,0,

        3,4,7,
        0,4,3,

        1,6,5,
        2,6,1,

        2,7,6,
        3,7,2,

        6,4,5,
        7,4,6
    };
    int indexcount = sizeof(initIndices) / sizeof(unsigned short);
    for (int i = 0; i < indexcount; i++)
    {
        this->indexes[i] = initIndices[i];
    }
}

const VArray<SimpleVertex>& Model::GetVertexData() const
{
    return this->vertices;
}

const VArray<UINT16>& Model::GetIndexData() const
{
    return this->indexes;
}

Matrix4x4 Model::GetTransform() const
{
    //Matrix4x4 transform;
    // start with just the identity matrix for now.

    return Matrix4x4();
}

void Model::Tick(float timeSpan)
{

}