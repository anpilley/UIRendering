#pragma once

#define PI_ON_2 1.57079633f
#define PI_ON_4 0.785398163f

namespace VMath
{
    inline float Magnitude(const UITypes::Vector3& vect)
    {
        float magsq = vect.x * vect.x + vect.y * vect.y + vect.z * vect.z;
        float mag = sqrtf(magsq); // math.h
        return mag;
    }

    inline UITypes::Vector3 Normalize(const UITypes::Vector3& vect)
    {
        // vect / magnitude(vect)
        float mag = Magnitude(vect);

        return UITypes::Vector3(vect.x / mag, vect.y / mag, vect.z / mag);
    }

    inline UITypes::Vector3 Vector3Cross(const UITypes::Vector3& v1, const UITypes::Vector3& v2)
    {
        float x = v1.y*v2.z - v1.z*v2.y;
        float y = v1.z*v2.x - v1.x*v2.z;
        float z = v1.x*v2.y - v1.y*v2.x;

        return UITypes::Vector3(x, y, z);
    }

    inline float Vector3Dot(const UITypes::Vector3& v1, const UITypes::Vector3& v2)
    {
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    inline UITypes::Matrix4x4 Transpose(const UITypes::Matrix4x4& M)
    {
        UITypes::Matrix4x4 T;
        T.m11 = M.m11; T.m12 = M.m21; T.m13 = M.m31; T.m14 = M.m41;
        T.m21 = M.m12; T.m22 = M.m22; T.m23 = M.m32; T.m24 = M.m42;
        T.m31 = M.m13; T.m32 = M.m23; T.m33 = M.m33; T.m34 = M.m43;
        T.m41 = M.m14; T.m42 = M.m24; T.m43 = M.m34; T.m44 = M.m44;
        return T;
    }

    inline UITypes::Matrix4x4 MatrixMultiply(const UITypes::Matrix4x4& A, const UITypes::Matrix4x4& B)
    {
        UITypes::Matrix4x4 R;
        R.m11 = A.m11 * B.m11 + A.m12 * B.m21 + A.m13 * B.m31 + A.m14 * B.m41;
        R.m12 = A.m11 * B.m12 + A.m12 * B.m22 + A.m13 * B.m32 + A.m14 * B.m42;
        R.m13 = A.m11 * B.m13 + A.m12 * B.m23 + A.m13 * B.m33 + A.m14 * B.m43;
        R.m14 = A.m11 * B.m14 + A.m12 * B.m24 + A.m13 * B.m34 + A.m14 * B.m44;

        R.m21 = A.m21 * B.m11 + A.m22 * B.m21 + A.m23 * B.m31 + A.m24 * B.m41;
        R.m22 = A.m21 * B.m12 + A.m22 * B.m22 + A.m23 * B.m32 + A.m24 * B.m42;
        R.m23 = A.m21 * B.m13 + A.m22 * B.m23 + A.m23 * B.m33 + A.m24 * B.m43;
        R.m24 = A.m21 * B.m14 + A.m22 * B.m24 + A.m23 * B.m34 + A.m24 * B.m44;

        R.m31 = A.m31 * B.m11 + A.m32 * B.m21 + A.m33 * B.m31 + A.m34 * B.m41;
        R.m32 = A.m31 * B.m12 + A.m32 * B.m22 + A.m33 * B.m32 + A.m34 * B.m42;
        R.m33 = A.m31 * B.m13 + A.m32 * B.m23 + A.m33 * B.m33 + A.m34 * B.m43;
        R.m34 = A.m31 * B.m14 + A.m32 * B.m24 + A.m33 * B.m34 + A.m34 * B.m44;

        R.m41 = A.m41 * B.m11 + A.m42 * B.m21 + A.m43 * B.m31 + A.m44 * B.m41;
        R.m42 = A.m41 * B.m12 + A.m42 * B.m22 + A.m43 * B.m32 + A.m44 * B.m42;
        R.m43 = A.m41 * B.m13 + A.m42 * B.m23 + A.m43 * B.m33 + A.m44 * B.m43;
        R.m44 = A.m41 * B.m14 + A.m42 * B.m24 + A.m43 * B.m34 + A.m44 * B.m44;

        return R;
     }

    inline UITypes::Matrix4x4 MatRotateY(float angle)
    {
        float sineAngle = sinf(angle);
        float cosineAngle = cosf(angle);

        UITypes::Matrix4x4 a(cosineAngle, 0.f, sineAngle, 0.f,
                    0.f, 1.f, 0.f, 0.f, 
                    -sineAngle, 0.f, cosineAngle, 0.f, 
                    0.f, 0.f, 0.f, 1.f);

        return a;
    }

    inline UITypes::Matrix4x4 MatRotateX(float angle)
    {
        float sineAngle = sinf(angle);
        float cosineAngle = cosf(angle);

        UITypes::Matrix4x4 b(1.f, 0.f, 0.f, 0.f,
                    0.f, cosineAngle, -sineAngle, 0.f, 
                    0.f, sineAngle, cosineAngle, 0.f, 
                    0.f, 0.f, 0.f, 1.f);

        return b;
    }

    inline UITypes::Matrix4x4 MatRotateZ(float angle)
    {
        float sineAngle = sinf(angle);
        float cosineAngle = cosf(angle);

        UITypes::Matrix4x4 c(cosineAngle, -sineAngle, 0.f, 0.f,
                    sineAngle, cosineAngle, 0.f, 0.f, 
                    0.f, 0.f, 1.f, 0.f, 
                    0.f, 0.f, 0.f, 1.f);

        return c;
    }

    inline UITypes::Matrix4x4 MatTranslate(float x, float y, float z)
    {
        UITypes::Matrix4x4 r(1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, 0.f, 0.f, 0.f, 1.f, 0.f, x, y, z, 1.f);
        return r;
    }

    inline UITypes::Matrix4x4 MatScale(float x, float y, float z)
    {
        return UITypes::Matrix4x4(x, 0.f, 0.f, 0.f, 0.f, y, 0.f, 0.f, 0.f, 0.f, z, 0.f, 0.f, 0.f, 0.f, 1.f);
    }

    inline UITypes::Matrix4x4 LookAtLH(const UITypes::Vector4& eye, const UITypes::Vector4& at, const UITypes::Vector4& up)
    {
        // eyedir = sub (at - eye)
        UITypes::Vector3 eyedir(at.x - eye.x, at.y - eye.y, at.z - eye.z);

        // check eyedir != 0
        // check up != 0

        // r2 = normalize(eyedir)
        UITypes::Vector3 r2 = Normalize(eyedir);

        // r0 = up x R2
        UITypes::Vector3 r0 = Vector3Cross(UITypes::Vector3(up.x, up.y, up.z), r2);

        // r0 = normalize(r0)
        r0 = Normalize(r0);

        // r1 = r2 x r0
        UITypes::Vector3 r1 = Vector3Cross(r2, r0);

        // negeyepos = neg(eyepos)
        UITypes::Vector3 negeye(-1.f * eye.x, -1.f * eye.y, -1.f * eye.z);

        // d0 = r0 . negeye
        float d0 = Vector3Dot(r0, negeye);
        // d1 = r1 . negeye
        float d1 = Vector3Dot(r1, negeye);
        // d2 = r2 . negeye
        float d2 = Vector3Dot(r2, negeye);

        UITypes::Matrix4x4 lookAt;
        // M.r0 = r0.x,y,z,d0
        lookAt.m11 = r0.x; lookAt.m12 = r0.y; lookAt.m13 = r0.z; lookAt.m14 = d0;
        // M.r1 = r1.x,y,z,d1
        lookAt.m21 = r1.x; lookAt.m22 = r1.y; lookAt.m23 = r1.z; lookAt.m24 = d1;
        // M.r2 = r2.x,y,z,d2
        lookAt.m31 = r2.x; lookAt.m32 = r2.y; lookAt.m33 = r2.z; lookAt.m34 = d2;
        // M.r3 = 0,0,0,1
        lookAt.m41 = lookAt.m42 = lookAt.m43 = 0; lookAt.m44 = 1;

        // Transpose lookAt
        lookAt = Transpose(lookAt);

        return lookAt;
    }

    inline UITypes::Matrix4x4 PerspectiveFovLH(float FovAngleY, float aspect, float nearZ, float farZ)
    {
        // check nearZ != farZ

        float sinFov = sinf(0.5f * FovAngleY);
        float cosFov = cosf(0.5f * FovAngleY);

        float height = cosFov / sinFov;

        float width = height / aspect;
        float fRange = farZ / (farZ - nearZ);

        UITypes::Matrix4x4 M(width, 0.f, 0.f, 0.f,
            0.f, height, 0.f, 0.f,
            0.f, 0.f, fRange, 1.f,
            0.f, 0.f, -fRange * nearZ, 0.f);

        return M;
    }
}