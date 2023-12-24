/*
	ť: �˰��� ���� -- �ܼ����Ḯ��Ʈ
		- main	: ������ ����(push, enQueue).����(pop, deQueue), ��ü ���� ���
*/

#include <iostream>
#include "LinkedQueue.h"
using namespace std;

int main(void)
{
	int	num, choice;
	LinkedQueue<int>	Q;	// �� ť ����

	while (true) {
		system("cls");
		cout << "### ť ����: �ܼ� ���� ����Ʈ ###\n" << endl;
		cout << "1) ������ ����(push, enQueue)" << endl;
		cout << "2) ������ ����(pop, deQueue)" << endl;
		cout << "3) ��ü ���" << endl;
		cout << "4) ���α׷� ���� \n" << endl;
		cout << "�޴� ����: ";
		cin >> choice;

		switch (choice) {
		case 1: cout << "\n���� �� ������ �Է�: ";
			cin >> num;
			Q.push(num);
			break;
		case 2: cout << "���� �� ������: " << Q.front() << endl;
			Q.pop();
			break;
		case 3: Q.printQueue();
			break;
		case 4: cout << "���α׷� ����..." << endl;
			return 0;
		default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
		}
		system("pause");
	}
	return 0;	// Q.~LinkedQueue();
}
