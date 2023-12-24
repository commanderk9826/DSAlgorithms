/*
	����: �˰��� ����(C++) --�ܼ����Ḯ��Ʈ
		���ϸ�: LinkedStack.h
		Ŭ����: SNode
		Ŭ����: LinkedStack
			- ������.�Ҹ���: LinkedStack, ~LinkedStack
			- ������ �׸� ����.����: push, pop
			- ������ �׸� Ȯ��(peek): top
			- �� ���� ���� �Ǵ�: empty
			- ���� ũ��(������ �׸� ����): size
			- ������ ��ü ������ �׸� ���: printStack
*/
#include <iostream>
using namespace std;

inline void error(const char* message) {
	cout << message;
	exit(100);
}

template <typename E>
class LinkedStack;

// SNode class
template <typename E>
class SNode {
public:
	SNode(const E& data);
	E	getData(void) const;
private:
	E		__data;
	SNode<E>* __link;
	template <typename E> friend class LinkedStack;
};

// SNode class: ��� �Լ� �ܺ� ����
template <typename E>
SNode<E>::SNode(const E& data) :
	__data(data), __link(nullptr) {}

template <typename E>
E   SNode<E>::getData(void) const { return __data; }

// LinkedStack class
template <typename E>
class LinkedStack {
public:
	LinkedStack();
	~LinkedStack();
	void	push(const E& e);
	void	pop(void);
	E& top(void) const;
	bool	empty(void) const;
	int	size(void) const;
	void	printStack(void) const;
private:
	SNode<E>* __top;
	int		__count;
};

// LinkedStack class: ������(�Ҹ���)�� �Ҹ���
template <typename E>
LinkedStack<E>::LinkedStack()
	: __top(nullptr), __count(0) {}

template <typename E>
LinkedStack<E>::~LinkedStack() {
	SNode<E>* temp = __top;
	while (temp) {
		__top = temp->__link;
		delete temp;
		temp = __top;
	}
}

// push: ������ ������ �׸� ����(�� ������ ����)
template <typename E>
void	LinkedStack<E>::push(const E& e) {
	SNode<E>* newSNode = new SNode<int>(e);
	// newSNode->__data = e;
	newSNode->__link = __top;
	__top = newSNode;
	__count++;
}

// pop: ���ÿ��� �� �������� ���Ե� ������ �׸� ����
template <typename E>
void	LinkedStack<E>::pop(void) {
	if (empty()) error("ERROR::STACK IS EMPTY");	// throw "ERROR::STACK IS EMPTY";
	SNode<int>* temp = __top;
	if (temp) {
		__top = temp->__link;
		delete temp;
		__count--;
	}
}

// top(peek): ���ÿ��� �� �������� ���Ե� ������ �׸� Ȯ��
template <typename E>
E& LinkedStack<E>::top(void) const {
	if (empty()) error("STACK IS EMPTY");			// throw "ERROR::STACK IS EMPTY";
	return  __top->__data;
}

// empty: ������ ���� ���� Ȯ��
template <typename E>
bool	LinkedStack<E>::empty(void) const { return __top == nullptr; }

// size: ������ ũ��(�׸��� ����)
template <typename E>
int	LinkedStack<E>::size(void) const { return __count; }

// printStack: ������ ��ü ������ �׸� ���
template <typename E>
void	LinkedStack<E>::printStack(void) const {
	SNode<E>* temp = __top;
	cout << "\n STACK [";
	while (temp) {
		cout.width(3);
		cout << temp->__data;
		temp = temp->__link;
	}
	cout << " ]" << endl;
}