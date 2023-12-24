/*
	�ܼ�.���� ���� ����Ʈ : �˰��� ����(C)
		���ϸ�: LinkedNode.c
			- ���		: SNode(data, link)
			- ���		: DNode(data, link)
*/

#include <stdio.h>
#include <stdlib.h>		// malloc, free
#include "LinkedNode.h"		// SNode, DNode

// �ܼ� ���� ����Ʈ ����(C)
// ���ο� ���(data, link) ����
SNode* makeSNode(element num) {
	SNode* newSNode = (SNode*)malloc(sizeof(SNode));
	if (newSNode == NULL) {
		printf("��� ���� ����!!! \n");
		exit(100);
	}
	newSNode->__data = num;
	newSNode->__link = NULL;
	return newSNode;
}

// ���� ���� ����Ʈ ����(C)
// ���ο� ���(DNode: data, Llink, Rlink) ����
DNode* makeDNode(element num) {
	DNode* newDNode = (DNode*)malloc(sizeof(DNode));
	if (newDNode == NULL) {
		printf("��� ���� ����!!! \n");
		exit(100);
	}
	newDNode->__data = num;
	newDNode->__Llink = NULL;
	newDNode->__Rlink = NULL;
	return newDNode;
}