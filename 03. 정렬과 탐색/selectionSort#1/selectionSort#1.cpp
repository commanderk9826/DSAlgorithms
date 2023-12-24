/*
정렬: 알고리즘 구현
선택정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void selectionSort(int* pArr, int num);	// 선택 정렬

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

	selectionSort(arr, arrMAXSIZE);


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

// 선택 정렬: 오름차순
void   selectionSort(int* pArr, int  num) {
	int* pSm;
	for (int i = 0; i < num; i++) {
		pSm = pArr + i;
		for (int j = i; j < num; j++)
			// 가장 작은 값을 가진 원소의 위치(주소) 탐색
			if (*pSm > *(pArr + j))
				pSm = pArr + j;
		// 가장 작은 값을 선택: 현재 값과 교환
		SWAP(pSm, pArr + i);
	}
}