#pragma once

namespace Scene
{
    class UIScene
    {
    public:
        UIScene();
        ~UIScene();

        void Initialize(int width, int height);

        const UITypes::VArray<Model*>& GetModels() const
        {
            return models;
        };

        const UITypes::Matrix4x4 GetView() const
        {
            return view;
        };
        const UITypes::Matrix4x4 GetProjection() const
        {
            return projection;
        };

        void Tick(float frameTime);
    private:
        UITypes::Matrix4x4 projection;
        UITypes::Matrix4x4 view;

        UITypes::VArray<Model*> models;
    };
}