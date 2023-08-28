#include <iostream>

using namespace std;

void Func2()
{
	cout << "This is Func2()" << endl;
}

void Func1()
{
	Func2();

	cout << "This is Func1()" << endl;

	// Func2(); // 실행 순서에 따른 결과 확인
}

void RecurFunc(int count)
{
	if (count == 0) // <- 종료 조건
		return;

	// RecurFunc(count - 1); // <- 변경

	cout << count << endl;

	RecurFunc(count - 1); // <- 변경

	// 실행 위치에 따라 결과가 달라집니다.
}

int main()
{
	// Func1(); // 이름이 다른 함수 호출

	RecurFunc(5); // 이름이 같은 함수 호출

	return 0;
}