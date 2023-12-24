#pragma once
#include <iostream>

using namespace std;

inline void error(const char* message) {
	cout << message;
	exit(100);
}

template<typename E>
class SNode {
public:
	SNode(const E& data);
	E getData(void)const;
private:
	E __data;
	SNode<E>* __link;
	template<typename E> friend class LinkedQueue;
};

//SNode class: ��� �Լ� �ܺ� ����
template <typename E>
SNode<E>::SNode(const E& data)
	: __data(data), __link(nullptr) {}

template <typename E>
E SNode<E>::getData(void) const {
	return __data;
}

//LinkedQueue class
template <typename E>
class LinkedQueue {
public:
	LinkedQueue();
	~LinkedQueue();
	void push(const E& e);//enQueue
	void pop(void); //deQueue
	E& front(void) const;
	E& back(void) const;
	bool empty(void) const;
	int size(void)const;
	void printQueue(void) const;
private:
	SNode<E>* __front;
	SNode<E>* __rear;
	int __count;
};

//LinkedStack class: ������(�Ҹ���)�� �Ҹ���
template<typename E>
LinkedQueue<E>::LinkedQueue()
	: __front(nullptr), __rear(nullptr), __count(0) {}

template <typename E>
LinkedQueue<E> :: ~LinkedQueue() {
	SNode<E>* temp = __front;
	while (temp) {
		__front = temp->__link;
		delete temp;
		temp = __front;
	}
}

//push(enQueue) : ť�� ������ �׸� ����(�� ������ ����)
template <typename E>
void LinkedQueue<E>::push(const E& e) {//enQueue
	SNode<E>* newSNode = new SNode<int>(e);
	//newSNode-> __data=e;
	if (__front)
		__rear->__link = newSNode;
	else __front = newSNode;
	__rear = newSNode;
}

//pop(deQueue) : ť���� �� ù��°�� ���Ե� ������ �׸� ����
template <typename E>
void LinkedQueue<E>::pop(void) {//deQueue
	if (empty()) error("STACK IS EMPTY"); //throw "ERROR : STACK IS EMPTY";
	SNode<int>* temp = __front;
	//E data = temp->__data;
	__front = temp->__link;
	if (!__front)
		__rear = nullptr;
	delete temp;
}

//front(peek) : ť���� �� ù ��°�� ���Ե� ������ �׸� Ȯ��
template<typename E>
E& LinkedQueue<E>::front(void)const {
	if (empty())error("STACK IS EMPTY");//throw "ERROR::STACK IS EMPTY";
	return __front->__data;
}

//back(peek) : ť���� �� �������� ���Ե� ������ �׸� Ȯ��
template<typename E>
E& LinkedQueue<E>::back(void)const {
	if (empty())error("STACK IS EMPTY"); //throw "ERROR::STACK IS EMPTY";
	return __rear->__data;
}

//empty : ������ ���� ���� Ȯ��
template <typename E>
bool LinkedQueue<E> ::empty(void)const {
	return __front == nullptr;
}

//size : ť�� ũ��(�׸��� ����)
template<typename E>
int LinkedQueue<E> ::size(void)const {
	return __count;
}

//printQueue : ť�� ��ü ������ �׸� ���
template <typename E>
void LinkedQueue<E>::printQueue(void)const {
	SNode<E>* temp = __front;
	cout << "\nQUEUE [";
	while (temp) {
		cout << temp->__data;
		temp = temp->__link;
	}
	cout << "]" << endl;
}
