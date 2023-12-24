/*
정렬: 알고리즘 구현
퀵정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  quickSort(int* pArr, int* pFirst, int* pLast);// 퀵 정렬
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

	quickSort(arr, arr, arr + arrMAXSIZE - 1);


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

//퀵 정렬 : 오름차순
void quickSort(int* pArr, int* pfirst, int* plast) {

	int* pmid = NULL;
	if (pfirst - pArr < plast - pArr) {
		pmid = Partition(pArr, pfirst, plast);//분할 후 기준 값의 위치 값을 반환
		PRINT(pmid, plast - pmid);
		quickSort(pArr, pfirst, pmid - 1);//왼쪽 부분 정렬
		quickSort(pArr, pmid + 1, plast);//오른쪽 부분 정렬
	}
}

int* Partition(int* pArr, int* pfirst, int* plast) {
	int pivot = *plast; //마지막 원소를 기준 값으로 선택

	int i = (pfirst - pArr) - 1;

	for (int j = (pfirst - pArr); j < (plast - pArr); j++) {
		if (pArr[j] <= pivot)
			SWAP(pArr + (++i), pArr + j);//기준 값을 가운데로 위치 시킨다.
	}
	SWAP(pArr + i + 1, plast);

	return pArr + i + 1;//기준 값의 위치 값을 반환
}
