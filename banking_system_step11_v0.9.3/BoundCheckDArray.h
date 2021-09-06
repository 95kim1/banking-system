#ifndef __BOUND_CHECK_D_ARRAY_H__
#define __BOUND_CHECK_D_ARRAY_H__

/*
 * �����̸�: BoundCheckDArray.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.2
 */
 
/*
 * Ŭ������: BoundCheckDArray
 * ����: Array class 
 */

#include <iostream>

template <typename T>
class BoundCheckDArray
{
	T * mArr;
	int mSize;
	int mCapacity;
	
	BoundCheckDArray(const BoundCheckDArray& arr) {}
	BoundCheckDArray& operator=(const BoundCheckDArray& arr) {}
public:
	BoundCheckDArray(int capacity=1);

	T& operator[](int index);
	T operator[](int index) const;
	
	int GetSize() const;
	int GetCapacity() const;
	
	void ResizeArray(int capacity);
	
	void PushBack(T data);
	bool DeleteData(T data);
	
	~BoundCheckDArray();
};

// ������
template <typename T>
BoundCheckDArray<T>::BoundCheckDArray(int capacity)
	: mSize(0)
	, mCapacity(capacity)
{
	mArr = new T[capacity];
}

// ���� ������
template <typename T>
T& BoundCheckDArray<T>::operator[](int index)
{
	if (index < -mSize || mSize <= index)
	{
		std::cout << "index boundary error" << std::endl;
		exit(1);
	}	
	
	// array[-i] == array[mSize-i] for 0 < i <= mSize
	if (index < 0)
	{
		index += mSize;
	}
	
	return mArr[index];	
}

// ���� ������ const 
template <typename T>
T BoundCheckDArray<T>::operator[](int index) const
{
	if (index < -mSize || mSize <= index)
	{
		std::cout << "index boundary error" << std::endl;
		exit(1);
	}	
	
	if (index < 0)
	{
		index += mSize;
	}
	
	return mArr[index];
}


// getters
template <typename T>
int BoundCheckDArray<T>::GetSize() const 
{
	return mSize;
}
template <typename T>
int BoundCheckDArray<T>::GetCapacity() const
{
	return mCapacity;
}

// Resize
template <typename T>
void BoundCheckDArray<T>::ResizeArray(int capacity)
{
	int i;
	
	// ���� �뷮���� or ������ �������� ���� ���Ҵ� ���� 
	if (capacity == mCapacity || capacity < mSize) 
	{
		return;
	}
	
	T * tmp = new T[capacity];
	
	// �޸� ���� �Ҵ� ���� 
	if (tmp == NULL)
	{
		std::cout << "failed: memory allocation" << std::endl;
		exit(1);
	}
	
	mCapacity = capacity;
	
	// ������ �̵� 
	for (i = 0; i < mSize; i++)
	{
		tmp[i] = mArr[i];
	}
	
	// old storage ���� 
	delete mArr;
	mArr = tmp;
}

// push back
template <typename T>
void BoundCheckDArray<T>::PushBack(T data)
{
	if (mCapacity == mSize)
	{
		ResizeArray(mCapacity + mCapacity);
	}
	
	mArr[mSize] = data;
	mSize++;
}

// delete data
template <typename T>
bool BoundCheckDArray<T>::DeleteData(T data)
{
	int i;
	int index = -1;
	
	for (i = 0; i < mSize; i++)
	{
		if (*data == *mArr[i])
		{
			index = i;
			break;
		}
	}
	
	if (index == -1)
	{
		return false;
	}
	
	delete mArr[index];
	mSize--;
	
	for (i = index; i < mSize; i++)
	{
		mArr[index] = mArr[index + 1];
	}
	
	return true;
}

// �Ҹ���
template <typename T>
BoundCheckDArray<T>::~BoundCheckDArray()
{
	int i;
	
	for (i = 0; i < mSize; i++)
	{
		delete mArr[i];
	}
	
	delete mArr;
}

#endif
