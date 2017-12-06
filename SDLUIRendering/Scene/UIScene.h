#pragma once

namespace Scene
{

    class UIScene
    {
    public:
        UIScene();
        ~UIScene();

    private:
        UITypes::Matrix4x4 projection;
        UITypes::Matrix4x4 view;

        UITypes::VArray<Model> models;
    };
}