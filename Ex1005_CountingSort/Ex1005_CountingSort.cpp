#include <iostream>
#include "../shared/Queue.h"
#include <iomanip>

using namespace std;

bool CheckSorted(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}

	return true;
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << setw(4) << arr[i] << " ";
	cout << endl;
}

int GetMax(int arr[], int n)
{
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

int main()
{
	//int arr[] = { 170, 45, 75, 90, 802, 24, 2, 66 };
	int arr[] = { 1, 0, 2, 3, 4, 2, 3, 1, 2 }; // 0이 1개, 1이 2개, 2가 3개, 4가 1개
	int n = sizeof(arr) / sizeof(arr[0]);

	Print(arr, n);

	// Queue<int> queues[10]; // 기본 동기: 큐를 사용하지 말자! 
	int count[10 + 1];        // 각각의 큐에 몇 개가 저장될 것인지 + 마지막 하나는 가장 큰 위치를 표시용
	int* temp = new int[n];   // 임시 저장 메모리, 큐10개가 메모리를 따로따로 사용하는 대신에 하나의 큰 메모리 하나만 사용
	                          // 대신에 큐가 사용할 최대 각각의 크기를 미리 알아야 한다

	int m = GetMax(arr, n); // 가장 큰 자리수를 찾기 위해서

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		for (int i = 0; i < n; i++)
		{
			temp[i] = arr[i]; // 단순 복사
			arr[i] = -1;      // 디버깅 편의
		}

		for (int i = 0; i < 10 + 1; i++)
			count[i] = 0; // 초기화

		for (int i = 0; i < n; i++)
			// queues[(arr[i] / exp) % 10].Enqueue(arr[i]); // 큐에 저장하지 않고
			count[temp[i] / exp % 10] += 1;                 // 각각의 큐에 몇 개가 저장될 것인지만 기록

		cout << "Count1: ";
		Print(count, 11);

		// 큐 10개가 메모리를 따로따로 갖지 않고 한 줄로 쭉 나열되어 있다면 각각의 큐의 시작 위치는?
		for (int i = 1; i < 10 + 1; i++)
		{
			// TODO: 이 부분을 어렵게 생각하시는 분들이 많네요. 
			//       Count1: 과 Count2: 의 출력을 보고 맞춰보세요.
		}

		cout << "Count2: ";
		Print(count, 11);

		for (int i = n - 1; i >= 0; i--) // Stable sort로 구현하기 위해 역순으로 진행
		{
			cout << temp[i] << endl; // 자기 자리를 찾아갈 값

			// TODO: count[temp[i] / exp % 10] 업데이트 (아주 간단해요)
			arr[count[temp[i] / exp % 10]] = temp[i];

			cout << " Count: ";
			Print(count, 11);

			cout << "Output: ";
			Print(arr, n);
		}

		Print(arr, n);
	}

	delete[] temp;

	return 0;
}

/* 이해를 돕기 위해 실제 예상 출력에 추가한 부분이 있습니다.

 정렬전:  1    0    2    3    4    2    3    1    2

 radix:  0    1    2    3    4    5    6    7    8    9
Count1:  1    2    3    2    1    0    0    0    0    0    0   // 0이 1개, 1이 2개, 2가 3개, 3이 2개, 4가 1개

 radix : 0    1    2    3    4    5    6    7    8    9
Count2 : 1    3    6    8    9    9    9    9    9    9    9   // 0 이하가 1개, 1 이하가 3개, 2 이하가 6개, 3 이하가 8개, 4 이하가 9개, 뒷부분은 총 9개라는 의미

기수정렬의 큐 사용에 비유하면,
queues[0]이 인덱스 0에서 1-1 = 0, (0이 1개)
queues[1]이 인덱스 1에서 3-1 = 2, (1이 2개)
queues[2]이 인덱스 3에서 6-1 = 5, (2가 3개)
queues[3]이 인덱스 6에서 8-1 = 7, (3이 2개)
queues[4]이 인덱스 8에서 9-1 = 8, (4가 1개)
에 대응하는 것처럼 생각할 수 있습니다.

2 <- 정렬전 배열의 가장 오른쪽 끝
 Count:    1    3    5    8    9    9    9    9    9    9    9
Output:   -1   -1   -1   -1   -1    2   -1   -1   -1           // <- 2가 자기 위치에 복사됨 (이 위치를 어떻게 찾는지가 포인트입니다)
1
 Count:    1    2    5    8    9    9    9    9    9    9    9
Output:   -1   -1    1   -1   -1    2   -1   -1   -1           // <- 1이 자기 위치에 복사됨
3
 Count:    1    2    5    7    9    9    9    9    9    9    9
Output:   -1   -1    1   -1   -1    2   -1    3   -1           // <- 3이 자기 위치에 복사됨
2
 Count:    1    2    4    7    9    9    9    9    9    9    9
Output:   -1   -1    1   -1    2    2   -1    3   -1
4
 Count:    1    2    4    7    8    9    9    9    9    9    9
Output:   -1   -1    1   -1    2    2   -1    3    4
3
 Count:    1    2    4    6    8    9    9    9    9    9    9
Output:   -1   -1    1   -1    2    2    3    3    4
2
 Count:    1    2    3    6    8    9    9    9    9    9    9
Output:   -1   -1    1    2    2    2    3    3    4
0
 Count:    0    2    3    6    8    9    9    9    9    9    9
Output:    0   -1    1    2    2    2    3    3    4
1
 Count:    0    1    3    6    8    9    9    9    9    9    9
Output:    0    1    1    2    2    2    3    3    4

 정렬후:    0    1    1    2    2    2    3    3    4
*/

/*
170 45 75 90 802 24 2 66
170 90 802 2 24 45 75 66
802 2 24 45 66 170 75 90
2 24 45 66 75 90 170 802
*/