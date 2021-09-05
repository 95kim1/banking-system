/*
 * 파일이름: String.cpp
 * 작성자: sh.kim
 * 업데이트 정보: [2021, 09, 05] 파일버전 0.1
 */
 
#include "String.h"

/*
 * 클래스명: String
 * 유형: String class
 */

// 입출력 연산자 (전역 함수 기반) 
std::ostream& operator<<(std::ostream& cout, const String& str)
{
	cout << str.GetStr();
	return cout;
}
std::istream& operator>>(std::istream& cin, const String& str)
{
	cin >> str.GetStr();
	return cin;
}

// + 연산자 (전역 함수 기반) 
String operator+(const char* str1, const String& str2)
{
	int i;
	int size1;
	int size2 = str2.GetSize();

	String s(str1);
	
	size1 = s.GetSize();
	
	s.Resize(size1 + size2 + 1);
	std::cout << s << std::endl;
	for (i = 0; i < size2; i++)
	{
		s.PushBack(str2[i]);
	}
	std::cout << s <<  "--" << std::endl;
	return s;
}

// 비교연산자 (전역 함수 기반) 
bool operator==(const char* str1, const String& str2)
{
	if (strcmp(str1, str2.GetStr()) == 0)
		return true;
	return false;
}

// 디폴트 생성자 
String::String()
	: mSize(0)
	, mCapacity(1)
{
	mStr = new char[1];
	mStr[0] = '\0';
}
String::String(const char* str)
	: mSize(strlen(str))
	, mCapacity(mSize+1)
{	
	int i;
	mStr = new char[mCapacity];

	for (i = 0; i <= mSize; i++)
	{
		mStr[i] = str[i];
	}
}

// 복사 생성자 
String::String(const String& str)
	: mSize(str.mSize)
	, mCapacity(str.mCapacity)
{
	int i;
	mStr = new char[mCapacity];
	
	for (i = 0; i <= mSize; i++)
	{
		mStr[i] = str.mStr[i];
	}
}

//3. 대입연산자
String& String::operator=(const String& str)
{
	int i;
	
	if (mCapacity <= str.mSize)
	{
		Resize(str.mSize + 1);
	}
	
	mSize = str.mSize;
	
	for (i = 0; i <= mSize; i++)
	{
		mStr[i] = str.mStr[i];
	}
	
	return *this;
}
String& String::operator=(const char* str)
{
	int i;
	int size = strlen(str);
	
	if (mCapacity <= size)
	{
		Resize(size + 1);
	}
	
	mSize = size;
	
	for (i = 0; i <= mSize; i++)
	{
		mStr[i] = str[i];
	}
	
	return *this;
}

// 배열 첨자 연산자 
char& String::operator[](int index)
{
	if (index < -mSize || mSize < index)
	{
		std::cout << "index error" << std::endl;
		exit(1);
	}
	
	if (index < 0)
	{
		index += mSize;	
	}
	
	return mStr[index];
}
char& String::operator[](int index) const
{
	if (index < -mSize || mSize < index)
	{
		std::cout << "index error" << std::endl;
		exit(1);
	}
	
	if (index < 0)
	{
		index += mSize;	
	}
	
	return mStr[index];
}

// + 연산자
String String::operator+(const String& str)
{
	int i;
	
	String s(*this);
	Resize(s.mSize + str.mCapacity);
	
	for (i = 0; i < str.mSize; i++)
	{
		s.mStr[s.mSize++] = str.mStr[i];
	}
	s.mStr[s.mSize] = '\0';
	
	return s;
}
String String::operator+(const char* str)
{
	int i;
	int size = strlen(str);
	
	String s(*this);
	Resize(s.mCapacity + size);
	
	for (i = 0; i < size; i++)
	{
		s.mStr[s.mSize++] = str[i];
	}
	s.mStr[s.mSize] = '\0';
	
	return s;
}

// += 연산자
String& String::operator+=(const String& str)
{
	int i = mSize;	// (*this)'s index
	int j;			// str's index
	
	mSize += str.mSize;
	
	if (mCapacity <= mSize)
	{
		Resize(mSize + 1);
	}
	
	for (j = 0; j <= str.mSize; j++, i++)
	{
		mStr[i] = str.mStr[j];
	}
	
	return *this;
}
String& String::operator+=(const char* str)
{
	int i = mSize;	// (*this)'s index
	int j;			// str's index
	int size = strlen(str);
	
	mSize += size;
	
	if (mCapacity <= mSize)
	{
		Resize(mSize + 1);
	}
	
	for (j = 0; j <= size; j++, i++)
	{
		mStr[i] = str[j];
	}
	
	return *this;
}

// 비교 연산자 
bool String::operator==(const String& str)
{
	if (strcmp(mStr, str.mStr) == 0)
		return true;
	return false;
}
bool String::operator==(const char* str)
{
	if (strcmp(mStr, str) == 0)
		return true;
	return false;
}

// Resize capacity of string
void String::Resize(const int capacity)
{
	int i;
	
	if (capacity == mCapacity || capacity < mSize)
	{
		return;
	}
	
	char * tmp = new char[capacity];
	mCapacity = capacity;
	
	for (i = 0; i <= mSize; i++)
	{
		tmp[i] = mStr[i];
	}
	
	delete mStr;
	mStr = tmp;
}

// insert a character at the last position
void String::PushBack(const char& ch)
{
	if (mSize == mCapacity)
	{
		Resize(mCapacity+mCapacity);
	}
	
	mStr[mSize++] = ch;
	mStr[mSize] = '\0';
}

// 소멸자 
String::~String()
{
	delete mStr;
}

