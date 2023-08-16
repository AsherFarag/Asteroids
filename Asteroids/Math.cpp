#include "Math.h"
#include <cmath>

Mat4 Math::CreateScale(float a_ScaleX, float a_ScaleY)
{
    Mat4 Result = Identity;

    Result.m0 = (a_ScaleX);
    Result.m5 = (a_ScaleY);

    return Result;
}
Mat4 Math::CreateRotationZ(float a_Radians)
{
    Matrix Result = Identity;
    float RCos = std::cos(a_Radians);
    float RSin = std::sin(a_Radians);

    Result.m0 = (RCos);  Result.m4 = (RSin);
    Result.m1 = (-RSin); Result.m5 = (RCos);

    return Result;
}
Mat4 Math::CreateTranslation(float a_X, float a_Y)
{
    Matrix Result = Identity;

    Result.m2 = (a_X);
    Result.m6 = (a_Y);

    return Result;
}

Mat4 Math::Identity = Mat4{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1 };