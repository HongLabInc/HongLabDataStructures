#include "Array2D.h"

#include <algorithm>
#include <cassert>
#include <iostream>


int main()
{
	using namespace std;

	Array2D m1(3, 4);
	m1.SetValue(0, 0, 1.0f);
	m1.SetValue(0, 1, 2.0f);
	m1.SetValue(0, 2, 3.0f);
	m1.SetValue(1, 0, 0.0f);
	m1.SetValue(1, 1, 4.0f);
	m1.SetValue(1, 2, 5.0f);
	m1.SetValue(2, 3, 7.0f);

	m1.Print();

	cout << endl;

	Array2D add = m1.Add(m1); // 자기 자신과 더하기
	add.Print();

	cout << endl;

	Array2D tr = m1.Transpose(); // 전치행렬
	tr.Print();

	return 0;
}

