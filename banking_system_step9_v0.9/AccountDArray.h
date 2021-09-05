#ifndef __ACCOUNT_D_ARRAY_H__
#define __ACCOUNT_D_ARRAY_H__

/*
 * 파일이름: AccountDArray.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 04] 파일버전 0.1
 */
 
#include "CommonDeclare.h"
#include "Account.h"
 
typedef Account* ACC_PTR;
 
/*
 * 클래스명: AccountDArray
 * 유형: Array class 
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
