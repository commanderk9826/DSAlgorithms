/*
03. ���
����2-3. 1���� n������ ��
*/
#include <iostream>

using namespace std;

int SUM(int num);

int main(void) {
	int num;
	cout << "������ ���� �Է�: "; cin >> num;
	cout << "1���� " << num << "������ ��: " << SUM(num) << endl;
	return 0;
}

//����� ���: 1���� n������ ��
int SUM(int num) {
	if (num < 0)
		return 0;
	return num + SUM(num - 1);
}

//�ݺ��� ���: 1���� n������ ��
/*
int SUM(int num) {
	int tot = 0;
	for(int i = 1; i< num + 1; i++)
		tot += i;
	return tot;
}
*/