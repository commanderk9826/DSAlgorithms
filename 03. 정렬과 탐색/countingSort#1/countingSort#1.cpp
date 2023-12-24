/*
����: �˰��� ����
�������
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void	contingSort(int* pArr, int num); // �������

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

	contingSort(arr, arrMAXSIZE);


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


//��� ���� 
void	contingSort(int* pArr, int num) {
	int* countArr, * sortArr;
	int	maxNum = 0;
	for (int i = 0; i < num; i++)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	// countArr : ���� �����Ϳ��� �� �׸���� �߻� Ƚ���� �����Ѵ�.
	// ��, ���� �������� �� ��ü�� countArr�� ÷�ڰ� �ȴ�.
	countArr = new (nothrow) int[maxNum + 1] { 0 };
	if (countArr == nullptr) {
		cout << "���� �޸� ���� �Ҵ� ����!!!" << endl;
		return; 
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