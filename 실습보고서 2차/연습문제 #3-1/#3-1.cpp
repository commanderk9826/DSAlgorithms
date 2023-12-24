#include <iostream>
#define arrMAXSIZE 10
using namespace std;

// 이진 탐색 : 재귀적 용법
int	binarySearch(int* pArr, int  first, int  last, int  key);

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}

int main(void)
{
	int	arr[arrMAXSIZE] = { 5, 9, 13, 17, 21, 28, 37, 46, 55, 88 };

	cout << "20215229 이채훈" << endl;
	cout << endl;

	cout << "원시 데이터: "; PRINT(arr, arrMAXSIZE);

	int	key;
	while (true) {
		cout << "검색 데이터 입력(검색 종료: 0) : "; cin >> key;
		if (key == 0)
			break;

		int index = binarySearch(arr, 0, arrMAXSIZE - 1, key);
		if (index == -1)
			cout << "없다고!!!" << endl;
		else
			cout << "검색 데이터: " << arr[index] << "번째 위치 " << index + 1 << endl;
	}
	return 0;
}

// 이진탐색: 재귀적용법
int	binarySearch(int* pArr, int  first, int  last, int  key) {
	// 재귀함수의 탈출 조건
	if (first > last)
		return  -1;

	// 검색범위의 중간 원소의 위치 값 계산
	int	index, mid = (first + last) / 2;

	if (*(pArr + mid) == key)
		return  mid;
	else if (*(pArr + mid) > key)
		index = binarySearch(pArr, first, mid - 1, key);
	else if (*(pArr + mid) < key)
		index = binarySearch(pArr, mid + 1, last, key);

	return index;
}
