/*
정렬: 알고리즘 구현
쉘정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void	shellSort(int* pArr, int num);		// 쉘 정렬
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
	//C 스타일 난수 생성(srand와 rand 함수)
	srand(static_cast<unsigned int>(time(nullptr)));
	static_cast<int>(rand() % (99 + 1UL - 0)) + 0;
	*/
	//C++ 스타일 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);


	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "정렬 전: ";
	PRINT(arr, arrMAXSIZE);

	shellSort(arr, arrMAXSIZE);


	cout << "정렬 후: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}

void  SWAP(int* pa, int* pb) {
	int	temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

// 쉘 정렬: 오름차순
void  shellSort(int* pArr, int num) {
	int	interval = num;
	while (interval >= 1) {
		interval /= 2;
		for (int i = 0; i < interval; i++)
			intervalSort(pArr, num, i, interval);
		printf("interval: %d, ", interval);
	}
}

// 쉘 정렬에 쓰이는 삽입 정렬: interval 간격만큼 삽입 정렬
void  intervalSort(int* pArr, int num, int start, int interval) {
	int	i, j, temp;
	for (i = start; i < num; i += interval) {
		temp = *(pArr + i);
		for (j = i - interval; j >= 0 && *(pArr + j) > temp; j -= interval)
			*(pArr + j + interval) = *(pArr + j);
		*(pArr + j + interval) = temp;
	}
}