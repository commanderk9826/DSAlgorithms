/*
����: �˰��� ����
��������
*/
#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  mergeSort(int* pArr, int* pFirst, int* pLast);// ���� ����
void merge(int* pArr, int* pFirst, int* pMid, int* pLast);

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

	//C++ ��Ÿ�� ���� ����
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "20215229 ��ä��" << endl;
	cout << endl;

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

//���� ���� : ��������
void mergeSort(int* pArr, int* pFirst, int* pLast) {

    int* mid = NULL;

    if ((pFirst - pArr) < (pLast - pArr)) {
        mid = pFirst + (pLast - pFirst) / 2;//first�� last ������ �߰� ������ ��ġ
        mergeSort(pArr, pFirst, mid); //���� �κ����� ����
        mergeSort(pArr, mid + 1, pLast); //������ �κ����� ����
        merge(pArr, pFirst, mid, pLast);//���ĵ� �� �κ����� ����
    }
}

void merge(int* pArr, int* pFirst, int* pMid, int* pLast) {
    int i = pFirst - pArr;
    int j = (pMid - pArr) + 1;
    int t = i;

    int* tempArr = new int[arrMAXSIZE];

    while (i <= (pMid - pArr) && j <= (pLast - pArr)) {
        if (pArr[i] <= pArr[j]) {
            tempArr[t++] = pArr[i++];
        }
        else {
            tempArr[t++] = pArr[j++];
        }
    }

    while (i <= (pMid - pArr)) tempArr[t++] = pArr[i++];
    while (j <= (pLast - pArr)) tempArr[t++] = pArr[j++];

    //���ĵ� ���·� �籸���� temp �迭�� ���� �迭 A�� ����
    i = pFirst - pArr;
    t = i;

    while (i <= (pLast - pArr)) pArr[i++] = tempArr[t++];

    delete[] tempArr;
}