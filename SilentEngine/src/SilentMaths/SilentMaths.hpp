#pragma once
namespace SilentMaths
{
    float degreesToRadians(float angle)
    {
        return (angle * 3.14159265358979323846) / 180;
    }

    float radiansToDegrees(float angle)
    {
        return (angle * 180) / 3.14159265358979323846;
    }

template<typename T>
    T dotProduct3(T v1x,T v1y,T v1z, T v2x,T v2y,T v2z,)
    {
        return v1x*v2x + v1y*v2y + v1z*v2z;
    }
}