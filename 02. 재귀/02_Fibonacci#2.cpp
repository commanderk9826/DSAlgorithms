/*
02. ���
�Ǻ���ġ ����:���� ���α׷���
#�������� 2-2: �Ǻ���ġ ����--������� ���
*/
#include <iostream>

using namespace std;

int Fibo(int num);

int main(void) {
    int num;
    cout << "### �Ǻ���ġ ���� ���ϱ� ###" << endl;
    cout << "���° �������� ����ұ��? : "; cin >> num;
    for (int i = 1; i <= num; i++) {
        cout.width(8);
        if (i % 5)cout << Fibo(i);
        else cout << Fibo(i) << endl;
    }
}

int Fibo(int num) {
    if (num == 1 || num == 2)
        return 1;
    //���� �޸� �Ҵ�
    int* pArr = new int[num];
    if (pArr == NULL) {
        cout << "�޸� �Ҵ� ����!!!" << endl;
        exit(100);
    }
    int i, temp;
    *pArr = *(pArr + 1) = 1;
    for (i = 2; i <num ; i++) {//for�� ���� ���� <=/<, num+1->num
        *(pArr + i) = *(pArr + i - 1) + *(pArr + i - 2);
    }
    temp = *(pArr + i - 1);
   
    delete []pArr;//���� �޸� �Ҵ� ������ �����ȿ� �� �ִ� ����, for���� �߰�ȣ�� �߰��ؼ� ����
    return temp;
}
