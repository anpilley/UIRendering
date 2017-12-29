#pragma once

#include "VTypes.h"

struct SimpleVertex
{
    struct SimpleVertex()
    {
        Pos = UITypes::Vector3::Zero;
        Norm = UITypes::Vector3::Zero;
    }
    struct SimpleVertex(UITypes::Vector3 pos, UITypes::Vector3 normal)
    {
        Pos = pos;
        Norm = normal;
    }
    UITypes::Vector3 Pos;
    UITypes::Vector3 Norm;
};