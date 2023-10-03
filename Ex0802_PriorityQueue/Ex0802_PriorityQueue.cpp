#include <iostream>

#include "../shared/MaxHeap.h"

using namespace std;

struct Patient
{
	int severity; // <- 중증도, 정렬할 때의 1차적인 키(key)로 사용됨
	int time;	  // <- 도착시간, 정렬할 때의 2차적인 키(key)로 사용됨, 중증도가 같을 때는 먼저 온 순서
	const char* name;

	// 우선순위 관점에서 봤을 때 a >= b 인지를 반환하는 함수
	friend bool operator >= (const Patient& a, const Patient& b)
	{
		if (a.severity == b.severity) // 우선순위가 같을 때는 시간을 기준으로 다시 판단 (선착순)
			return a.time <= b.time;   // 숫자로써 time이 작은 것이 먼저 왔다는 의미니까 최종 우선순위가 더 높다.
		else
			return a.severity > b.severity; // 우선순위가 큰 쪽 기준
	}

	friend bool operator < (const Patient& a, const Patient& b)
	{
		return !(a >= b); // 앞의 ! 주의 (operator >= 활용) 
	}

	friend std::ostream& operator << (std::ostream& os, const Patient& p)
	{
		// TODO: 필요하면 구현
		return os;
	}
};

int main()
{
	// 응급실
	MaxHeap<Patient> h;

	// 우선순위가 더 높은 환자 먼저 치료
	// 더 중증인 경우(severity가 큰 경우) 우선순위가 높다.
	// 증상의 무거운 정도가 동일하다면(severity가 같다면) 먼저 온 환자 먼저 치료(time이 작은 환자 먼저)

	h.Push({ 1, 0, "Ironman" });   // 중증도 1의 Ironman 시간 0에 도착
	h.Push({ 1, 1, "Nick Fury" }); // 중증도 1의 Nick Fury 시간 1에 도착
	h.Push({ 3, 2, "Hulk" });      // 중증도 3의 Hulk 시간 2에 도착

	cout << h.Top().name << endl;  // 중증도가 높은 Hulk 먼저 치료
	h.Pop();

	cout << h.Top().name << endl;  // 중증도가 동일하지만 먼저 도착한 Ironman
	h.Pop();

	h.Push({ 2, 3, "Blue Beetle" });

	cout << h.Top().name << endl;  // 늦게 도착했지만 중증도가 높은 Blue Beetle
	h.Pop();

	cout << h.Top().name << endl;  // 마지막으로 Nick Fury
	h.Pop();

	/* 출력 예시
	Hulk
	Ironman
	Blue Beetle
	Nick Fury
	*/

	return 0;
}
