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

        const UITypes::VArray<SimpleVertex>& GetVertexData();
        const UITypes::VArray<UINT32>& GetIndexData();
    private:
        UITypes::Matrix4x4 position;
        
        UITypes::VArray<SimpleVertex> vertices;
        UITypes::VArray<UINT32> indexes;
        
    };

}