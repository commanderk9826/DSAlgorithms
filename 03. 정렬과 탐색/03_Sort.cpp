/*
����: �˰��� ����
1) �������� ���� �˰��� : ����.����.����.�� ����
2) ��� ���� �˰��� : ��.���� ����
3) Ư�� ���� �˰��� : ���.���.��Ŷ ����
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void	selectionSort(int* pArr, int num);	// ���� ����
void	bubbleSort(int* pArr, int num);		// ���� ����
void	insertionSort(int* pArr, int num);	// ���� ����
void	shellSort(int* pArr, int num);		// �� ����
void	intervalSort(int* pArr, int num, int start, int interval);
void	contingSort(int* pArr, int num); // ���.���.��Ŷ ����

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

	//C ��Ÿ�� ���� ����(srand�� rand �Լ�)
		srand(static_cast<unsigned int>(time(nullptr)));
		static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	
	/*C++ ��Ÿ�� ���� ����
	random_device rd;		
	mt19937 gen(rd());		
	uniform_int_distribution<int> dis(0, 99);
	*/
		
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);
	
	cout << "���� ��: ";
	PRINT(arr, arrMAXSIZE);
	
	//selectionSort(arr, arrMAXSIZE);
	//bubbleSort(arr, arrMAXSIZE);
	//insertionSort(arr, arrMAXSIZE);
	//shellSort(arr, arrMAXSIZE);
	//quickSort(arr, arr, arr+arrMAXSIZE-1);
	//mergeSort(arr, arr, arr + arrMAXSIZE - 1);
	//contingSort(arr, arrMAXSIZE);
		
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
void   selectionSort(int* pArr, int  num) {
	int* pSm;
	for (int i = 0; i < num; i++) {
		pSm = pArr + i;
		for (int j = i; j < num; j++)
		// ���� ���� ���� ���� ������ ��ġ(�ּ�) Ž��
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// ���� ���� ���� ����: ���� ���� ��ȯ
		SWAP(pSm, pArr + i);
	}
}

// ���� ����: ��������
void  bubbleSort(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num - 1; j > 0; j--)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
	}
}

// ���� ����: ����(���)�� �˰��� 
void  bubbleSortUp(int* pArr, int num) {
	for (int i = 0; i < num; i++) 
	{
		bool state = TRUE;
		for (int j = num - 1; j > 0; j--)
		{
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
				state=FALSE;
		}
		if(state=TRUE)
		return;
	}
}

// ���� ����: ��������
void  insertionSort(int* pArr, int num) {
	int	i, j, temp;
	for (i = 1; i < num; i++) {
		temp = *(pArr + i);
		// temp �� �� ���� Ȯ��
		for (j = i - 1; j >= 0 && *(pArr + j) > temp; j--)
			*(pArr + j + 1) = *(pArr + j);
		*(pArr + j + 1) = temp;
	}
}

// �� ����: ��������
void  shellSort(int* pArr, int num) {
	int	interval = num;
	while (interval >= 1) {
		interval /= 2;
		for (int i = 0; i < interval; i++)
			intervalSort(pArr, num, i, interval);
		printf("interval: %d, ", interval);
	}
}

// �� ���Ŀ� ���̴� ���� ����: interval ���ݸ�ŭ ���� ����
void  intervalSort(int* pArr, int num, int start, int interval) {
	int	i, j, temp;
	for (i = start; i < num; i += interval) {
		temp = *(pArr + i);
		for (j = i - interval; j >= 0 && *(pArr + j) > temp; j -= interval)
			*(pArr + j + interval) = *(pArr + j);
		*(pArr + j + interval) = temp;
	}
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

//��� ���� 
void	contingSort(int* pArr, int num) {
	int* countArr, * sortArr;
	int	maxNum = 0;
	for (int i = 0; i < num; i++)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	// countArr : ���� �����Ϳ��� �� �׸���� �߻� Ƚ���� �����Ѵ�.
	// ��, ���� �������� �� ��ü�� countArr�� ÷�ڰ� �ȴ�.
	countArr = new (nothrow) int[maxNum + 1]{ 0 };
	if (countArr == nullptr) {
		cout << "���� �޸� ���� �Ҵ� ����!!!" << endl;
		return;�� 
	}
	for (int i = 0; i < num; i++)		countArr[pArr[i]]++;
	for (int i = 1; i <= maxNum; i++)	countArr[i] += countArr[i - 1];

	// sortArr : countArr�� ���� ÷�ڷ� �Ͽ� ���� �����͸� ���ĵ� �����ͷ� �����Ѵ�.
	sortArr = new (nothrow) int[num] {0};
	if (countArr == nullptr) {
		cout << "���� �޸� ���� �Ҵ� ����!!!" << endl;
		exit(100);
	}
	for (int i = num - 1; i >= 0; i--) {
		sortArr[countArr[pArr[i]] - 1] = pArr[i];
		countArr[pArr[i]]--;
		// PRINT(sort, num);
	}

	// ���ĵ� ������(sortArr)�� ���� ������(pArr)�� �籸���Ѵ�.
	for (int i = 0; i < num; i++)
		pArr[i] = sortArr[i];

	delete[] countArr;
	delete[] sortArr;
}
