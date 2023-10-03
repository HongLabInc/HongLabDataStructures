#include <iostream>

#include "../shared/Stack.h"

using namespace std;

Stack<char> tower[3];

void PrintTowers()
{
	cout << "Towers" << endl;
	cout << "0: ";
	tower[0].Print();
	cout << "1: ";
	tower[1].Print();
	cout << "2: ";
	tower[2].Print();
}

// 실제로 디스크를 움직여서 스택들을 업데이트
void MoveDisk(int from, int to)
{
	if (tower[from].IsEmpty())
	{
		cout << "Tower " << from << " is empty." << endl;
		exit(0); // 오류 강제 종료
	}

	auto disk = tower[from].Top();

	// 받을 타워가 비어 있으면 뭐든지 받을 수 있음
	// 알파벳 순서여야 받을 수 있음 (역순 X)
	if (!tower[to].IsEmpty() && tower[to].Top() > disk)
	{
		cout << "Cannot place " << disk << " on " << tower[to].Top() << endl;
		exit(0); // 오류 강제 종료
	}

	tower[from].Pop();
	tower[to].Push(disk);

	cout << "Move disk " << disk << " from " << from << " to " << to << endl;
	PrintTowers();
}

void RecurMoveDisks(int n, int from, int temp, int to)
{
	// TODO:
}

int main()
{
	int num_disks = 5;

	for (int i = 0; i < num_disks; i++)
		tower[0].Push('A' + i);

	PrintTowers();

	// MoveDisk(0, 2); // <- 디스크 하나만 움직이는 함수 tower 0 -> tower 2

	RecurMoveDisks(num_disks, 0, 1, 2);

	return 0;
}
