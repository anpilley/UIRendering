#pragma once

namespace UITypes
{
    struct Vector3
    {
        struct Vector3()
        {
            x = y = z = 0.f;
        }
        struct Vector3(float lx, float ly, float lz)
        {
            x = lx;
            y = ly;
            z = lz;
        }

        float x;
        float y;
        float z;

        static Vector3 Zero;
    };
    typedef struct Vector3 Vector3;

    struct Vector4
    {
        struct Vector4()
        {
            x = y = z = a = 0.f;
        }
        struct Vector4(float lx, float ly, float lz, float la)
        {
            x = lx;
            y = ly;
            z = lz;
            a = la;
        }

        float x;
        float y;
        float z;
        float a;

        static Vector4 Zero;
    };
    typedef struct Vector4 Vector4;

    // [m11, m12, m13
    //  m21, m22, m23
    //  m31, m32, m33]
    struct Matrix3x3
    {
        struct Matrix3x3()
        {
            m11 = m22 = m33 = 1;
            m12 = m13 = m21 = m23 = m31 = m32 = 0;
        };

        float m11;
        float m12;
        float m13;
        float m21;
        float m22;
        float m23;
        float m31;
        float m32;
        float m33;
    };
    typedef struct Matrix3x3 Matrix3x3;


    // [m11, m12, m13, m14
    //  m21, m22, m23, m24
    //  m31, m32, m33, m34
    //  m41, m42, m43, m44]
    struct Matrix4x4
    {
        struct Matrix4x4()
        {
            m11 = m22 = m33 = m44 = 1;
            m12 = m13 = m14 = m21 = m23 = m24 = m31 = m32 = m34 = m41 = m42 = m43 = 0;
        };

        struct Matrix4x4(float l11, float l12, float l13, float l14,
            float l21, float l22, float l23, float l24,
            float l31, float l32, float l33, float l34,
            float l41, float l42, float l43, float l44)
        {
            m11 = l11;
            m12 = l12;
            m13 = l13;
            m14 = l14;
            m21 = l21;
            m22 = l22;
            m23 = l23;
            m24 = l24;
            m31 = l31;
            m32 = l32;
            m33 = l33;
            m34 = l34;
            m41 = l41;
            m42 = l42;
            m43 = l43;
            m44 = l44;
        }

        float m11;
        float m12;
        float m13;
        float m14;
        float m21;
        float m22;
        float m23;
        float m24;
        float m31;
        float m32;
        float m33;
        float m34;
        float m41;
        float m42;
        float m43;
        float m44;
    };
    typedef struct Matrix4x4 Matrix4x4;

}
