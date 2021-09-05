/*
 * �����̸�: String.h
 * �ۼ���: sh.kim
 * ������Ʈ ����: [2021, 09, 05] ���Ϲ��� 0.1
 */
 
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

/*
 * Ŭ������: String
 * ����: String class
 */

class String
{
	char* mStr;
	int mSize;
	int mCapacity;
public:
	/* ������ */
	String();
	String(const char*);
	String(const String& str);
	
	/* getters */
	int GetSize() const {return mSize;}
	int GetCapacity() const {return mCapacity;}
	char* GetStr() const {return mStr;}
	
	/* ������ �����ε� */
	 
	String& operator=(const String&);
	String& operator=(const char*);
	
	char& operator[](int);
	char& operator[](int) const;
	
	String operator+(const String&);
	String operator+(const char*);
	
	String& operator+=(const String&);
	String& operator+=(const char*);
	
	bool operator==(const String&);
	bool operator==(const char*);
	
	void Resize(const int capacity);
	void PushBack(const char& ch);
	
	/* �Ҹ��� */
	~String();
};

// ����� ������  (���� �Լ� ���)
std::ostream& operator<<(std::ostream& cout, const String& str);
std::istream& operator>>(std::istream& cin, const String& str);

// + ������ (���� �Լ� ���) 
String operator+(const char* str1, const String& str2);

// �񱳿����� (���� �Լ� ���) 
bool operator==(const char* str1, const String& str2);

#endif
