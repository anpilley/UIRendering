#pragma once

#include "VTypes.h"

struct SimpleVertex
{
    struct SimpleVertex()
    {
        Pos = UITypes::Vector3::Zero;
        Color = UITypes::Vector4::Zero;
    }
    struct SimpleVertex(UITypes::Vector3 pos, UITypes::Vector4 color)
    {
        Pos = pos;
        Color = color;
    }
    UITypes::Vector3 Pos;
    UITypes::Vector4 Color;
};