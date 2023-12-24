#pragma once
/*
	���� Ʈ��: �˰��� ����(C) -- �ܼ����Ḯ��Ʈ
			���ϸ�: LinkedBTree.h
*/

// #pragma once
#include "LinkedNode.h"		// DNode, makeDNode

// ���� Ʈ�� ����
DNode* makeLinkedBTree(char* pStr);
int	isOperator(int ch);
int	isLegal(char* pStr);

// ���� Ʈ�� ��ȸ: ���� �켱 ��ȸ(����.����.���� ��ȸ)
void	Preorder(DNode* root);
void	Inorder(DNode* root);
void	Postorder(DNode* root);

// ���� Ʈ�� ��ȸ: �ʺ� �켱 ��ȸ
void	Levelorder(DNode* root);
