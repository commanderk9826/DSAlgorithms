#include <iostream>
#define arrMAXSIZE 10
using namespace std;

// ���� Ž�� -- �˰��� ���� / ����� ���
int	binarySearch(int* pArr, int  first, int  last, int  key);

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };
	cout << "���� ������: ";
	PRINT(arr, arrMAXSIZE);

	int	key;
	while (true) {
		cout << "�˻� ������ �Է�(�˻� ����: 0) : ";
		cin >> key;
		if (key == 0)
			break;

		int index = binarySearch(arr, 0, arrMAXSIZE - 1, key);
		if (index == EOF) cout << "���ٰ�!!!" << endl;
		else cout << "�˻� ������: " << arr[index] << "��° ��ġ " << index + 1 << endl;
	}
	return 0;
}

// ����Ž��: ��������
int	binarySearch(int* pArr, int  first, int  last, int  key) {
	// ����Լ��� Ż�� ����
	if (first > last)
		return  EOF;

	// �߰� ������ ��ġ(÷��) ���: first ~ last ��������...
	int	index, mid = (first + last) / 2;

	if (*(pArr + mid) == key)		return  mid;
	else if (*(pArr + mid) < key)	index = binarySearch(pArr, mid + 1, last, key);
	else if (*(pArr + mid) > key)	index = binarySearch(pArr, first, mid - 1, key);
	return index;
}
