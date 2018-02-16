#include "..\stdafx.h"
#include "../Types/RenderTypes.h"
#include "Model.h"

using namespace Scene;
using namespace UITypes;

Model::Model() :
    vertices(24),
    indexes(6 * 6)
{

}

Model::~Model()
{

}

void Model::Initialize()
{
    SimpleVertex initVertices[] =
    { //  relative position             normal
        { Vector3(-1.f, 1.f, -1.f), Vector3(0.f, 1.f, 0.f) },
        { Vector3(1.f, 1.f, -1.f), Vector3(0.f, 1.f, 0.f) },
        { Vector3(1.f, 1.f, 1.f), Vector3(0.f, 1.f, 0.f) },
        { Vector3(-1.f, 1.f, 1.f), Vector3(0.f, 1.f, 0.f) },

        { Vector3(-1.f, -1.f, -1.f), Vector3(0.f, -1.f, 0.f) },
        { Vector3(1.f, -1.f, -1.f), Vector3(0.f, -1.f, 0.f) },
        { Vector3(1.f, -1.f, 1.f), Vector3(0.f, -1.f, 0.f) },
        { Vector3(-1.f, -1.f, 1.f), Vector3(0.f, -1.f, 0.f) },
        
        { Vector3(-1.f, -1.f, 1.f), Vector3(-1.f, 0.f, 0.f) },
        { Vector3(-1.f, -1.f, -1.f), Vector3(-1.f, 0.f, 0.f) },
        { Vector3(-1.f, 1.f, -1.f), Vector3(-1.f, 0.f, 0.f) },
        { Vector3(-1.f, 1.f, 1.f), Vector3(-1.f, 0.f, 0.f) },
        
        { Vector3(1.f, -1.f, 1.f), Vector3(1.f, 0.f, 0.f) },
        { Vector3(1.f, -1.f, -1.f), Vector3(1.f, 0.f, 0.f) },
        { Vector3(1.f, 1.f, -1.f), Vector3(1.f, 0.f, 0.f) },
        { Vector3(1.f, 1.f, 1.f), Vector3(1.f, 0.f, 0.f) },

        { Vector3(-1.f, -1.f, -1.f), Vector3(0.f, 0.f, -1.f) },
        { Vector3(1.f, -1.f, -1.f), Vector3(0.f, 0.f, -1.f) },
        { Vector3(1.f, 1.f, -1.f), Vector3(0.f, 0.f, -1.f) },
        { Vector3(-1.f, 1.f, -1.f), Vector3(0.f, 0.f, -1.f) },

        { Vector3(-1.f, -1.f, 1.f), Vector3(0.f, 0.f, 1.f) },
        { Vector3(1.f, -1.f, 1.f), Vector3(0.f, 0.f, 1.f) },
        { Vector3(1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f) },
        { Vector3(-1.f, 1.f, 1.f), Vector3(0.f, 0.f, 1.f) },

    };

    for (int i = 0; i < sizeof(initVertices) / sizeof(SimpleVertex); i++)
    {
        this->vertices[i] = initVertices[i];
    }

    unsigned short initIndices[] =
    {
        3,1,0,
        2,1,3,

        6,4,5,
        7,4,6,

        11,9,8,
        10,9,11,

        14,12,13,
        15,12,14,

        19,17,16,
        18,17,19,

        22,20,21,
        23,20,22
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

const Matrix4x4 Model::GetTransform() const
{
    return transform;
}

void Model::Tick(float frameTime)
{
    // rotate our transform
    //Matrix4x4 y = VMath::MatRotateY(45);
    //Matrix4x4 x = VMath::MatRotateX(45);
    //Matrix4x4 a = VMath::MatRotateY(frameTime );
    //transform = VMath::MatrixMultiply(x, y);

    transform = UITypes::Matrix4x4();
}