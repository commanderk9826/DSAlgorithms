/*
정렬: 알고리즘 구현
버블정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  bubbleSortUp(int* pArr, int num);		// 버블 정렬 변형(향상)된 알고리즘
//void bubbleSort(int* pArr, int num);		// 버블 정렬

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

	bubbleSortUp(arr, arrMAXSIZE);
	//bubbleSort(arr, arrMAXSIZE);

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
/*
// 버블 정렬: 오름차순
void  bubbleSort(int* pArr, int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num - 1; j > 0; j--)
			if (*(pArr + j) < *(pArr + j - 1))
				SWAP(pArr + j, pArr + j - 1);
	}
}
*/

// 버블 정렬: 변형(향상)된 알고리즘 
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

