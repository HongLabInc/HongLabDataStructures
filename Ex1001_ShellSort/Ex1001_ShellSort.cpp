#include <iostream>
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
		cout << setw(3) << arr[i] << " ";
	cout << endl;
}

void Print(int* arr, int size, int start, int gap)
{
	for (int i = 0; i < size; i++)
	{
		if ((i - start) % gap == 0)
			cout << setw(3) << arr[i] << " ";
		else
			cout << "    ";
	}
	cout << endl;
}

void InsertionSort(int arr[], int n)
{
	for (int i = 1; i < n; i += 1)
	{
		int key = arr[i];
		int j = i;
		for (; j > 0 && arr[j - 1] > key; j -= 1)
			arr[j] = arr[j - 1];
		arr[j] = key;
	}
}

void InsertionSort(int arr[], int n, int gap) // gap 추가
{
	cout << "gap = " << gap << endl;

	for (int i = gap; i < n; i += 1)
	{
		cout << "Before : ";
		Print(arr, n, i, gap);

		// TODO:

		cout << " After : ";
		Print(arr, n, i, gap);
	}
}

void ShellSort(int arr[], int n)
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		cout << "         ";
		Print(arr, n);

		InsertionSort(arr, n, gap);
	}

	cout << "         ";
	Print(arr, n);
	cout << endl;
}

int main()
{
	int arr[] = { 99, 83, 18, 66, 7, 54, 95, 86, 47, 69, 25, 28 };
	int n = sizeof(arr) / sizeof(arr[0]);

	ShellSort(arr, n);

	// 최악 O(n^2), 평균 O(n^1.5)
}

