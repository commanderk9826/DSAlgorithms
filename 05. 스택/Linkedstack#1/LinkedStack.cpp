/*
	����: �˰��� ���� -- �ܼ����Ḯ��Ʈ
		- main	: ������ ����(push).����(pop), ��ü ���� ���
*/

#include <iostream>
#include "LinkedStack.h"
using namespace std;

int main(void)
{
	int	num, choice;
	LinkedStack<int>	S;	// �� ���� ����

	while (true) {
		system("cls");
		cout << "### ���� ����: �ܼ� ���� ����Ʈ ###\n" << endl;
		cout << "1) ������ ����(push)" << endl;
		cout << "2) ������ ����(pop)" << endl;
		cout << "3) ��ü ���" << endl;
		cout << "4) ���α׷� ���� \n" << endl;
		cout << "�޴� ���� : ";
		cin >> choice;

		switch (choice) {
		case 1: cout << "\n���� �� ������ �Է�: ";
			cin >> num;
			S.push(num);
			break;
		case 2: cout << "���� �� ������: " << S.top() << endl;
			S.pop();
			break;
		case 3: S.printStack();
			break;
		case 4: cout << "���α׷� ����..." << endl;
			return 0;
		default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
	return 0;	// S.~ListStack();
}



