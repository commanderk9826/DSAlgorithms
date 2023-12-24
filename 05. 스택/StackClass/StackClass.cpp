#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack<int> S;

	S.push(10);
	S.push(20);
	S.push(30);

	cout << "stack is empty : " << S.empty() << endl;
	cout << "stack size     : " << S.size() << endl;

	while (!S.empty()) {
		cout << "top element : " << S.top() << endl;
		S.pop();
	}
	return 0;
}

/*
#include <stack> 
using namespace std;
stack<DataType> stackName // �� ���� ����
void push(const value_type& val); // ���ÿ� ������ �׸� �߰�
void pop(); // ���ÿ� ������ �׸� ����
value_type& top();// ������ ������ �׸� ��ȯ(top)
bool empty() const; // ������ ��� �ִ��� ���� Ȯ��
size_type size() const; // ������ ũ�� ��ȯ
swap(stack1, stack2) // ���� SWAP
*/