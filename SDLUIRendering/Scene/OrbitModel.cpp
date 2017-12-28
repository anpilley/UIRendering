#include "..\stdafx.h"
#include "../Types/RenderTypes.h"
#include "OrbitModel.h"

using namespace Scene;
using namespace UITypes;

OrbitModel::OrbitModel() 
{
    
}

OrbitModel::~OrbitModel()
{

}

void OrbitModel::Initialize()
{
    Model::Initialize();

}

void OrbitModel::Tick(float frameTime)
{
    Matrix4x4 a;
    transform = a;


    Matrix4x4 spin = VMath::MatRotateZ(-frameTime);
    Matrix4x4 orbit = VMath::MatRotateY(-frameTime * 2.0f);
    Matrix4x4 translate = VMath::MatTranslate(-4.0f, 0.f, 0.f);
    Matrix4x4 scale = VMath::MatScale(0.3f, 0.3f, 0.3f);

    // scale, spin, translate, orbit
    transform = VMath::MatrixMultiply(scale, VMath::MatrixMultiply(spin, VMath::MatrixMultiply(translate, orbit)));
}