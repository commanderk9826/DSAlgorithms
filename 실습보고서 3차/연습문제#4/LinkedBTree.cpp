#include <iostream>
#include <string>
#include "LinkedBtree.h"// class DNode

using namespace std;

int main(void)
{
	string	postfix;

	cout << "20215229 ��ä��" << endl;

	cout << "\nƮ���� ������ ���� ����: ";
	getline(cin, postfix);

	// ���� Ʈ�� ���� �� ����
	LinkedBTree<char>	BT;
	DNode<char>* root = BT.makeLinkedBTree(postfix);

	// ���� �켱 ��ȸ: ����.����.���� ��ȸ
	cout << "\nPreorder  : "; BT.Preorder(root);	// ���� ��ȸ
	cout << "\nInorder   : "; BT.Inorder(root);	// ���� ��ȸ
	cout << "\nPostorder : "; BT.Postorder(root);	// ���� ��ȸ

	// �ʺ� �켱 ��ȸ
	cout << "\nLevelorder : "; BT.Levelorder(root); 

	return 0;
}