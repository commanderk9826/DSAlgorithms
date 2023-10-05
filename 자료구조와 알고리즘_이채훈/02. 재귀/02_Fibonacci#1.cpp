/*
02. ���
�Ǻ���ġ ����:���� ���α׷���
#�������� 2-3: �Ǻ���ġ ����--������� ���
*/
#include <iostream>

using namespace std;

int Fibo(int num);

int main(void) {
    int num;
    cout << "### �Ǻ���ġ ���� ���ϱ�###" << endl;
    cout << "���° �������� ����ұ��? : "; cin >> num;
    for (int i = 1; i <=num; i++) {
        cout.width(8);
        if (i % 5)cout << Fibo(i);
        else cout << Fibo(i) << endl;
    }
}

int Fibo(int num) {
    if (num == 1 || num == 2)
        return 1;
    int first = 1, second = 1, res = 0;
    for (int i = 3; i <= num; ++i) {
        res = first + second;
        first = second;
        second = res;
    }
    return res;
}
