#include <iostream>
#define arrMAXSIZE 10
using namespace std;

// ���� Ž�� -- �˰��� ���� / ������� ���
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key);
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

		int* pIndex = binarySearch(arr, arr, arr + arrMAXSIZE - 1, key);
		if (pIndex == NULL) cout << "���ٰ�!!!" << endl;
		else cout << "�˻� ������: " << *pIndex << "��° ��ġ " << pIndex - arr + 1 << endl;
	}
	return 0;
}

// ����Ž��: ����������
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key) {
	while (pFirst <= pLast) {
		// �߰� ������ ��ġ(�ּ�) ���: pFirst ~ pLast ��������...
		int* pMid = pFirst + (pLast - pFirst) / 2;

		if (*pMid == key)	return  pMid;
		else if (*pMid < key)	pFirst = pMid + 1;
		else if (*pMid > key)	pLast = pMid - 1;
	}
	return NULL;
}