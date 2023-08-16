
#include "Transformation.h"


// ===== Constructors =====
Transformation::Transformation()
{

}

Transformation::Transformation(Transformation* a_Parent)
{

}

Transformation::~Transformation()
{

}



// ===== Heirarchies =====
Transformation* m_Parent;
std::vector<Transformation*> m_Children;



// ===== General Functions =====
void Transformation::UpdateTransform(bool a_Force) const
{
	if (m_Dirty || a_Force)
	{
		Mat4 Translation = Math::CreateTranslation(m_Position.x, m_Position.y);
		Mat4 Rotation = Math::CreateRotationZ(m_Rotation);
		Mat4 Scale = Math::CreateScale(m_Scale.x, m_Scale.y);

		m_LocalMatrix = MatrixMultiply(MatrixMultiply(Scale, Rotation), Translation);
		m_GlobalMatrix = (m_Parent == nullptr ? m_LocalMatrix : MatrixMultiply(m_Parent->m_GlobalMatrix, m_LocalMatrix));
		m_Dirty = false;

		for (int i = 0; i < m_Children.size(); i++)
			 m_Children[i]->UpdateTransform(true);
	}
}



#pragma region Properties

// ===== Global =====
const Mat4& Transformation::GetGlobalMatrix() const
{
	UpdateTransform(false);
	return m_GlobalMatrix;
}

const Vec3& Transformation::GetGlobalPosition() const
{
	UpdateTransform(false);
	return Vec3{ m_GlobalMatrix.m2, m_GlobalMatrix.m6, 0.0f };
}

float Transformation::GetGlobalRotation() const
{
	UpdateTransform(false);							// Will Update this Transform if it is Dirty
	Mat4 TempGlobal = m_GlobalMatrix;    // Creates a Copy of the Global Matrix
	TempGlobal.m2 = 0; TempGlobal.m6 = 0; // Sets the Translation to 0 for Both X and Y

	Vec3 MagnitudeVector = Vec3{ TempGlobal.m0, TempGlobal.m4, 0.0f };
	float XMagnitude = Vector3Length(MagnitudeVector);		        // Calculates the Scale of the First Row in Temp Global 
	TempGlobal.m0 /= XMagnitude; TempGlobal.m4 /= XMagnitude; // Seperates the Rotation of m00 and m01 from the TempGlobal by Dividing with the Scale

	return (float)std::atan2(TempGlobal.m0, TempGlobal.m4);
}

const Vec3& Transformation::GetGlobalScale() const
{
	UpdateTransform(false);							// Will Update this Transform if it is Dirty
	Mat4 TempGlobal = m_GlobalMatrix;    // Creates a Copy of the Global Matrix
	TempGlobal.m0 = 0; TempGlobal.m4 = 0; // Sets the Translation to 0 for Both X and Y

	float XMagnitude = Vector3Length( Vec3{TempGlobal.m0, TempGlobal.m4, 0.0f } ); // Calculates the Scale of the First Row in Temp Global 
	float YMagnitude = Vector3Length(Vec3{ TempGlobal.m1, TempGlobal.m5 }); // Calculates the Scale of the Second Row in Temp Global 

	return Vec3{ XMagnitude, YMagnitude, 0.0f }; // Returns the Scale as a Vector3
}



// ===== Local Getters =====
const Mat4& Transformation::GetLocalMatrix() const
{
	UpdateTransform(false); // Will Update this Transform if it is Dirty
	return m_LocalMatrix;
}

const Vec3& Transformation::GetLocalPosition() const
{
	return m_Position;
}

float Transformation::GetLocalRotation() const
{
	return m_Rotation;
}

const Vec3& Transformation::GetLocalScale() const
{
	return m_Scale;
}



// ===== Local Setters =====
void Transformation::SetLocalPosition(const Vec3& a_Value)
{
	m_Position = a_Value;
	m_Dirty = true;
}

void Transformation::SetLocalRotation(float a_Value)
{
	m_Rotation = a_Value;
	m_Dirty = true;
}

void Transformation::SetLocalScale(const Vec3& a_Value)
{
	m_Scale = a_Value;
	m_Dirty = true;
}


void Transformation::AddLocalPosition(const Vec3& a_Value)
{
	m_Position = Vector3Add(m_Position, a_Value);
	m_Dirty = true;
}
void Transformation::AddLocalRotation(float a_Value)
{
	m_Rotation += a_Value;
	m_Dirty = true;
}
#pragma endregion