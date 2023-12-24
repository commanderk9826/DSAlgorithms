/*
	ť: �˰��� ���� -- �����ڷᱸ��(�ܼ����Ḯ��Ʈ)
		���ϸ�: LinkedQueue.c
			- ť�� ����.�Ҹ�		: queueCreate, queueDestroy
			- ������ ����.����	: enQueue, deQueue
			- ������ Ȯ��(peek)	: front, back
			- �� ���� ���� �Ǵ�	: queueEempty
			- ť�� ũ��		: queueSize
			- ť�� ��ü ���� ���	: printQueue
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedQueue.h"	// LinkedQueue, SNode
#include "LinkedNode.h"	// SNode, DNode

// queueCreate : �� ť ����
LinkedQueue* queueCreate(void) {
	LinkedQueue* Q = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (Q == NULL) {
		printf("���� ���� ����!!! \n");
		return NULL;
	}
	Q->__front = NULL;
	Q->__rear = NULL;
	return Q;
}

// queueDestroy : ť ���� -- ��� ��� ����
void queueDestroy(LinkedQueue* Q) {
	SNode* temp = Q->__front;
	while (temp) {
		Q->__front = temp->__link;
		free(temp);
		temp = Q->__front;
	}
	free(Q);
	return;
}

// enQueue : ť�� ������ ����
void enQueue(LinkedQueue* Q, element  data) {
	SNode* newSNode = makeSNode(data);
	if (Q->__front == NULL) {
		Q->__front = newSNode;
		Q->__rear = newSNode;
	}
	else {
		Q->__rear->__link = newSNode;
		Q->__rear = newSNode;
	}
}

// deQueue : ť���� ������ ����
void	deQueue(LinkedQueue* Q) {
	if (queueEempty(Q))	return;
	SNode* temp = Q->__front;
	Q->__front = temp->__link;
	if (Q->__front == NULL)
		Q->__rear = NULL;
	free(temp);
}

// front : ť���� ù ��° ���� Ȯ��
element front(LinkedQueue* Q) {
	if (queueEempty(Q))	return EOF;	// return NULL;	
	return  Q->__front->__data;
}

// back : ť���� �� ������ ���� Ȯ��
element back(LinkedQueue* Q) {
	if (queueEempty(Q))	return EOF;	// return NULL;
	return  Q->__rear->__data;
}

// queueEempty : ť�� ���� ���� ���� �Ǵ�
_Bool queueEempty(LinkedQueue* Q) {
	return Q->__front == NULL;
}

// queueSize: ť�� ũ��
int	queueSize(LinkedQueue* Q) {
	return Q->__count;

}

// printQueue : ť�� ��ü ���� ���
void printQueue(LinkedQueue* Q) {
	SNode* temp = Q->__front;
	printf("\n Queue [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}