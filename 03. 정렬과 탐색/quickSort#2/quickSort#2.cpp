/*
����: �˰��� ����
������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  quickSort(int* pArr, int* pFirst, int* pLast);// �� ����
int* Partition(int* pArr, int* pfirst, int* plast);

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

//�� ���� : ��������
void quickSort(int* pArr, int* pfirst, int* plast) {

	int* pmid = NULL;
	if (pfirst - pArr < plast - pArr) {
		pmid = Partition(pArr, pfirst, plast);//���� �� ���� ���� ��ġ ���� ��ȯ
		PRINT(pmid, plast - pmid);
		quickSort(pArr, pfirst, pmid - 1);//���� �κ� ����
		quickSort(pArr, pmid + 1, plast);//������ �κ� ����
	}
}

int* Partition(int* pArr, int* pfirst, int* plast) {
	int pivot = *plast; //������ ���Ҹ� ���� ������ ����

	int i = (pfirst - pArr) - 1;

	for (int j = (pfirst - pArr); j < (plast - pArr); j++) {
		if (pArr[j] <= pivot)
			SWAP(pArr + (++i), pArr + j);//���� ���� ����� ��ġ ��Ų��.
	}
	SWAP(pArr + i + 1, plast);

	return pArr + i + 1;//���� ���� ��ġ ���� ��ȯ
}
