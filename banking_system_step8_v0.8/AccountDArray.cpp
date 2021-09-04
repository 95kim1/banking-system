/*
 * 파일이름: AccountDArray.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.1
 */
 
 #include "AccountDArray.h"
 
// 생성자 
BoundCheckPtrDArray::BoundCheckPtrDArray(int capacity)
	: mSize(0)
	, mCapacity(capacity)
{
	mAccArr = new ACC_PTR[capacity];
}

// 대입 연산자 
ACC_PTR& BoundCheckPtrDArray::operator[](int index)
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
	
	return mAccArr[index];	
}

// 대입 연산자 const 
ACC_PTR BoundCheckPtrDArray::operator[](int index) const
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
	
	return mAccArr[index];
}


// getters
int BoundCheckPtrDArray::GetSize() const 
{
	return mSize;
}
int BoundCheckPtrDArray::GetCapacity() const
{
	return mCapacity;
}

// Resize
void BoundCheckPtrDArray::ResizeArray(int capacity)
{
	int i;
	
	// 같은 용량으로 or 데이터 개수보다 적게 재할당 방지 
	if (capacity == mCapacity || capacity < mSize) 
	{
		return;
	}
	
	ACC_PTR * tmp = new ACC_PTR[capacity];
	
	// 메모리 공간 할당 실패 
	if (tmp == NULL)
	{
		std::cout << "failed: memory allocation" << std::endl;
		exit(1);
	}
	
	mCapacity = capacity;
	
	// 데이터 이동 
	for (i = 0; i < mSize; i++)
	{
		tmp[i] = mAccArr[i];
	}
	
	// old storage 제거 
	delete mAccArr;
	mAccArr = tmp;
}

// push back
void BoundCheckPtrDArray::PushBack(ACC_PTR data)
{
	if (mCapacity == mSize)
	{
		ResizeArray(mCapacity + mCapacity);
	}
	
	mAccArr[mSize] = data;
	mSize++;
}

// delete data
bool BoundCheckPtrDArray::DeleteData(ACC_PTR data)
{
	int i;
	int index = -1;
	
	for (i = 0; i < mSize; i++)
	{
		if (*data == *mAccArr[i])
		{
			index = i;
			break;
		}
	}
	
	if (index == -1)
	{
		return false;
	}
	
	delete mAccArr[index];
	mSize--;
	
	for (i = index; i < mSize; i++)
	{
		mAccArr[index] = mAccArr[index + 1];
	}
	
	return true;
}

// 소멸자 
BoundCheckPtrDArray::~BoundCheckPtrDArray()
{
	int i;
	
	for (i = 0; i < mSize; i++)
	{
		delete mAccArr[i];
	}
	
	delete mAccArr;
}
