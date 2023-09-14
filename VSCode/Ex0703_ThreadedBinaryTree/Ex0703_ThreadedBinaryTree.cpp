#include <iostream>

using namespace std;

template<typename T>
class ThreadedBinaryTree
{
public:
	struct Node
	{
		T data = T();
		Node* left = nullptr; // Left child
		Node* right = nullptr; // Right child
		int right_thread = 0;
	};

	ThreadedBinaryTree(Node* root)
	{
		root_ = root;
	}

	Node* Next(Node* node)
	{
		Node* next = node->right;

		if (!next || node->right_thread) return next; // 오른쪽 링크가 쓰레드라면 바로 반환

		while (next->left) next = next->left; // Inorder 예시라서 가장 마지막 left로 이동

		return next; // (left가 없었다면 right 반환) left가 있었다면 가장 마지막 left 반환
	}

	void Inorder() { Inorder(root_); }
	void Inorder(Node* node)
	{
		while (node->left) node = node->left; // Inorder라서 가장 마지막 left로 이동

		do
		{
			cout << node->data << " "; // Visit
			node = Next(node); // 다음 노드를 찾는다
		} while (node);

		cout << endl;
	}

	/*void IterInorder() // 비교 Stack을 사용하는 Iterative Inorder()
	{
		if (!root_) return;

		Stack<Node*> s;

		Node* current = root_;
		while (current || !s.IsEmpty())
		{
			while (current)
			{
				s.Push(current);
				current = current->left;
			}

			current = s.Top();
			s.Pop();

			Visit(current);

			current = current->right;
		}
	}*/

private:
	Node* root_ = nullptr;
};

int main()
{
	using Node = ThreadedBinaryTree<int>::Node;

	Node* n1 = new Node{ 1, nullptr, nullptr }; // 물결괄호 초기값 나열 (생성자 아님)
	Node* n2 = new Node{ 2, n1, nullptr };
	Node* n3 = new Node{ 3, nullptr, nullptr };
	Node* n4 = new Node{ 4, nullptr, nullptr };
	Node* n5 = new Node{ 5, nullptr, n4 };
	Node* n6 = new Node{ 6, n2, n5 };
	n1->right = n3;

	n3->right = n2;
	n3->right_thread = 1;

	n2->right = n6;
	n2->right_thread = 1;

	ThreadedBinaryTree<int> tree(n6);

	tree.Inorder(); // 1 3 2 6 5 4

	return 0;
}

