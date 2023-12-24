/*
	���� Ʈ��: �˰��� ���� -- �ܼ����Ḯ��Ʈ
		���ϸ�: LinkedBTree(demo).cpp
			- main: ���� Ʈ��(���� Ʈ��) ���� �� ��ȸ
*/

#include <iostream>
#include <string>
#include "LinkedBtree.h"	// DNode Class 
// LinkedBTree Class
using namespace std;

int main(void)
{
	string	postfix;

	cout << "20215229 ��ä��" << endl;

	cout << "Ʈ���� ������ ���� ����: ";
	getline(cin, postfix);

	// ���� Ʈ�� ���� �� ����
	LinkedBTree<char>	BT;
	DNode<char>* root = BT.makeLinkedBTree(postfix);

	// ���� �켱 ��ȸ: ����.����.���� ��ȸ
	cout << "\nPreorder  : ";	BT.Preorder(root);	// ���� ��ȸ
	cout << "\nInorder   : ";	BT.Inorder(root);	// ���� ��ȸ
	cout << "\nPostorder : ";	BT.Postorder(root);	// ���� ��ȸ
	cout << "\nLevelorder : ";	BT.Levelorder(root); // �ʺ� �켱 ��ȸ

	return 0;
}