#ifndef __ACCOUNT_D_ARRAY_H__
#define __ACCOUNT_D_ARRAY_H__

/*
 * �����̸�: AccountDArray.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 04] ���Ϲ��� 0.1
 */
 
#include "CommonDeclare.h"
#include "Account.h"
 
typedef Account* ACC_PTR;
 
/*
 * Ŭ������: AccountDArray
 * ����: Array class 
 */
 
class BoundCheckPtrDArray
{
	ACC_PTR * mAccArr;
	int mSize;
	int mCapacity;
	
	BoundCheckPtrDArray(const BoundCheckPtrDArray& arr) {}
	BoundCheckPtrDArray& operator=(const BoundCheckPtrDArray& arr) {}
public:
	BoundCheckPtrDArray(int capacity=MAX_ACCOUNT);

	ACC_PTR& operator[](int index);
	ACC_PTR operator[](int index) const;
	
	int GetSize() const;
	int GetCapacity() const;
	
	void ResizeArray(int capacity);
	
	void PushBack(ACC_PTR data);
	bool DeleteData(ACC_PTR data);
	
	~BoundCheckPtrDArray();
};

#endif
