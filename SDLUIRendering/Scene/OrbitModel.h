#pragma once

#include "Model.h"

namespace Scene
{
    class OrbitModel : public Model
    {
    public:
        OrbitModel();
        ~OrbitModel();

        virtual void Tick(float frameTime) override;

        virtual void Initialize() override;
    private:

    };

}