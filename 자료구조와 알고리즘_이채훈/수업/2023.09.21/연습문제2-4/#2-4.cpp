/*
03. ���
�������� 2-4: �Ǻ���ġ���� -- ����� ���
*/
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int Fibo(int num);
int main(void) {
	int num;
	cout << "### �Ǻ���ġ ���� ���ϱ� ###" << endl << endl;
	cout << "�� ��° �������� ����ұ��: "; cin >> num;

	for (int i = 1; i <= num; i++) {
		if (i % 5) {
			cout.width(8);
			cout << Fibo(i);
		}
		else {
			cout.width(8);
			cout << Fibo(i);
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}
//����� ��� : �Ǻ���ġ ����
int Fibo(int num) {
	//��� Ż�� : Ż�� ����
	if (num == 1 || num == 2)
		return 1;
	else {
		return Fibo(num - 1) + Fibo(num - 2);//O(2^n)
	}
}