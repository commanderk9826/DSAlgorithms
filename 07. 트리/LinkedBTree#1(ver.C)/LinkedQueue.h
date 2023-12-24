#pragma once
/*
	ť: �˰��� ����(C) -- �ܼ� ���� ����Ʈ
		���ϸ�: LinkedQueue.h
			- ť�� ����.�Ҹ�		: queueCreate, queueDestroy
			- ������ ����.����	: enQueue, deQueue
			- ������ Ȯ��(peek)	: front, back
			- �� ���� ���� �Ǵ�	: queueEempty
			- ť�� ũ��		: queueSize
			- ť�� ��ü ���� ���	: printQueue
*/

// #pragma once
#include "LinkedNode.h"		// SNode, DNode

// ť ����: LinkedQueue
#ifndef __LinkdedQueue_H__
#define __LinkdedQueue_H__
typedef struct __LinkedQueue {
	SNode* __front, * __rear;
	int	__count;
}LinkedQueue;
#endif

// ť ����(C):: ť ���� �� Ȱ��
LinkedQueue* queueCreate(void);
void		queueDestroy(LinkedQueue* Q);
void		enQueue(LinkedQueue* Q, element data);
void		deQueue(LinkedQueue* Q);
element		front(LinkedQueue* Q);
element		back(LinkedQueue* Q);
_Bool		queueEempty(LinkedQueue* Q);
int		queueSize(LinkedQueue* Q);
void		printQueue(LinkedQueue* Q);