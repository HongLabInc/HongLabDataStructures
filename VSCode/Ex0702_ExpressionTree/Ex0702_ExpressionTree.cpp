#include <iostream>

#include "../shared/Stack.h"
#include "../shared/Queue.h"
#include "../shared/BinaryTree.h"

using namespace std;

// Function to return precedence of operators
int Prec(char c);
void InfixToPostfix(Queue<char>& q, Queue<char>& output);
int EvalPostfix(Queue<char>& q);

class ExpressionTree : public BinaryTree<char>
{
public:
	typedef BinaryTree<char> Base;

	ExpressionTree(Node* root) : Base(root) {}

	bool IsDigit(char c)
	{
		if (c >= '0' && c <= '9') return true;
		else return false;
	}

	int Evaluate()
	{
		return Evaluate(Base::root_);
	}

	int Evaluate(Node* node)
	{
		// TODO: 트리에 저장된 수식의 결과값을 계산
		return 0;
	}

	void Infix() { Infix(root_); cout << endl; }
	void Infix(Node* node) {
		// TODO: 수식을 Infix 형식으로 출력 (괄호 포함)
	}

	void Postfix() { Postfix(root_);  cout << endl; }
	void Postfix(Node* node) {
		// TODO: 수식을 Postfix 형식으로 출력
	}

	// Infix -> postfix -> expression tree
	ExpressionTree(const char* infix)
	{
		// Infix -> Postfix (예제 재사용)
		Queue<char> q;
		for (int i = 0; infix[i] != '\0'; i++)
			q.Enqueue(infix[i]);
		cout << "  Infix: ";
		q.Print();
		Queue<char> postfix;
		InfixToPostfix(q, postfix);
		cout << "Postfix: ";
		postfix.Print();

		// Postfix -> Expression tree

		Stack<Node*> s;

		while (!postfix.IsEmpty())
		{
			char c = postfix.Front();
			postfix.Dequeue();

			if (c >= '0' && c <= '9')
			{
				// TODO:
			}
			else
			{
				// TODO:
			}
		}

		root_ = s.Top();
	}
};

int main()
{
	using Node = ExpressionTree::Node;

	// 5 + (3 - 2) * 4
	// 
	//    +
	//	/   \
	// 5     *
	//	    / \
	//	   -   4
	//	  / \
	//	 3   2

	Node* n1 = new Node{ '5', nullptr, nullptr };
	Node* n2 = new Node{ '+', nullptr, nullptr };
	Node* n3 = new Node{ '3', nullptr, nullptr };
	Node* n4 = new Node{ '-', nullptr, nullptr };
	Node* n5 = new Node{ '2', nullptr, nullptr };
	Node* n6 = new Node{ '*', nullptr, nullptr };
	Node* n7 = new Node{ '4', nullptr, nullptr };

	// +
	n2->left = n1; // 5
	n2->right = n6; // *

	// *
	n6->left = n4; // -
	n6->right = n7; // 4

	// -
	n4->left = n3; // 3
	n4->right = n5; // 2

	ExpressionTree tree(n2);

	tree.Print2D();

	// 수식 트리에 저장되어 있는 수식을 실제로 계산해서 그 결과를 출력합니다.
	cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9

	// 수식 트리에 저장되어 있는 수식을 Infix 방식으로 출력합니다.
	cout << "  Infix: ";
	tree.Infix();   // (5+((3-2)*4)) <- 출력 예시

	// 수식 트리에 저장되어 있는 수식을 Postfix 방식으로 출력합니다.
	cout << "Postfix: ";
	tree.Postfix(); // 532-4*+ <- 출력 예시

	cout << endl;

	// Infix -> Postfix -> Expression Tree
	{
		// const char infix[] = "1+(1*2+3)*4";
		const char infix[] = "(5+((3-2)*4))";

		// 생성자에서 문자열로 입력받은 수식을 내부적으로 Infix->Postfix 과정을 거쳐 트리로 저장합니다.
		ExpressionTree tree(infix);

		tree.Print2D();

		// 수식 트리에 저장되어 있는 수식을 실제로 계산해서 그 결과를 출력합니다.
		cout << "Evaluated = " << tree.Evaluate() << endl; // Evaluated = 9
	}

	return 0;
}

// Function to return precedence of operators
int Prec(char c)
{
	if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1; // '('는 우선순위가 아주 낮은 것으로 처리
}

void InfixToPostfix(Queue<char>& q, Queue<char>& output)
{
	Stack<char> s; // 우선순위가 낮은 연산을 보류하기 위한 스택

	output.SetDebugFlag(false);

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		//cout << c << endl;

		if (c >= '0' && c <= '9') // 숫자(피연산자)라면 output에 추가
			output.Enqueue(c);
		else if (c == '(') // 여는 괄호라면 스택에 추가
			s.Push(c);
		else if (c == ')') // 닫는 괄호를 만나면
		{
			// 여는 괄호 전까지를 스택에서 꺼내서 출력에 넣기
			while (s.Top() != '(')
			{
				output.Enqueue(s.Top());
				s.Pop();
			}
			s.Pop(); // 여는 괄호 제거
		}
		else // 연산자를 만나면
		{
			// 스택에서 c보다 우선순위가 높거나 같은 것들을 꺼내서 추가
			while (!s.IsEmpty() && Prec(c) <= Prec(s.Top()))
			{
				output.Enqueue(s.Top());
				s.Pop();
			}

			// c는 스택에 추가
			s.Push(c);
		}

		//cout << "Stack: ";
		//s.Print();
		//cout << "Output:";
		//output.Print();
		//cout << endl;
	}

	// 스택에 남아있는 것들을 모두 추가
	while (!s.IsEmpty())
	{
		output.Enqueue(s.Top());
		s.Pop();
	}
}

int EvalPostfix(Queue<char>& q)
{
	Stack<int> s;

	while (!q.IsEmpty())
	{
		char c = q.Front();
		q.Dequeue();

		//cout << c << endl;

		if (c != '+' && c != '-' && c != '*' && c != '/')
		{
			s.Push(c - '0'); // 입력이 연산자가 아니면 일단 저장
		}
		else
		{
			//cout << "Operator: " << c << endl;

			// 입력이 연산자이면 스택에서 꺼내서 연산에 사용
			int op2 = s.Top(); // op1, op2 순서 주의
			s.Pop();
			int op1 = s.Top();
			s.Pop();

			if (c == '+') {
				s.Push(op1 + op2);
			}
			else if (c == '-') {
				s.Push(op1 - op2);
			}
			else if (c == '*') {
				s.Push(op1 * op2);
			}
			else if (c == '/')
			{
				s.Push(op1 / op2);
			}
			else
			{
				cout << "Wrong operator" << endl;
				exit(-1); // 강제 종료
			}
		}

		//cout << "Stack: ";
		//s.Print();
	}

	return s.Top();
}
