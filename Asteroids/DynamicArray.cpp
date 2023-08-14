#include "DynamicArray.h"

// Constructors / Destructors
    // --------------------------------------------------------

template <class T>
DynamicArray<T>::DynamicArray()
{
    m_Count = 0;
    m_Data = new T[m_Count];
    for (int i = 0; i < m_Count; i++)
        m_Data[i] = 0;
}

template <class T>
DynamicArray<T>::~DynamicArray()
{
    delete[] m_Data;
}

// General Operations
// --------------------------------------------------------

template <class T>
void DynamicArray<T>::Add(T a_Value)
{
    T* tmp = new T[m_Count];

    for (int i = 0; i < m_Count; i++)
    {
        tmp[i] = m_Data[i];
    }

    m_Count++;

    delete[] m_Data;
    m_Data = tmp;

    m_Data[m_Count - 1] = a_Value;
}

template <class T>
bool DynamicArray<T>::Remove(T a_Value)     // === UNFINISHED ===
{
    T* tmp = new T[m_Count];

    for (int i = 0; i < m_Count; i++)
    {
        tmp[i] = m_Data[i];
    }
}

template <class T>
bool DynamicArray<T>::IsEmpty()
{
    return m_Count == 0;
}

template <class T>
int DynamicArray<T>::Size()
{
    return m_Count;
}

// Operator Overloads
// --------------------------------------------------------

template <class T>
T& DynamicArray<T>::operator[](const int index)
{
    return m_Data[index];
}