#include <iostream>

using namespace std;

template<class T>
void printArr(const T* pArr, const int num) {

	for (int i = 0; i < num; i++) {
		cout << *(pArr + i) << " ";
	}
	cout << endl;
}
char str[] = "Hi ~ Clickseo";
int iarr[] = { 10, 20 , 30, 40, 50 };
double darr[] = { 10.5, 20.5, 30.5, 40.5, 50.5 };

int main(void) {
	cout << "20215229 ÀÌÃ¤ÈÆ" << endl;
	cout << endl;

	printArr(str, sizeof(str) / sizeof(char));
	printArr(iarr, sizeof(iarr) / sizeof(int));
	printArr(darr, sizeof(darr) / sizeof(double));

	return 0;
}