#include <iostream>
#include <cassert> // assert()

using namespace std;

// 조언
// - 배열의 값들도 정수이고 인덱스도 정수라서 헷갈리는 것이 당연합니다. 
// - 단기 집중력이 필요한데 익숙해지셔야 합니다.

// 배열 arr에 x가 몇 번 나오는지 반환
int Count(int* arr, int n, int x);

// 배열 arr에 x가 있으면 index 반환, 없으면 -1 반환
int SequentialSearch(int* arr, int n, int x); // LinearSearch

// 정렬된 배열에서 x가 몇 번 나오는지 반환
int SortedCount(int* arr, int n, int x);
int SortedCountHelper(int* arr, int n, int x, int start); // start 사용

// 정렬할 때 사용
void InsertionSort(int* arr, int n);

void Print(int* arr, int size);

int main()
{
	// 정렬되지 않은 데이터를 가정

	int arr[] = { 8, 1, 1, 3, 2, 5, 1, 2 , 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// 복잡한 알고리즘이나 자료구조를 개발할 때는 
	// 실수할 가능성이 적은 단순한 방법을 기준으로 삼아요.

	cout << "Count 9 = " << Count(arr, n, 9) << endl;
	cout << "Count 2 = " << Count(arr, n, 2) << endl;
	cout << "Count 8 = " << Count(arr, n, 8) << endl;
	cout << "Count 1 = " << Count(arr, n, 1) << endl;
	cout << endl;

	cout << "Search 2 = " << SequentialSearch(arr, n, 2) << endl;
	cout << "Search 5 = " << SequentialSearch(arr, n, 5) << endl;
	cout << "Search 9 = " << SequentialSearch(arr, n, 9) << endl;
	cout << endl;

	InsertionSort(arr, n);

	Print(arr, n);

	cout << "Sorted Count 9 = " << SortedCount(arr, n, 9) << endl;
	cout << "Sorted Count 2 = " << SortedCount(arr, n, 2) << endl;
	cout << "Sorted Count 8 = " << SortedCount(arr, n, 8) << endl;
	cout << "Sorted Count 1 = " << SortedCount(arr, n, 1) << endl;
	cout << endl;

	return 0;
}

// 배열 arr에 x가 몇 번 나오는지 반환
int Count(int* arr, int n, int x)
{
	// TODO:

	return 0;
}

// 배열 arr에 x가 있으면 index 반환, 없으면 -1 반환
int SequentialSearch(int* arr, int n, int x)
{
	// TODO:

	return -1;
}

int SortedCountHelper(int* arr, int n, int x, int start) // start 사용
{
	// TODO: 

	return 0;
}

int SortedCount(int* arr, int n, int x)
{
	int i = SequentialSearch(arr, n, x);

	if (i >= 0)
		return SortedCountHelper(arr, n, x, i + 1) + 1;
	else
		return 0;
}

void InsertionSort(int* arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}

		arr[j + 1] = key;
	}
}

void Print(int* arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}