/*
정렬: 알고리즘 구현
병합정렬
*/

#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  mergeSort(int* pArr, int* pFirst, int* pLast);// 병합 정렬

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

	mergeSort(arr, arr, arr + arrMAXSIZE - 1);


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

// 병합 정렬: 오름차순
void  mergeSort(int* pArr, int* pFirst, int* pLast) {
	// 재귀 함수 탈출 조건
	if (pFirst >= pLast)
		return;

	int* pMid = pFirst + (int)(pLast - pFirst) / 2; // 중간 원소의 위치(주소) 계산
	mergeSort(pArr, pFirst, pMid);			// 왼쪽 부분집합 정렬
	mergeSort(pArr, pMid + 1, pLast);		// 오른쪽 부분집합 정렬

	// 각각의 부분집합을 병합(merge)할 메모리 공간 확보
	int	num = (int)(pLast - pFirst) + 1;
	int* pTemp = new (nothrow) int[num];
	if (pTemp == nullptr) {
		cout << "동적 메모리 공간 할당 실패!!!" << endl;
		exit(100);
	}

	// 병합(merge): 정렬된 두 부분집합 병합
	int* pi = pFirst;	// 시작 위치: 왼쪽 부분집합
	int* pj = pMid + 1;	// 시작 위치: 오른쪽 부분집합
	int* pt = pTemp;
	while (pi <= pMid && pj <= pLast) {
		if (*pi <= *pj) 	*pt++ = *pi++;
		else *pt++ = *pj++;
	}
	while (pi <= pMid)	*pt++ = *pi++;
	while (pj <= pLast)	*pt++ = *pj++;

	// 정렬된 데이터로 원본 데이터 재구성
	pi = pFirst;
	pt = pTemp;
	while (pi <= pLast)
		*pi++ = *pt++;
	delete[] pTemp;
}