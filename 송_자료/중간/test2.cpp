#include <iostream>
#define arrMaxsize 10
using namespace std;

int* binarySearch(int* pArr, int* pFirst, int* pLast, int key);
void OUTPUT(int* pArr, int num);

int main() {

	int arr[arrMaxsize] = { 5,9,13,17,21,28,37,46,55,88 };

	cout << "원시 데이터 : ";
	for (int i = 0; i < arrMaxsize; i++) {
		cout.width(3);
		cout << arr[i];
	}
	
	int x;

	while (true) {
		cout << '\n';
		cout << "검색 데이터 입력(검색종료 : 0) ";
		cin >> x;

		if (x == 0) break;

		int* result =binarySearch(arr, arr, arr + arrMaxsize - 1, x);

		if (result == NULL) {
			cout << "없다고!!!" << endl;
			continue;
		}
		else {
			cout << "검색 데이터 위치 : ";
			cout << result - arr + 1 << "번째 위치 " << *result;
		}
	}



	return 0;
}

/*
1. 중간값 찾기
2. pmid == key 면 return
3. key < pmid면 왼쪽에서 다시 찾기
4. key > pmid면 오른쪽에서 다시 찾기
*/
int* binarySearch(int* pArr, int* pFirst, int* pLast, int key) {

	while (pFirst-pArr <= pLast-pArr) {
		int* pmid = pFirst + (pLast - pFirst) / 2;
		if (*pmid == key) return pmid;
		else if (key < *pmid) {
			pLast = pmid - 1;
			continue;
		}
		else if (key > *pmid) {
			pFirst = pmid + 1;
			continue;
		}
	}
	return NULL;
}
