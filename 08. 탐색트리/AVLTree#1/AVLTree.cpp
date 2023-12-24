/*
    ���� Ž�� Ʈ��(AVL Ʈ��): �˰��� ����
        ���ϸ�: AVLTree(demo).cpp
            - main	: ����(Insert), ����(Remove), �˻�(Search), ��ü ���
*/

#include <iostream>
#include <algorithm>    // max
#include "AVLTree.h"    // AVLTree
using namespace std;

void	Insert(AVLTree* avl);
void	Remove(AVLTree* avl);
void	Search(AVLTree* avl);

int main(void)
{
    int         num;
    AVLTree* avl = new AVLTree();
    while (true) {
        system("cls");
        cout << "\n ### ���� ���� Ž�� Ʈ��: AVL ### \n" << endl;
        cout << "1) ������ ����" << endl;
        cout << "2) ������ ����" << endl;
        cout << "3) ������ �˻�" << endl;
        cout << "4) ��ü ���" << endl;
        cout << "5) ���α׷� ����" << endl;
        cout << "\n�޴� ����: ";
        cin >> num;
        switch (num) {
        case 1: Insert(avl);	break;
        case 2: Remove(avl);	break;
        case 3: Search(avl);	break;
        case 4: avl->Inorder(avl->getRoot());         break;
        case 5: cout << "���α׷� ����!!!\n" << endl;   return 0;
        default: cout << "�޴��� �߸� �����ϼ̽��ϴ�." << endl;
        }
        system("pause");
    }
    return 0;
}

// ������ �Է�
void Insert(AVLTree* avl) {
    int	    num;
    while (true) {
        cout << "������ ���� �Է�(����: 0): ";
        cin >> num;
        if (num == 0)   break;
        avl->insert(num);
    }
}

// ������ ����
void  Remove(AVLTree* avl) {
    int	    num;
    while (true) {
        cout << "\n������ ������ ���� ���� �Է��ϼ���(����: 0): ";
        cin >> num;
        if (num == 0)   break;
        avl->remove(num);
    }
}

// ������ �˻�
void  Search(AVLTree* avl) {
    int		num;
    AVLNode* temp = nullptr;
    while (true) {
        cout << "\nã�� ������ ���� ���� �Է��ϼ���(����: 0): ";
        cin >> num;
        if (num == 0)   break;
        temp = avl->search(num);
        if (temp)	cout << temp->getData() << " Ű�� ã�ҽ��ϴ�!!!" << endl;
        else		cout << "Ű�� ã�� ���߽��ϴ�." << endl;
    }
}
