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

const Matrix4x4 Model::GetTransform() const
{
    //Matrix4x4 transform;
    // start with just the identity matrix for now.

    return transform;
}

void Model::Tick(float frameTime)
{
    // rotate our transform
    Matrix4x4 a = VMath::MatRotateY(frameTime / 1000.f + 90.f);
    Matrix4x4 b = VMath::MatRotateX(frameTime / 1000.f + 180.f);
    Matrix4x4 c = VMath::MatRotateZ(frameTime / 1000.f + 270.f);

    transform = VMath::MatrixMultiply(a, VMath::MatrixMultiply(b, c));

    // scale
    /*float scaleAmt = sinf(frameTime / 10000.f) + 0.1f;

    Matrix4x4 s(scaleAmt, 0.f, 0.f, 0.f, 0.f, scaleAmt, 0.f, 0.f, 0.f, 0.f, scaleAmt, 0.f, 0.f, 0.f, 0.f, 1.f);
    transform = VMath::MatrixMultiply(transform, s);
*/

    // translate.
    float moveXAmt = sinf(frameTime / 1000.f) * 4.f;
    float moveYAmt = cosf(frameTime / 1000.f) * 4.f;
    Matrix4x4 t(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, moveXAmt, moveYAmt, moveXAmt, 1.f);
    transform = VMath::MatrixMultiply(transform, t);

}