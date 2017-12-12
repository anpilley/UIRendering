#pragma once
// model placement data for a scene

namespace Scene
{
    class Model
    {
    public:
        Model();
        ~Model();

        void Initialize();

        const UITypes::VArray<SimpleVertex>& GetVertexData() const;
        const UITypes::VArray<UINT16>& GetIndexData() const;

        void Tick(float timeSpan);

        UITypes::Matrix4x4 GetTransform() const;
    private:
        UITypes::Vector3 position;
        UITypes::Vector3 rotation;
        UITypes::Vector3 scale;

        
        UITypes::VArray<SimpleVertex> vertices;
        UITypes::VArray<UINT16> indexes;
        
    };

}