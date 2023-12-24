/*
	���� Ʈ��: �˰��� ����
		���ϸ�: LinkedBTree.c
			- ���� Ʈ�� ����			: makeLinkedBTree
			- ���� �켱 ��ȸ(����.����.����)	: Preorder, Inorder, Postorder
			- �ʺ� �켱 ��ȸ			: Levelorder
*/

#include <stdio.h>
#include <stdlib.h>		// malloc
#include "LinkedStack.h"	// LinkedStack
#include "LinkedQueue.h"	// LinkedQueue
#include "LinkedBTree.h"	// DNode
#include "LinkedNode.h"	// SNode, DNode
#include "Operators.h"		// isOperator,precedence, isLegal

// ���� Ʈ�� ����
DNode* makeLinkedBTree(char* pStr) {
	DNode* temp;
	LinkedStack* S = stackCreate();
	while (*pStr) {
		// ���� ����
		while (*pStr == ' ')
			pStr++;

		temp = makeDNode(*pStr);

		// �������� ���: ���ÿ��� �ڽ� ��带 ������ �ּҸ� pop
		if (isOperator(*pStr)) {
			temp->__Rlink = (DNode*)top(S);		pop(S);
			temp->__Llink = (DNode*)top(S);		pop(S);
		}
		push(S, (long long)temp);
		pStr++;
	}
	// ��Ʈ ���
	temp = (DNode*)top(S);
	pop(S);

	stackDestroy(S);
	return  temp;
}

// ���� �켱 ��ȸ: ���� ��ȸ(����� ���)
void  Preorder(DNode* root) {
	if (root) {
		printf("%3c", root->__data);
		Preorder(root->__Llink);
		Preorder(root->__Rlink);
	}
}

// ���� �켱 ��ȸ: ���� ��ȸ(����� ���)
void  Inorder(DNode* root) {
	if (root) {
		Inorder(root->__Llink);
		printf("%3c", root->__data);
		Inorder(root->__Rlink);
	}
}

// ���� �켱 ��ȸ: ���� ��ȸ(����� ���)
void  Postorder(DNode* root) {
	if (root) {
		Postorder(root->__Llink);
		Postorder(root->__Rlink);
		printf("%3c", root->__data);
	}
}

// �ʺ� �켱 ��ȸ: ������� ���
void  Levelorder(DNode* root) {
	DNode* temp;
	LinkedQueue* Q = queueCreate();

	enQueue(Q, (long long)root);
	while (!queueEempty(Q)) {
		temp = (DNode*)front(Q);	deQueue(Q);
		printf("%3c", temp->__data);
		if (temp->__Llink)	enQueue(Q, temp->__Llink);
		if (temp->__Rlink)	enQueue(Q, temp->__Rlink);
	}
	queueDestroy(Q);
}