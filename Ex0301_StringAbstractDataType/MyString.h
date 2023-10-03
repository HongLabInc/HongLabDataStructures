#pragma once

#include <iostream>
#include <algorithm> // swap
#include <cassert>

// Abstract Data Type 개념 소개
// 보충: 원래 ADT는 특정 언어에 종속되는 개념은 아닙니다.

/* Horowitz 교재
An abstract data type (ADT) is a data type
that is organized in such a way that the specification of the operations
on the objects is separated from the representation of the objects and
the implementation of the operations.
*/

/*

class MyArray // 공부용은 이름앞에 My를 붙여서 혼동 방지
{
public:
	MyArray(int size);

	~MyArray(); // ADT라기 보다는 언어 특성

	float Retrieve(int i);

	void Store(int i, float x);

private:
	float* arr_ = 0;
	int size_ = 0;
}

*/

class MyString
{
public:
	MyString();						// 비어 있는 MyString() 생성
	MyString(const char* init);		// 맨 뒤에 널 캐릭터'\0'가 들어 있는 문자열로부터 초기화
	MyString(const MyString& str);	// MyString의 다른 instance로부터 초기화
	~MyString();

	bool IsEmpty();
	bool IsEqual(const MyString& str);
	int Length();
	void Resize(int new_size);

	MyString Substr(int start, int num);	// 인덱스 start위치의 글자부터 num개의 글자로 새로운 문자열 만들기
	MyString Concat(MyString app_str);		// 뒤에 덧붙인 새로운 문자열 반환 (append)
	MyString Insert(MyString t, int start); // 중간에 삽입

	int Find(MyString pat);

	void Print();

private:
	char* str_ = nullptr; // 마지막에 '\0' 없음
	int size_ = 0; // 글자 수
};
