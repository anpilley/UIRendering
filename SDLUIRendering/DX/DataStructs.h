#pragma once


struct Vector4
{
    Vector4(float x, float y, float z, float a)
    {
        this->x = x;
        this->y = y;
        this->z = z;
        this->a = a;
    };

    float x;
    float y;
    float z;
    float a;
};

struct SimpleVertex
{
    DirectX::XMFLOAT3 Pos;
};