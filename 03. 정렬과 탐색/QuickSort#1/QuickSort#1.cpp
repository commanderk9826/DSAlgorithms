/*
����: �˰��� ����
������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  quickSort(int* pArr, int* pFirst, int* pLast);// �� ����

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}

int main(void)
{
	int	arr[arrMAXSIZE] = { 0 };
	/*
	//C ��Ÿ�� ���� ����(srand�� rand �Լ�)
	srand(static_cast<unsigned int>(time(nullptr)));
	static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	*/
	//C++ ��Ÿ�� ���� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);


	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "���� ��: ";
	PRINT(arr, arrMAXSIZE);

	quickSort(arr, arr, arr + arrMAXSIZE - 1);


	cout << "���� ��: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// �� ����: ��������
void  quickSort(int* pArr, int* pFirst, int* pLast) {
	// ��� �Լ� Ż�� ����
	if (pFirst >= pLast)
		return;

	// ����: ���� ���� ����(���� ��)�� ������(ū ��) �κ� ����
	int* pi = pFirst - 1;
	for (int* pj = pFirst; pj < pLast; pj++)
		if (*pj <= *pLast)		// ���� ��(pivot): ������ ����
			SWAP(++pi, pj);
	SWAP(pi + 1, pLast);			// ���� ���� ����� ��ġ ��Ų��.

	int* mid = pi + 1;				// ���� ���� ��ġ(�ּ�)
	quickSort(pArr, pFirst, mid - 1);		// ���� �κ� ����
	quickSort(pArr, mid + 1, pLast);		// ������ �κ� ����
}