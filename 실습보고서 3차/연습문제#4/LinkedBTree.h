#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include "LinkedQueue.h"

using namespace std;

// ������ ���θ� �Ǵ�
int  isOperator(int  op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

template <typename E>
class LinkedBTree;

// class DNode
template <typename E>
class DNode {
public:
	DNode(const E& data);
private:
	E         __data;
	DNode<E>* __Llink;
	DNode<E>* __Rlink;
	template <typename E> friend class LinkedBTree;
	template <typename E> friend class LinkedQueue;
};

//DNode: �����ڿ� �޼ҵ� ����
template <typename E>
DNode<E>::DNode(const E& data)
	:__data(data), __Llink(nullptr), __Rlink(nullptr) {}

// class LinkedBTree
template <typename E>
class LinkedBTree {
public:
	LinkedBTree();
	DNode<E>* makeLinkedBTree(const string str);
	void	Preorder(DNode<E>* root) const;
	void	Inorder(DNode<E>* root) const;
	void	Postorder(DNode<E>* root) const;
	void    Levelorder(DNode<E>* root)const;

private:
	DNode<E>* root;
};

//LinkedBTree class : �����ڿ� �Ҹ���
template <typename E>
LinkedBTree<E>::LinkedBTree()
	: root(nullptr) {}


//���� Ʈ��(���� Ʈ��) ����
template <typename E>
DNode<E>* LinkedBTree<E>::makeLinkedBTree(const string str) {
	stack<DNode<E>*> s;
	DNode<E>* tNode;
	for (int i = 0; i < str.length(); i++) {
		//���� ����
		while (str[i] == ' ')
			i++;

		//���ο� ��带 ����
		tNode = new DNode<E>(str[i]);

		//�������� ���...
		if (isOperator(str[i])) {
			tNode->__Rlink = s.top(); s.pop();
			tNode->__Llink = s.top(); s.pop();
		}
		s.push(tNode);
	}
	tNode = s.top();
	s.pop();

	//��Ʈ ��� ����
	root = tNode;
	return tNode;
}

//���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Preorder(DNode<E>* root)const {
	if (root == nullptr) 
		return;
	stack<DNode<E>*> s;
	s.push(root);
	while (!s.empty()) {
		DNode<E>* tNode = s.top();
		s.pop();
		cout.width(3); cout << tNode->__data;
		if (tNode->__Rlink) s.push(tNode->__Rlink);
		if (tNode->__Llink) s.push(tNode->__Llink);
	}
}

//���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Inorder(DNode<E>* root)const {
	stack<DNode<E>*> s;
	DNode<E>* tNode = root;
	while (tNode || !s.empty()) {
		while (tNode) {
			s.push(tNode);
			tNode = tNode->__Llink;
		}
		tNode = s.top();
		s.pop();
		cout.width(3); cout << tNode->__data;
		tNode = tNode->__Rlink;
	}
}

//���� �켱 ��ȸ: ���� ��ȸ
template <typename E>
void LinkedBTree<E>::Postorder(DNode<E>* root)const {
	if (root == nullptr) 
		return;
	stack<DNode<E>*> s1, s2;
	s1.push(root);
	while (!s1.empty()) {
		DNode<E>* tNode1 = s1.top();
		s1.pop();
		s2.push(tNode1);
		if (tNode1->__Llink) s1.push(tNode1->__Llink);
		if (tNode1->__Rlink) s1.push(tNode1->__Rlink);
	}
	while (!s2.empty()) {
		DNode<E>* tNode2 = s2.top();
		s2.pop();
		cout.width(3); cout << tNode2->__data;
	}
}

//�ʺ� �켱 ��ȸ
template <typename E>
void LinkedBTree<E>::Levelorder(DNode<E>* root)const {
	if (root == nullptr)
		return;
	queue<DNode<E>*> Q;
	Q.push(root);
	while (!Q.empty()) {
		DNode<E>* tNode = Q.front();
		Q.pop();
		cout.width(3);
		cout << tNode->__data;
		if (tNode->__Llink) Q.push(tNode->__Llink);
		if (tNode->__Rlink) Q.push(tNode->__Rlink);
	}
	cout << endl;
}