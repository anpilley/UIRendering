#include "..\stdafx.h"
#include "../Types/RenderTypes.h"
#include "Model.h"

using namespace Scene;

Model::Model() :
    vertices(8),
    indexes(8 * 3)
{

}

Model::~Model()
{

}

void Model::Initialize()
{
    SimpleVertex initVertices[] =
    {
        { UITypes::Vector3(-1.0f, 1.0f, -1.0f), UITypes::Vector4(0.0f, 0.0f, 1.0f, 1.0f) },
        { UITypes::Vector3(1.0f, 1.0f, -1.0f), UITypes::Vector4(0.0f, 1.0f, 0.0f, 1.0f) },
        { UITypes::Vector3(1.0f, 1.0f, 1.0f), UITypes::Vector4(0.0f, 1.0f, 1.0f, 1.0f) },
        { UITypes::Vector3(-1.0f, 1.0f, 1.0f), UITypes::Vector4(1.0f, 0.0f, 0.0f, 1.0f) },
        { UITypes::Vector3(-1.0f, -1.0f, -1.0f), UITypes::Vector4(1.0f, 0.0f, 1.0f, 1.0f) },
        { UITypes::Vector3(1.0f, -1.0f, -1.0f), UITypes::Vector4(1.0f, 1.0f, 0.0f, 1.0f) },
        { UITypes::Vector3(1.0f, -1.0f, 1.0f), UITypes::Vector4(1.0f, 1.0f, 1.0f, 1.0f) },
        { UITypes::Vector3(-1.0f, -1.0f, 1.0f), UITypes::Vector4(0.0f, 0.0f, 0.0f, 1.0f) },
    };

    for (int i = 0; i < sizeof(initVertices); i++)
    {
        this->vertices[i] = initVertices[i];
    }

    int initIndices[] =
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

    for (int i = 0; i < sizeof(initIndices); i++)
    {
        this->indexes[i] = initIndices[i];
    }
}

const UITypes::VArray<SimpleVertex>& Model::GetVertexData()
{
    return this->vertices;
}

const UITypes::VArray<UINT32>& Model::GetIndexData()
{
    return this->indexes;
}