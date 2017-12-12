#include "../stdafx.h"
#include "..\Types\RenderTypes.h"
#include "Model.h"
#include "UIScene.h"

using namespace Scene;
using namespace UITypes;

UIScene::UIScene() :
    models(1)
{

}

UIScene::~UIScene()
{
    if (this->models[0] != nullptr)
    {
        Model * model = this->models[0];
        delete model; // why is this causing heap corruption?
        this->models[0] = nullptr;
    }
}

void UIScene::Initialize(int width, int height)
{
    // Add a model.
    models[0] = new Model();
    models[0]->Initialize();

    
    Vector4 eye(0.f, 1.f, -5.f, 0.f);
    Vector4 at(0.f, 1.f, 0.f, 0.f);
    Vector4 up(0.f, 1.f, 0.f, 0.f);

    this->view = VMath::LookAtLH(eye, at, up);

    this->projection = VMath::PerspectiveFovLH(PI_ON_2, width / (float)height, 0.01f, 100.0f);
    
}
