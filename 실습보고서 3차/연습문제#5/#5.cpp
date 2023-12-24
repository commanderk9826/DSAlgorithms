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

    // C++ ��Ÿ�� ���� ����
    random_device rd;		// �õ� ����: random_device ����
    mt19937 gen(rd());	// ���� ���� ����(mt19937) �ʱ�ȭ
    uniform_int_distribution<int> dis(0, 99);	// �յ� ���� ����: ���� ����

    for (int i = 0; i < arrMAXSIZE; i++)
        *(arr + i) = dis(gen);

    cout << "20215229 ��ä��\n" << endl;
    cout << "���� ��: "; PRINT(arr, arrMAXSIZE);
    buildHeap(arr, arrMAXSIZE);
    cout << "buildheap: "; PRINT(arr, arrMAXSIZE);
    HeapSort(arr, arrMAXSIZE);
    cout << "���� ��: "; PRINT(arr, arrMAXSIZE);

    return 0;
}

template <typename E>
void percolateDown(E* pArr, const int root, const int end) {
    int parent = root;
    int child;

    while ((parent * 2) + 1 <= end) {
        // ���� �ڽ�
        child = (parent * 2) + 1;  

        // ������ �ڽ��� �ְ�, ������ �ڽ��� �� ũ�ٸ� child�� ������ �ڽ����� �Ҵ�
        if (child + 1 <= end && pArr[child] < pArr[child + 1]) {
            ++child;
        }

        // �θ� �ڽĺ��� ������ ��ȯ
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
    // ������ ��� ����� �ε��� ���
    int startIdx = (num / 2) - 1;

    // ������ ��� ������ ��Ʈ���� �� �Ӽ��� �����ϸ鼭 �ݺ�
    for (int i = startIdx; i >= 0; --i) {
        percolateDown(pArr, i, num - 1);
    }
}

template <typename E>
void HeapSort(E* pArr, const int num) {
    // 1. �� ����
    buildHeap(pArr, num);

    // 2. �� ����
    for (int i = num - 1; i > 0; --i) {
        // �ִ� ���� �迭 ������ �̵�
        SWAP(&pArr[0], &pArr[i]);
        // �� �Ӽ� �����ϸ鼭 �� ũ�� ����
        percolateDown(pArr, 0, i - 1);
    }
}

