#include "MyString.h"

using namespace std;

int main()
{
	// 생성자, MyString::Print()
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		str1.Print();
	}

	// Find()
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		cout << str1.Find(MyString("hell")) << endl;

		cout << "Found at " << MyString("ABCDEF").Find(MyString("A")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("AB")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("CDE")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EF")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EFG")) << endl;
		cout << "Found at " << MyString("ABCDEF").Find(MyString("EFGHIJ")) << endl;
	}

	// 복사 생성자
	{
		MyString str1("hi hay he hel hello llo ello el el o!");
		MyString str2 = str1; // MyString str2(str1);
		str2.Print();
	}

	// IsEqual()
	{
		MyString str3("Hello, World!");
		cout << boolalpha;
		cout << str3.IsEqual(MyString("Hello, World!")) << endl;
		cout << str3.IsEqual(MyString("Hay, World!")) << endl;
	}

	// Insert()
	{
		MyString str4("ABCDE");
		for (int i = 0; i <= str4.Length(); i++)
		{
			MyString str5 = str4.Insert(MyString("123"), i);
			str5.Print();
		}
	}

	// Substr()
	{
		MyString str("ABCDEFGHIJ");

		str.Substr(3, 4).Print();
	}

	// Concat()
	{
		MyString str1("Hello, ");
		MyString str2("World!");

		MyString str3 = str1.Concat(str2);

		str3.Print();
	}

	return 0;
}