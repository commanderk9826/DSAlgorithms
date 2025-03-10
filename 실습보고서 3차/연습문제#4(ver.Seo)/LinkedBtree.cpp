#include <iostream>
#include <string>
#include "LinkedBtree.h"// class DNode

using namespace std;

int main(void)
{
	string	postfix;

	cout << "20215229 이채훈" << endl;

	cout << "\n트리를 구성할 후위 수식: ";
	getline(cin, postfix);

	// 이진 트리 생성 및 구성
	LinkedBTree<char>	BT;
	DNode<char>* root = BT.makeLinkedBTree(postfix);

	// 깊이 우선 순회: 전위.중위.후위 순회
	cout << "\nPreorder  : "; BT.Preorder(root);	// 전위 순회
	cout << "\nInorder   : "; BT.Inorder(root);	// 중위 순회
	cout << "\nPostorder : "; BT.Postorder(root);	// 후위 순회

	// 너비 우선 순회
	cout << "\nLevelorder : "; BT.Levelorder(root);

	return 0;
}