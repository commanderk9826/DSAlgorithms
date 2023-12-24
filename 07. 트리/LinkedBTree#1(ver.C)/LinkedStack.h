#pragma once
/*
	����: �˰��� ����(C) -- �ܼ� ���� ����Ʈ
		���ϸ�: LinkedStack.h
			- ���� ����.�Ҹ�		: stackCreate, stackDestroy
			- ������ ����.����	: push, pop
			- ������ Ȯ��(peek)	: top
			- �� ���� ���� �Ǵ�	: stackEempty
			- ���� ũ��		: stackSize
			- ������ ��ü ���� ���	: printStack
*/

// #pragma once
#include "LinkedNode.h"		// SNode, DNode

// ���� ����: LinkedStack
#ifndef __LinkedStack_H__
#define __LinkedStack_H__
typedef struct __LinkedStack {
	SNode* __top;
	int	__count;
}LinkedStack;
#endif

// ���� ����(C): ���� ���� �� Ȱ��
LinkedStack* stackCreate(void);
void		stackDestroy(LinkedStack* S);
void		push(LinkedStack* S, element data);
void		pop(LinkedStack* S);
element		top(LinkedStack* S);
_Bool		stackEempty(LinkedStack* S);
int		stackSize(LinkedStack* S);
void		printStack(LinkedStack* S);