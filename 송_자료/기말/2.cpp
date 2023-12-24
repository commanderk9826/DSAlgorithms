#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

void	searchBST(BinarySearchTree* bst);
void	insertBST(BinarySearchTree* bst);
void	deleteBST(BinarySearchTree* bst);

int main(void)
{
	int			num;
	BinarySearchTree* bst = new BinarySearchTree();
	while (true) {
		system("cls");
		cout << "\n ### ���� Ž�� Ʈ�� ### \n" << endl;
		cout << "1) ������ ����" << endl;
		cout << "2) ������ �˻�" << endl;
		cout << "3) ������ ����" << endl;
		cout << "4) ��ü ���" << endl;
		cout << "5) ���α׷� ����" << endl;
		cout << "\n�޴� ����: ";
		cin >> num;
		switch (num) {
		case 1: insertBST(bst);			break;
		case 2: searchBST(bst);			break;
		case 3: deleteBST(bst);			break;
		case 4: bst->printBSTAll(bst->getRoot());	break;
		case 5: cout << "���α׷� ����!!!\n" << endl;	return 0;
		default: cout << "�޴��� �߸� �����ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
	return 0;
}

// ���� Ž�� Ʈ��(BST): ������ �˻�
void  searchBST(BinarySearchTree* bst) {
	int		num;
	DNode* temp = nullptr;
	while (true) {
		cout << "\nã�� ������ ���� ���� �Է��ϼ���(����: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// �����Ͱ˻�
		temp = bst->search(num);
		if (temp)	cout << temp->__data << " Ű�� ã�ҽ��ϴ�!!!" << endl;
		else		cout << "Ű�� ã�� ���߽��ϴ�." << endl;
	}
}

// ���� Ž�� Ʈ��(BST): ������ �Է�
void insertBST(BinarySearchTree* bst) {
	int		num;
	while (true) {
		cout << "������ ���� �Է�(����: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// ������ ����
		bst->insert(num);
	}
}

// ���� Ž�� Ʈ��(BST): ������ ����
void  deleteBST(BinarySearchTree* bst) {
	int		num;
	DNode* temp = nullptr;
	while (true) {
		cout << "\n������ ������ ���� ���� �Է��ϼ���(����: 0): ";
		cin >> num;
		if (num == 0)
			break;

		// ������ ����
		bst->remove(num);
	}
}