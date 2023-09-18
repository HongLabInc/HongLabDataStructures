#include <iostream>
#include <string> // std::string

using namespace std;

template<typename K, typename V>
class HashTable
{
public:
	struct Item
	{
		K key = K();
		V value = V();
	};

	HashTable(const int& cap = 8)
	{
		capacity_ = cap;
		table_ = new Item[capacity_];
	}

	~HashTable()
	{
		delete[] table_;
	}

	void Insert(const Item& item)
	{
		// TODO:

		size_t index = item.key; // 키를 인덱스로 사용
		table_[index] = item;
	}

	V Get(const K& key)
	{
		// TODO:

		size_t index = key;
		return table_[index].value;
	}

	// 정수 -> 해쉬값
	size_t HashFunc(const int& key)
	{
		// TODO:

		return key;
	}

	// 문자열을 정수 인덱스(해쉬값)로 변환
	// Horner's method
	//size_t HashFunc(const string& s)
	//{
	//  return TODO:
	//}

	void Print()
	{
		for (int i = 0; i < capacity_; i++)
			cout << i << " : " << table_[i].key << " " << table_[i].value << endl;
		cout << endl;
	}

private:
	Item* table_ = nullptr;
	int capacity_ = 0;
};

int main()
{
	// 키: int, 값: int 인 경우
	// 키의 범위가 아주 크고 아이템의 개수는 적을 경우
	{
		using Item = HashTable<int, int>::Item;

		HashTable<int, int> h(8);

		h.Insert(Item{ 123, 456 });

		h.Print();

		cout << "Get 123 " << h.Get(123) << endl;

		h.Insert(Item{ 1211, 999 }); // 충돌!

		h.Print();
	}

	// 키: std::string, 값: int
	//{
	//	using Item = HashTable<string, int>::Item;

	//	HashTable<string, int> h(8);

	//	h.Insert(Item{ "Apple", 1 });
	//	h.Insert(Item{ "Orange", 2 });
	//	h.Insert(Item{ "Mandarin", 4 });

	//	h.Print();

	//	cout << "Apple " << h.Get("Apple") << endl;
	//	cout << "Orange " << h.Get("Orange") << endl;
	//	cout << endl;

	//	h.Print();

	//	h.Insert(Item{ "Pineapple", 5 });

	//	h.Print(); // 충돌!

	//	cout << "Apple " << h.Get("Apple") << endl;
	//	cout << "Orange " << h.Get("Orange") << endl;
	//	cout << "Pineapple " << h.Get("Pineapple") << endl;
	//	cout << endl;
	//}

	return 0;
}