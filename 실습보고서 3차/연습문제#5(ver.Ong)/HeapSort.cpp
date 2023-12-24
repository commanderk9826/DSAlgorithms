#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10

using namespace std;

// 함수 선언
template <typename E>
void HeapSort(E* pArr, const int num);

template <typename E>
void buildHeap(E* pArr, const int num);

template <typename E>
void percolateDown(E* pArr, const int root, const int num);

template <typename E>
void SWAP(E* pa, E* pb);

template <typename E>
void PRINT(E* pArr, const int num);

template <typename E>
void SWAP(E* pa, E* pb)
{
	E temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;

	return;
}

template <typename E>
void PRINT(E* pArr, const int num)
{
	for (int i = 0; i < num; i++)
	{
		cout.width(3); cout << *(pArr + i);
	}
	cout << endl;

	return;
}

template <typename E>
void buildHeap(E* pArr, const int num)
{
	for (int i = num / 2; i >= 0; i--) percolateDown(pArr, i, num - 1);
	cout << "buildHeap: "; PRINT(pArr, SIZE);
}

template <typename E>
void percolateDown(E* pArr, const int root, const int num)
{
	int child = 2 * root + 1;	// 왼쪽 자식
	int right = 2 * root + 2;	// 오른쪽 자식

	if (child <= num)
	{
		if (right <= num && pArr[child] < pArr[right]) child = right;

		if (pArr[root] < pArr[child])
		{
			SWAP(pArr + root, pArr + child);
			percolateDown(pArr, child, num);
		}
	}
}

template <typename E>
void HeapSort(E* pArr, const int num)
{
	buildHeap(pArr, num);

	for (int i = num - 1; i >= 0; i--)
	{
		SWAP(pArr + 0, pArr + i);
		percolateDown(pArr, 0, i - 1);
	}
}

int main()
{
	int arr[SIZE] = { 0 };

	//초기 난수 생성해 배열에 넣기
	srand((unsigned int)time(NULL));
	for (int i = 0; i < SIZE; i++)  *(arr + i) = rand() % 100;

	cout << "정렬 전: "; PRINT(arr, SIZE);
	HeapSort(arr, SIZE);
	cout << "정렬 후: "; PRINT(arr, SIZE);

	return 0;
}
