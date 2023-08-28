#include <iostream>
#include <iomanip>      // std::setw

#include <cassert>

using namespace std;

void PrintHelper(int* arr, int n, int left, int right)
{
	cout << "[" << left << "," << right << "]" << endl;

	cout << "Indices: ";
	for (int i = left; i <= right; i++)
		cout << setw(2) << i << " ";
	cout << endl;

	cout << "Values : " << setw(2);
	for (int i = left; i <= right; i++)
		cout << setw(2) << arr[i] << " ";
	cout << endl;
}

int BinarySearch(int* arr, int n, int x) // 이진 탐색
{
	int left = 0;
	int right = n - 1;

	while (left <= right)
	{
		PrintHelper(arr, n, left, right);

		// int middle = ... ; // 정수 나누기 (버림)

		// cout << "middle " << middle << endl;

		//if ()
		//{
		//	...
		//	cout << "right " << right << endl;
		//}
		//else if ()
		//{
		//	...
		//	cout << "left " << left << endl;
		//}
		//else
		//{
		//	cout << "Found " << middle << endl;
		//	return middle;
		//}

		break; // 임시: 무한루프 방지
	}

	cout << "Not found" << endl;
	return -1; // Not found
}

int main()
{
	// 정렬된 배열 (임의의 배열 사용 가능, 여기서는 디버깅 편의를 위해 index와 같은 값)
	int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int arr[] = { 2, 4, 5, 5, 6, 8, 9, 10, 12, 13 };
	int n = sizeof(arr) / sizeof(arr[0]);

	assert(n > 0);

	// 정렬이 안된 배열은 미리 정렬

	BinarySearch(arr, n, 10);

	//for (int x = 0; x < n; x++)
	//	cout << x << " " << BinarySearch(arr, n, x) << endl;

	return 0;
}
