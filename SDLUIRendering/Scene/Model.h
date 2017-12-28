#pragma once
// model placement data for a scene

namespace Scene
{
    class Model
    {
    public:
        Model();
        ~Model();

        virtual void Initialize();

        const UITypes::VArray<SimpleVertex>& GetVertexData() const;
        const UITypes::VArray<UINT16>& GetIndexData() const;

        virtual void Tick(float frameTime);

        const UITypes::Matrix4x4 GetTransform() const;
    protected:
        UITypes::Vector3 position;
        UITypes::Vector3 rotation;
        UITypes::Vector3 scale;

        UITypes::Matrix4x4 transform;

        UITypes::VArray<SimpleVertex> vertices;
        UITypes::VArray<UINT16> indexes;
        
    };

}