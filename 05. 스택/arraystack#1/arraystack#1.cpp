/*
	����: �˰��� ���� -- �����ڷᱸ��(�迭)
		- arrayStack : stack, top
*/

#include <iostream>
#define stackMAXSIZE 100
using namespace std;
inline void error(const char* message);

// �迭 ����: arrayStack -- Ŭ���� ����
template <typename E>
class arrayStack {
private:
	E	stack[stackMAXSIZE];
	int	top;
public:
	arrayStack();
	~arrayStack();
	void	push(const E& e);
	E	pop(void);
	E	peek(void) const;
	bool	isEmpty(void) const;
	bool	isFull(void) const;
	void	printStack(void) const;
};

/*
	�迭 ����: arrayStack -- �޼ҵ� ����
		- ���� ���� �� ����: arrayStack, ~arrayStack
		- ���� ���԰� ���� : push, pop
		- ������ Ȯ��      : peek
		- ���� ���� �Ǵ�   : isEmpty, isFull
		- ��ü ���� ���   : printStack
*/

// ������: �� ���� ����
template <typename E>
arrayStack<E>::arrayStack() : top(-1) {}

// �Ҹ���
template <typename E>
arrayStack<E>::~arrayStack() {}

// PUSH : ���ÿ� ������ ���� 
template <typename E>
void	arrayStack<E>::push(const E& e) {
	if (isFull()) error("���� ��ȭ ����");	// throw "ERROR::STACK IS FULL";
	stack[++top] = e;
}

// POP : ���ÿ��� ������ ����
template <typename E>
E	arrayStack<E>::pop(void) {
	if (isEmpty()) error("���� ���� ����");	// throw "ERROR::STACK IS EMPTY";
	return stack[top--];
}

// PEEK : ���� �� ���� ���� Ȯ��
template <typename E>
E	arrayStack<E>::peek(void) const {
	if (isEmpty()) error("���� ���� ����");	// throw "ERROR::STACK IS EMPTY";
	return stack[top];
}

// ������ ���� ���� ���� �Ǵ�
template <typename E>
bool	arrayStack<E>::isEmpty(void) const {
	return top == -1;
}

// ������ ��ȭ ���� ���� �Ǵ�
template <typename E>
bool	arrayStack<E>::isFull(void) const {
	return top == stackMAXSIZE - 1;
}

// ������ ��ü ���� ���
template <typename E>
void	arrayStack<E>::printStack(void) const {
	cout << "\n STACK [";
	for (int i = 0; i <= top; i++) {
		cout.width(3);
		cout << stack[i];
	}
	cout << " ]" << endl;
}

inline void error(const char* message) {
	cout << message;
	exit(100);
}

int main(void)
{
	int	num, choice;
	arrayStack<int>	s = arrayStack<int>();		// �� ���� ����

	while (true) {
		system("cls");
		cout << "\n ### ���� ����: 1���� �迭 ### \n" << endl;
		cout << "1) ������ ����: PUSH" << endl;
		cout << "2) ������ ����: POP" << endl;
		cout << "3) ��ü ���" << endl;
		cout << "4) ���α׷� ���� \n" << endl;
		cout << "�޴� ���� : ";
		cin >> choice;

		switch (choice) {
		case 1: cout << "\n���� �� ������ �Է�: ";
			cin >> num;
			s.push(num);
			break;
		case 2: cout << "���� �� ������: " << s.pop() << endl;
			break;
		case 3: s.printStack();
			break;
		case 4: cout << "���α׷� ����..." << endl;
			return 0;
		default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
	// s.~ArrayStack();
	return 0;
}