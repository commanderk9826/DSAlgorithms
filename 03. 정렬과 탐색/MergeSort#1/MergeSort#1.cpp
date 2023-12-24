/*
����: �˰��� ����
��������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  mergeSort(int* pArr, int* pFirst, int* pLast);// ���� ����

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

	mergeSort(arr, arr, arr + arrMAXSIZE - 1);


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

// ���� ����: ��������
void  mergeSort(int* pArr, int* pFirst, int* pLast) {
	// ��� �Լ� Ż�� ����
	if (pFirst >= pLast)
		return;

	int* pMid = pFirst + (int)(pLast - pFirst) / 2; // �߰� ������ ��ġ(�ּ�) ���
	mergeSort(pArr, pFirst, pMid);			// ���� �κ����� ����
	mergeSort(pArr, pMid + 1, pLast);		// ������ �κ����� ����

	// ������ �κ������� ����(merge)�� �޸� ���� Ȯ��
	int	num = (int)(pLast - pFirst) + 1;
	int* pTemp = new (nothrow) int[num];
	if (pTemp == nullptr) {
		cout << "���� �޸� ���� �Ҵ� ����!!!" << endl;
		exit(100);
	}

	// ����(merge): ���ĵ� �� �κ����� ����
	int* pi = pFirst;	// ���� ��ġ: ���� �κ�����
	int* pj = pMid + 1;	// ���� ��ġ: ������ �κ�����
	int* pt = pTemp;
	while (pi <= pMid && pj <= pLast) {
		if (*pi <= *pj) 	*pt++ = *pi++;
		else *pt++ = *pj++;
	}
	while (pi <= pMid)	*pt++ = *pi++;
	while (pj <= pLast)	*pt++ = *pj++;

	// ���ĵ� �����ͷ� ���� ������ �籸��
	pi = pFirst;
	pt = pTemp;
	while (pi <= pLast)
		*pi++ = *pt++;
	delete[] pTemp;
}