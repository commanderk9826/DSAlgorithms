#include <iostream>

using namespace std;

template<class T>
void printArr(const T* pArr, const int num) {

	for (int i = 0; i < num; i++) {
		cout << *(pArr + i) << " ";
	}
	cout << endl;
}//정의된 배열의 원소들(자료형 상관x)을 출력하는 함수.

char str[] = "Hi ~ Clickseo";
int iarr[] = { 10, 20 , 30, 40, 50 };
double darr[] = { 10.5, 20.5, 30.5, 40.5, 50.5 };
//char, int, double형 배열 선언 및 초기화;

int main(void) {
	cout << "20215229 이채훈" << endl;
	cout << endl;

	printArr(str, sizeof(str) / sizeof(char));
	printArr(iarr, sizeof(iarr) / sizeof(int));
	printArr(darr, sizeof(darr) / sizeof(double));

	return 0;
}