/*
정렬: 알고리즘 구현
병합정렬
*/
#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void  mergeSort(int* pArr, int* pFirst, int* pLast);// 병합 정렬
void merge(int* pArr, int* pFirst, int* pMid, int* pLast);

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

	//C++ 스타일 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "20215229 이채훈" << endl;
	cout << endl;

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

//병합 정렬 : 오름차순
void mergeSort(int* pArr, int* pFirst, int* pLast) {

    int* mid = NULL;

    if ((pFirst - pArr) < (pLast - pArr)) {
        mid = pFirst + (pLast - pFirst) / 2;//first와 last 사이의 중간 원소의 위치
        mergeSort(pArr, pFirst, mid); //왼쪽 부분집합 정렬
        mergeSort(pArr, mid + 1, pLast); //오른쪽 부분집합 정렬
        merge(pArr, pFirst, mid, pLast);//정렬된 두 부분집합 병합
    }
}

void merge(int* pArr, int* pFirst, int* pMid, int* pLast) {
    int i = pFirst - pArr;
    int j = (pMid - pArr) + 1;
    int t = i;

    int* tempArr = new int[arrMAXSIZE];

    while (i <= (pMid - pArr) && j <= (pLast - pArr)) {
        if (pArr[i] <= pArr[j]) {
            tempArr[t++] = pArr[i++];
        }
        else {
            tempArr[t++] = pArr[j++];
        }
    }

    while (i <= (pMid - pArr)) tempArr[t++] = pArr[i++];
    while (j <= (pLast - pArr)) tempArr[t++] = pArr[j++];

    //정렬된 상태로 재구성된 temp 배열을 원본 배열 A에 복사
    i = pFirst - pArr;
    t = i;

    while (i <= (pLast - pArr)) pArr[i++] = tempArr[t++];

    delete[] tempArr;
}