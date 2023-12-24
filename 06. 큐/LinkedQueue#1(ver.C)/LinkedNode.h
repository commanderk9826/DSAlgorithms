/*
	�ܼ�.���� ���� ����Ʈ : �˰��� ����(C)
		���ϸ�: LinkedNode.h
			- ���		: SNode(__data, __link)
			- ���		: DNode(__data, __Llink, __Rlink)
*/
#pragma once

typedef	int		element;

// �ܼ� ���� ����Ʈ ����(C)
// ���: SNode(data, link)
#ifndef __SNode_H__
#define __SNode_H__
typedef struct __SNode {
	element		__data;
	struct __SNode* __link;
}SNode;
#endif

SNode* makeSNode(element data);

// ���� ���� ����Ʈ ����(C)
// ���: DNode(data, Llink, Rlink)
#ifndef __DNode_H__
#define __DNode_H__
typedef struct __DNode {
	element		__data;
	struct __DNode* __Llink;
	struct __DNode* __Rlink;
}DNode;
#endif

DNode* makeDNode(element data);