/*
 * 파일이름: String.h
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.1
 */
 
#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
#include <cstring>

/*
 * 클래스명: String
 * 유형: String class
 */

class String
{
	char* mStr;
	int mSize;
	int mCapacity;
public:
	/* 생성자 */
	String();
	String(const char*);
	String(const String& str);
	
	/* getters */
	int GetSize() const {return mSize;}
	int GetCapacity() const {return mCapacity;}
	char* GetStr() const {return mStr;}
	
	/* 연산자 오버로딩 */
	 
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
	
	/* 소멸자 */
	~String();
};

// 입출력 연산자  (전역 함수 기반)
std::ostream& operator<<(std::ostream& cout, const String& str);
std::istream& operator>>(std::istream& cin, const String& str);

// + 연산자 (전역 함수 기반) 
String operator+(const char* str1, const String& str2);

// 비교연산자 (전역 함수 기반) 
bool operator==(const char* str1, const String& str2);

#endif
