/*
	ť: �˰��� ���� -- �ܼ����Ḯ��Ʈ
		- main	: ������ ����.����, ��ü ���� ���
*/

#include <stdio.h>
#include <stdlib.h>				// system
#include <stdbool.h>			// bool, true, false
#include "LinkedQueue.h"		// LinkedQueue

int main(void)
{
	int		num, data;
	LinkedQueue* Q = queueCreate();

	while (true) {
		system("cls");
		printf("\n ### ť ����: �ܼ� ���� ����Ʈ ### \n\n");
		printf("1) ������ ����(enQueue) \n");
		printf("2) ������ ����(deQueue) \n");
		printf("3) ��ü ��� \n");
		printf("4) ���α׷� ���� \n\n");
		printf("�޴� ����: ");
		scanf_s("%d", &num);// scanf("%d", &num);

		switch (num) {
		case 1: printf("\n���� �� ������ �Է� : ");
			scanf_s("%d", &data);		// scanf("%d", &data);
			enQueue(Q, data);
			break;
		case 2: printf("���� �� ������ : %3d \n", front(Q));
			deQueue(Q);
			break;
		case 3:printQueue(Q);
			break;
		case 4: printf("���α׷� ����... \n");
			return 0;
		default: printf("�߸� ���� �ϼ̽��ϴ�. \n");
		}
		system("pause");
	}
	queueDestroy(Q);
	return 0;
}