#include <iostream>

#include "../shared/MaxHeap.h"

using namespace std;

int main()
{
	// 개념 설명은 트리인데 구현은 배열 (연결 표현법으로도 구현 가능)
	// 완전 이진 트리 상태를 유지

	// 부모 노드의 값이 두 자식 노드의 값 이상이어야 한다. 
	// 자식들끼리는 값의 크기 순서 무관. <- 느슨한 정렬 상태
	// 중복된 값을 여러개 넣을 수 있음

	// 배열 사용: 0번은 비워둠
	// 부모 인덱스 * 2 = 왼쪽 자식 인덱스
	// 부모 인덱스 * 2 + 1 = 오른쪽 자식 인덱스
	// 자식인덱스 / 2 = 부모 인덱스

	// 삽입: 일단 맨 마지막에 삽입한 후에 부모 노드로 올린다.
	// 삭제: 가장 마지막 값을 루트로 옮긴 후에 내려 보낸다.

	MaxHeap<int> h;

	for (auto i : { 2, 8, 5, 3, 2, 1, 9, 3, 7 })
	{
		h.Push(i);
		h.Print();
	}

	// 힙 정렬 O(nlogn), Not stable
	while (!h.IsEmpty())
	{
		cout << h.Top() << " ";
		h.Pop();
		// h.Print();
	}
	cout << endl;

	return 0;
}
