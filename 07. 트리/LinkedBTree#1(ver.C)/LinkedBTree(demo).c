/*
	���� Ʈ��: �˰��� ���� -- �ܼ����Ḯ��Ʈ
		���ϸ�: LinkedBTree(demo).c
			- main: ���� Ʈ�� ������ ��ȸ
*/

#include <stdio.h>
#include <stdlib.h>		// exit
#include "LinkedBTree.h"	// DNode
#define bufferMAXSIZE 1024

int main(void)
{
	DNode* root;
	char	postfix[bufferMAXSIZE];

	printf("Ʈ���� ������ ���� ����: ");
	gets_s(postfix, sizeof(postfix));

	if (!isLegal(postfix)) {
		printf("\n�߸��� ����... \n\n");
		exit(100);
	}

	// ���� Ʈ�� ����
	root = makeLinkedBTree(postfix);

	// ���� Ʈ�� ���� �켱 ��ȸ : ����.����.���� ��ȸ
	printf("\nPreorder  : ");	Preorder(root);			// ���� ��ȸ
	printf("\nInorder   : ");	Inorder(root);			// ���� ��ȸ
	printf("\nPostorder : ");	Postorder(root);		// ���� ��ȸ

	// ���� Ʈ�� �ʺ� �켱 ��ȸ
	printf("\nLevelorder : ");	Levelorder(root);
	printf("\n");

	return 0;
}
