#pragma once
#include "raylib.h"

using Mat4 = Matrix;
using Vec2 = Vector2;
using Vec3 = Vector3;
using Vec4 = Vector4;

class Math
{
public:

	static Mat4 CreateScale(float a_ScaleX, float a_ScaleY);
	static Mat4 CreateRotationZ(float a_Radians);
	static Mat4 CreateTranslation(float a_X, float a_Y);

	static Mat4 Identity;
};

