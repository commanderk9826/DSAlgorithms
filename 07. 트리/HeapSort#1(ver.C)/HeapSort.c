#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define arrMAXSIZE 10
typedef int element;

void HeapSort(element* pArr, const int num);
void buildHeap(element* pArr, const int num);
void percolateDown(element* pArr, const int root, const int end);
void SWAP(element* pa, element* pb);
void PRINT(element* pArr, const int num);

int main(void) {
	int arr[arrMAXSIZE] = { 0 };

	//������ ���� ����: 0~99������ ����
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arrMAXSIZE; i++)
		*(arr + i) = rand() % 100;

	printf("���� ��: "); PRINT(arr, arrMAXSIZE);
	HeapSort(arr, arrMAXSIZE);
	printf("���� ��: "); PRINT(arr, arrMAXSIZE);

	return 0;
}

//HeapSort: �� ����
void HeapSort(element* pArr, const int num) {
	buildHeap(pArr, num);

	for(int i=num-1; i>=0; i--){
		//A[i] = deleteMax();
		//i��° ��ġ�� ���� ū ���� ����
		SWAP(pArr, pArr + i);

		//pArr[0]�� �ڷ� �̵����� pArr[0:i-1]�� �ִ� ������ �籸��
		percolateDown(pArr, 0, i - 1);
	}
}

//buileheap: �ִ� �� ����
void buildHeap(element* pArr, const int num) {
	for (int i = num / 2; i >= 0; i--)
		percolateDown(pArr, i, num);
	//print("buildHeap: "); PRINT(pArr, arrMAXSIZE);
}

void percolateDown(element* pArr, const int root, const int end) {
	int child = 2 * root + 1;//���� �ڽ�
	int right = 2 * root + 2;//������ �ڽ�
	if (child <= end) {
		if (right <= end && pArr[child] < pArr[right])
			child = right;
		//child: A[2k+1]�� A[2k+2] �߿� ū ������ �ε���

		if (pArr[root] < pArr[child]) {
			SWAP(pArr + root, pArr + child);
			percolateDown(pArr, child, end);
		}
	}
}

void SWAP(element* pa, element* pb) {
	element temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
	return;
}

void PRINT(element* pArr, const int num) {
	for (int i = 0; i < num; i++)
		printf("%3d", *(pArr + i));
	printf("\n");
	return;
}