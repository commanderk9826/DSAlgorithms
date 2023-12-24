/*
����: �˰��� ����
��������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  bubbleSortUp(int* pArr, int num);		// ���� ���� ����(���)�� �˰���
//void bubbleSort(int* pArr, int num);		// ���� ����

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

	bubbleSortUp(arr, arrMAXSIZE);
	//bubbleSort(arr, arrMAXSIZE);

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
/*
// ���� ����: ��������
void  bubbleSort(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num - 1; j > 0; j--)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
	}
}
*/

// ���� ����: ����(���)�� �˰��� 
void  bubbleSortUp(int* pArr, int num) {
	for (int i = 0; i < num; i++)
	{
		bool state = true;
		for (int j = num - 1; j > 0; j--)
		{
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
			state = false;
		}
		if (state = true)
			return;
	}
}

