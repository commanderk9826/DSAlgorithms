/*
정렬: 알고리즘 구현
계수정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void	contingSort(int* pArr, int num); // 계수정렬

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

	contingSort(arr, arrMAXSIZE);


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


//계수 정렬 
void	contingSort(int* pArr, int num) {
	int* countArr, * sortArr;
	int	maxNum = 0;
	for (int i = 0; i < num; i++)
		if (maxNum < pArr[i])
			maxNum = pArr[i];

	// countArr : 원본 데이터에서 각 항목들의 발생 횟수를 저장한다.
	// 단, 원본 데이터의 값 자체가 countArr의 첨자가 된다.
	countArr = new (nothrow) int[maxNum + 1] { 0 };
	if (countArr == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		return; 
	}
	for (int i = 0; i < num; i++)		countArr[pArr[i]]++;
	for (int i = 1; i <= maxNum; i++)	countArr[i] += countArr[i - 1];

	// sortArr : countArr의 값을 첨자로 하여 원본 데이터를 정렬된 데이터로 구성한다.
	sortArr = new (nothrow) int[num] {0};
	if (countArr == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		exit(100);
	}
	for (int i = num - 1; i >= 0; i--) {
		sortArr[countArr[pArr[i]] - 1] = pArr[i];
		countArr[pArr[i]]--;
		// PRINT(sort, num);
	}

	// 정렬된 데이터(sortArr)로 원본 데이터(pArr)를 재구성한다.
	for (int i = 0; i < num; i++)
		pArr[i] = sortArr[i];

	delete[] countArr;
	delete[] sortArr;
}