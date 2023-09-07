#include <iostream>

#include "../shared/Stack.h" // 경로 "shared" 주의

int main()
{
	using namespace std;

	// 일종의 가방(bag), 컨테이너(container)
	// LIFO(Last-In-First-Out)

	Stack<char> s;

	s.Push('A');
	s.Print();

	s.Push('B');
	s.Print();

	s.Push('C');
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();
	s.Print();

	s.Push('E');
	s.Print();

	s.Pop();
	s.Print();

	cout << "Top = " << s.Top() << endl;

	s.Pop();

	// cout << "Top = " << s.Top() << endl; // 비었을 때 Top() 불가

	// 다른 자료형의 stack도 쉽게 만들 수 있어요.
	{
		//Stack<int> int_stack;
		//int_stack.Push(123);
		//cout << int_stack.Top() << endl;
		//int_stack.Top();
	}

	// 문자열 순서 뒤집어서 출력하기 (스택 사용하기 연습)
	{
		//const char str[] = "Hello, World!";
		//const int size = sizeof(str) - 1; // 마지막 '\0' 제외

		//cout << "Input: " << str << endl;

		//Stack<char> stack;

		//// TODO:

		//cout << endl;
	}

	return 0;
}
