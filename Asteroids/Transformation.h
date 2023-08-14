#pragma once

#include <vector>
#include "Math.h"

class GameObject;

class Transformation
{
public:
	// ===== Constructors =====
	Transformation();
	Transformation(Transformation* a_Parent);
	~Transformation();

	// ===== Heirarchies =====
	GameObject* m_AttachedObject = nullptr;
	Transformation* m_Parent = nullptr;
	std::vector<Transformation*> m_Children;

#pragma region Properties

	// ===== Global =====
	const Mat4& GetGlobalMatrix() const;
	const Vec3& GetGlobalPosition() const;
	float	GetGlobalRotation() const;
	const Vec3& GetGlobalScale() const;

	// ===== Local Getters =====
	const Mat4& GetLocalMatrix() const;
	const Vec3& GetLocalPosition() const;
	float GetLocalRotation() const;
	const Vec3& GetLocalScale() const;

	// ===== Local Setters =====
	void SetLocalPosition(const Vec3& a_Value);
	void SetLocalRotation(float a_Value);
	void SetLocalScale(const Vec3& a_Value);

#pragma endregion

protected:
private:

	// ===== General Functions =====
	void UpdateTransform(bool Force) const;

	// ===== Members =====
	mutable Mat4 m_GlobalMatrix;
	mutable Mat4 m_LocalMatrix;
	Vec3 m_Position;
	float m_Rotation = 0;
	Vec3 m_Scale = Vec3{ 1.0f, 1.0f, 1.0f };
	mutable bool m_Dirty = true;
};