/*
* 02. ���
* ����2-2. ���(Factorial ���ϱ�)
*/

#include <iostream>
using namespace std;

int Factorial(int num);

int main(void) {

	int num;
	cout << "������ ����: ";
	cin >> num;
	cout << num << " Factorial: " << Factorial(num) << endl;
	return 0;
}

//����� ��� : Factorial
int Factorial(int num) {
	if (num == 0)//����Լ� Ż��(����) ����
		return 1;
	return num * Factorial(num - 1);
}

//�ݺ��� ��� : Factorial
/*
int Factorial(int num) {
	int res = 1;
	for (int i = 0; i <= num; i++)
		res = res * i;
	return res;
}
*/
