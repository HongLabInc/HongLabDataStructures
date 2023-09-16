#include <iostream>

#include "../shared/BinarySearchTree.h"

using namespace std;

int main()
{
	using Item = BinarySearchTree<int, char>::Item;

	BinarySearchTree<int, char> bst;

	for (int i : { 5, 3, 7, 1, 4, 6, 8 })
		//for (int i : { 9, 8, 7, 6, 5})
	{
		// bst.Insert({ i, char('A' + i) }); // 참고: C++ 문법에서는 자료형의 이름 Item 생략하고 물결괄호 초기화 가능
		bst.Insert(Item{ i, char('A' + i) });
		bst.Print2D();
	}

	bst.Insert({ 6, 'Z' }); // 키 값이 같으면 덮어쓴다.
	bst.Print2D();

	bst.Inorder(); // key에 대해 정렬된 순서로 출력

	// 탐색
	cout << bst.RecurGet(5)->value << endl; // if(bst.RecurGet(5)) cout << bst.RecurGet(5)->value << endl;
	cout << bst.RecurGet(3)->value << endl;
	cout << bst.RecurGet(7)->value << endl;
	cout << bst.RecurGet(1)->value << endl;
	cout << bst.RecurGet(4)->value << endl;

	bst.Remove(999); // 없는 키에대해 삭제
	bst.Print2D();

	for (int i : {5, 4, 7, 3})
	{
		bst.Remove(i);
		bst.Print2D();
	}

	return 0;
}
