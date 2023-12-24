#include <iostream>
#include <random>       // C++ 11���� �߰�
using namespace std;    // C++11 ����: C ��Ÿ�� ���� ����(srand�� rand �Լ�)

#define arrMAXSIZE 15

template <typename E> void HeapSort(E* pArr, const int num);
template <typename E> void percolateDown(E* pArr, const int root, const int num);
template <typename E> void SWAP(E* pa, E* pb);
template <typename E> void PRINT(E* pArr, const int num);

int main(void)
{
    int		arr[arrMAXSIZE] = { 0 };

    // C++ ��Ÿ�� ���� ����
    random_device rd;		// �õ� ����: random_device ����
    mt19937 gen(rd());	// ���� ���� ����(mt19937) �ʱ�ȭ
    uniform_int_distribution<int> dis(0, 99);	// �յ� ���� ����: ���� ����
    for (int i = 0; i < arrMAXSIZE; i++)
        *(arr + i) = dis(gen);

    cout << "���� ��: ";       PRINT(arr, arrMAXSIZE);
    HeapSort(arr, arrMAXSIZE);
    cout << "���� ��: ";       PRINT(arr, arrMAXSIZE);

    return 0;
}

template <typename E>
void HeapSort(E* pArr, const int num) {
}

template <typename E>
void percolateDown(E* pArr, const int root, const int end) {
}

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
