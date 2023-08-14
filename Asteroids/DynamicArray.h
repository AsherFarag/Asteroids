#pragma once
template <class T>
class DynamicArray
{
private:
    T* m_Data;
    int m_Count;

public:
    DynamicArray();
    ~DynamicArray();

    void Add(T value);
    bool IsEmpty();
    bool Remove(T value);
    bool RemoveAt(int index);
    int Size();

    T& operator[](const int index);
};

