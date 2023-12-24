/*
	����: �˰��� ����(C) -- �ܼ����Ḯ��Ʈ
		���ϸ�: LinkedStack.c
			- ���� ����.�Ҹ�		: stackCreate, stackDestroy
			- ������ ����.����	: push, pop
			- ������ Ȯ��(peek)	: top
			- �� ���� ���� �Ǵ�	: stackEempty
			- ���� ũ��		: stackSize
			- ������ ��ü ���� ���	: printStack
*/

#include <stdio.h>
#include <stdlib.h>			// malloc, free
#include "LinkedStack.h"		// LinkedStack, SNode
#include "LinkedNode.h"		// SNode, DNode

// stackCreate : �� ���� ����
LinkedStack* stackCreate(void) {
	LinkedStack* S = (LinkedStack*)malloc(sizeof(LinkedStack));
	if (S == NULL) {
		printf("���� ���� ����!!! \n");
		exit(100);
	}
	S->__top = NULL;
	S->__count = 0;
	return S;
}

// stackDestroy : ���� ���� -- ��� ��� ����
void	stackDestroy(LinkedStack* S) {
	SNode* temp = S->__top;
	while (temp) {
		S->__top = temp->__link;
		free(temp);
		temp = S->__top;
	}
	free(S);
	return;
}

// push : ������ ������ ����
void	push(LinkedStack* S, element data) {
	SNode* newSNode = makeSNode(data);
	newSNode->__link = S->__top;
	S->__top = newSNode;
	S->__count++;
}

// pop : ���ÿ��� ������ ����
void	pop(LinkedStack* S) {
	if (stackEempty(S))	return;
	SNode* temp = S->__top;
	S->__top = temp->__link;
	free(temp);
	S->__count--;
}

// top(peek) : ���� �� ���� ���� Ȯ��
element	top(LinkedStack* S) {
	if (stackEempty(S))	return EOF;		// return NULL;
	return  S->__top->__data;
}

// stackEempty : ������ ���� ����
_Bool	stackEempty(LinkedStack* S) {
	return S->__top == NULL;
}

// stackSize: ������ ũ��
int	stackSize(LinkedStack* S) {
	return S->__count;

}

// printStack : ������ ��ü ���� ���
void	printStack(LinkedStack* S) {
	SNode* temp = S->__top;
	printf("\n STACK [");
	while (temp) {
		printf("%3d", temp->__data);
		temp = temp->__link;
	}
	printf(" ]\n");
}