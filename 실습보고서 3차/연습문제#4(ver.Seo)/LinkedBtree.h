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

/*
//���� �켱 ��ȸ: ���� ��ȸ(����� ���)
template <typename E>
void LinkedBTree<E>::Preorder(DNode<E>* root)const {
	if (root) {
		cout.width(3); cout << root->__data;
		Preorder(root->__Llink);
		Preorder(root->__Rlink);
	}
	
}
*/

//���� �켱 ��ȸ: ���� ��ȸ(������� ���)
template <typename E>
void LinkedBTree<E>::Preorder(DNode<E>* root)const {
	if (root == nullptr)
		return;
	stack<DNode<E>*> S;
	DNode<E>* tNode;
	S.push(root);
	while (!S.empty()) {
		tNode = S.top(); S.pop();
		if (tNode) {
			cout.width(3); cout << tNode->__data;
			S.push(tNode->__Rlink);
			S.push(tNode->__Llink);
		}
	}
	return;
}

/*
//���� �켱 ��ȸ: ���� ��ȸ(����� ���)
template <typename E>
void LinkedBTree<E>::Inorder(DNode<E>* root)const {
	if (root) {
		Inorder(root->__Llink);
		cout.width(3); cout << root->__data;
		Inorder(root->__Rlink);
	}
}
*/

//���� �켱 ��ȸ: ���� ��ȸ(������� ���)
template <typename E>
void LinkedBTree<E>::Inorder(DNode<E>* root)const {
	if (root == nullptr) return;
	stack<DNode<E>*> S;
	DNode<E>* tNode;
	tNode = root;
	while (true) {
		//���� ���� Ʈ���� ���ÿ�.
		while (tNode != nullptr) {
			S.push(tNode);
			tNode = tNode->__Llink;
		}
		if (S.empty())
			break;

		//���ÿ��� pop�� �����Ͽ� ��� �湮
		tNode = S.top(); S.pop();
		cout.width(3); cout << tNode->__data;

		//������ ���� Ʈ���� �̵�
		tNode = tNode->__Rlink;
	}
	return;
}

/*
//���� �켱 ��ȸ: ���� ��ȸ(����� ���)
template <typename E>
void LinkedBTree<E>::Postorder(DNode<E>* root)const {
	if (root) {
		Postorder(root->__Llink);
		Postorder(root->__Rlink);
		cout.width(3); cout << root->__data;
	}
}
*/

//���� �켱 ��ȸ: ���� ��ȸ(������� ���)
template <typename E>
void LinkedBTree<E>::Postorder(DNode<E>* root)const {
	if (root == nullptr) return;
	stack<DNode<E>*> S;
	DNode<E>* tNode, * pre;

	tNode = root;
	while (true) {
		//���� ���� Ʈ���� ���ÿ�..
		while (tNode != nullptr) {
			S.push(tNode);
			tNode = tNode->__Llink;
		}

		while (!S.empty()) {
			pre = tNode;
			tNode = S.top(); S.pop();
			//������ ���� Ʈ���� ���� ���..
			if (tNode->__Rlink != nullptr) {
				if (tNode->__Rlink == pre) {
					cout.width(3);
					cout << tNode->__data;
				}
				else {
					S.push(tNode);
					tNode = tNode->__Rlink;
					break;
				}
			}
			//������ ���� Ʈ���� ������ ��� �湮
			else {
				cout.width(3);
				cout << tNode->__data;
			}

		}
		if (S.empty())
			break;
	}
	return;
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