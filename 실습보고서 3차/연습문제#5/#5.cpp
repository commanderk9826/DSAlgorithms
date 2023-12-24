#include <iostream>
#include <random>       
using namespace std;    

#define arrMAXSIZE 15

template <typename E> void HeapSort(E* pArr, const int num);
template <typename E> void buildHeap(E* pArr, const int num);
template <typename E> void percolateDown(E* pArr, const int root, const int num);

template <typename E> void SWAP(E* pa, E* pb) {
    E	temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

template <typename E> void PRINT(E* pArr, const int num) {
    for (int i = 0; i < num; i++)
        cout << pArr[i] << " ";
    cout << endl;
}

int main(void)
{
    int		arr[arrMAXSIZE] = { 0 };

    // C++ 스타일 난수 생성
    random_device rd;		// 시드 설정: random_device 생성
    mt19937 gen(rd());	// 난수 생성 엔진(mt19937) 초기화
    uniform_int_distribution<int> dis(0, 99);	// 균등 분포 정의: 범위 지정

    for (int i = 0; i < arrMAXSIZE; i++)
        *(arr + i) = dis(gen);

    cout << "20215229 이채훈\n" << endl;
    cout << "정렬 전: "; PRINT(arr, arrMAXSIZE);
    buildHeap(arr, arrMAXSIZE);
    cout << "buildheap: "; PRINT(arr, arrMAXSIZE);
    HeapSort(arr, arrMAXSIZE);
    cout << "정렬 후: "; PRINT(arr, arrMAXSIZE);

    return 0;
}

template <typename E>
void percolateDown(E* pArr, const int root, const int end) {
    int parent = root;
    int child;

    while ((parent * 2) + 1 <= end) {
        // 왼쪽 자식
        child = (parent * 2) + 1;  

        // 오른쪽 자식이 있고, 오른쪽 자식이 더 크다면 child를 오른쪽 자식으로 할당
        if (child + 1 <= end && pArr[child] < pArr[child + 1]) {
            ++child;
        }

        // 부모가 자식보다 작으면 교환
        if (pArr[parent] < pArr[child]) {
            SWAP(&pArr[parent], &pArr[child]);
            parent = child;
        }
        else {
            break;
        }
    }
}

template <typename E>
void buildHeap(E* pArr, const int num) {
    // 마지막 비닐 노드의 인덱스 계산
    int startIdx = (num / 2) - 1;

    // 마지막 비닐 노드부터 루트까지 힙 속성을 유지하면서 반복
    for (int i = startIdx; i >= 0; --i) {
        percolateDown(pArr, i, num - 1);
    }
}

template <typename E>
void HeapSort(E* pArr, const int num) {
    // 1. 힙 생성
    buildHeap(pArr, num);

    // 2. 힙 정렬
    for (int i = num - 1; i > 0; --i) {
        // 최대 값을 배열 끝으로 이동
        SWAP(&pArr[0], &pArr[i]);
        // 힙 속성 유지하면서 힙 크기 감소
        percolateDown(pArr, 0, i - 1);
    }
}

