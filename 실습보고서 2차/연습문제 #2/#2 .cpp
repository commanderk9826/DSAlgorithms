#include <iostream>
#include <random>	
#define arrMAXSIZE 15
using namespace std;

void insertionSort(int* pArr, int num);	// 삽입 정렬

void  PRINT(int* pArr, int  num) {
	for (int i = 0; i < num; i++) {
		cout.width(3);
		cout << *(pArr + i);
	}
	cout << endl;
}

int main(void)
{
	//배열 생성
	int	arr[arrMAXSIZE] = { 0 };

	//C++ 스타일 난수 생성
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0, 99);

	cout << "20215229 이채훈" << endl;
	cout << endl;

	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = dis(gen);

	cout << "정렬 전: ";
	PRINT(arr, arrMAXSIZE);

	insertionSort(arr, arrMAXSIZE);


	cout << "정렬 후: ";
	PRINT(arr, arrMAXSIZE);

	return 0;
}


// 삽입 정렬: 오름차순
void  insertionSort(int* pArr, int num) {
		int	i, j, temp;
	for (i = 1; i < num; i++) {
			temp = *(pArr + i);
		// temp 가 들어갈 공간 확보 
		for (j = i - 1; j >= 0 && *(pArr + j) > temp; j--)
			*(pArr + j + 1) = *(pArr + j);
		*(pArr + j + 1) = temp;
		PRINT(pArr, num);
	}
}


	

