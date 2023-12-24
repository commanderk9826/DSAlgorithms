#include <iostream>
#define stackMAXSIZE 10
using namespace std;
inline void error(const char* message);

// �迭 ����: arrayStack
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
	int size(void) const;
	bool	Empty(void) const;
	bool	Full(void) const;
	void	printStack(void) const;
};

// ������: �� ���� ����
template <typename E>
arrayStack<E>::arrayStack() : top(-1) {}

// �Ҹ���
template <typename E>
arrayStack<E>::~arrayStack() {}

// PUSH : ���ÿ� ������ ���� 
template <typename E>
void	arrayStack<E>::push(const E& e) {
	if (Full()) 
		error("���� ��ȭ ����");	
	stack[++top] = e;
}

// POP : ���ÿ��� ������ ����
template <typename E>
E	arrayStack<E>::pop(void) {
	if (Empty()) 
		error("���� ���� ����");	
	return stack[top--];
}

// PEEK : ���� �� ���� ���� Ȯ��
template <typename E>
E	arrayStack<E>::peek(void) const {
	if (Empty()) 
		error("���� ���� ����");	
	return stack[top];
}

// SIZE : ������ ũ�� �� ��ȯ
template <typename E>
int arrayStack<E>::size(void) const {
	return top + 1;
}


// ������ ���� ���� ���� �Ǵ�
template <typename E>
bool	arrayStack<E>::Empty(void) const {
	return top == -1;
}

// ������ ��ȭ ���� ���� �Ǵ�
template <typename E>
bool	arrayStack<E>::Full(void) const {
	return top == stackMAXSIZE - 1;
}


// ������ ��ü ���� ���
template <typename E>
void	arrayStack<E>::printStack(void) const {
	cout << "\nSTACK [";
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
	arrayStack<int>	s = arrayStack<int>();// �� ���� ����
	

	while (true) {
		system("cls");
		cout << " 20215229 ��ä�� " << endl;
		cout << "\n ### ���� ����: 1���� �迭 ###\n" << endl;
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
			cout << "���� ũ��: " << s.size() << endl;
			break;
		case 4: cout << "���α׷� ����..." << endl;
			return 0;
		default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
	
	return 0;
}