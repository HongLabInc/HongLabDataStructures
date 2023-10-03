#include <iostream>

#include "../shared/DoublyLinkedList.h"

using namespace std;

int main()
{
	DoublyLinkedList<int> list;

	list.Print();

	list.PushFront(3);
	list.Print();

	list.PushBack(4);
	list.Print();

	list.PushFront(2);
	list.Print();

	list.PushFront(1);
	list.Print();

	list.PushBack(5);
	list.Print();

	list.Reverse();
	list.Print();

	DoublyLinkedList<int>::Node* temp = list.Find(3);
	list.InsertBack(temp, 1000);
	list.Print();

	// PopFront()/Back() 테스트
	for (int i = 0; i < 5; i++)
	{
		//list.PopFront();
		//list.Print();

		list.PopBack();
		list.Print();

		if (!list.IsEmpty())
			cout << list.Front() << " " << list.Back() << endl;
	}

	// Edge case 테스트 주의

	return 0;
}
