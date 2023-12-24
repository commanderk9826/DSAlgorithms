/*
����: �˰��� ����
������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void	shellSort(int* pArr, int num);		// �� ����
void	intervalSort(int* pArr, int num, int start, int interval);

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

	shellSort(arr, arrMAXSIZE);


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