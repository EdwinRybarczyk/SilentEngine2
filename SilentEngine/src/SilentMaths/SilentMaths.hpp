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
}