#include "Operators.h"

// ������ ���θ� �Ǵ�
int  isOperator(int  op) {
	return op == '+' || op == '-' || op == '*' || op == '/';
}

// ������ �켱������ ��ġ�� ��ȯ
int  precedence(int op) {
	if (op == '(') return 0;
	else if (op == '+' || op == '-') return 1;
	else if (op == '*' || op == '/') return 2;
	else return 3;
}

// ���� ���� ��
int  isLegal(char* pStr) {
	int	count = 0;
	for (; *pStr; pStr++) {
		while (*pStr == ' ')	pStr++;		// ���� ����
		if (isOperator(*pStr))	count--;	// �������̸� ����
		else count++;						// �ǿ������̸� ����

		// "�ǿ����� �� - ������ �� = 1"�� �Ǿ�� �Ѵ�.
		if (count < 1)
			break;
	}
	return count == 1;
}