#include <iostream>
#define arrMaxsize 10
using namespace std;

int* binarySearch(int* pArr, int* pFirst, int* pLast, int key);
void OUTPUT(int* pArr, int num);

int main() {

	int arr[arrMaxsize] = { 5,9,13,17,21,28,37,46,55,88 };

	cout << "���� ������ : ";
	for (int i = 0; i < arrMaxsize; i++) {
		cout.width(3);
		cout << arr[i];
	}
	
	int x;

	while (true) {
		cout << '\n';
		cout << "�˻� ������ �Է�(�˻����� : 0) ";
		cin >> x;

		if (x == 0) break;

		int* result =binarySearch(arr, arr, arr + arrMaxsize - 1, x);

		if (result == NULL) {
			cout << "���ٰ�!!!" << endl;
			continue;
		}
		else {
			cout << "�˻� ������ ��ġ : ";
			cout << result - arr + 1 << "��° ��ġ " << *result;
		}
	}



	return 0;
}

/*
1. �߰��� ã��
2. pmid == key �� return
3. key < pmid�� ���ʿ��� �ٽ� ã��
4. key > pmid�� �����ʿ��� �ٽ� ã��
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
