#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10];
vector<int> v;

void inputValues() {
    cout << "������ ���� 10���� �Է��ϼ���..." << endl;
    for (int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] : ";
        cin >> arr[i];
        v.push_back(arr[i]);
    }
}//�� �Է� �� ����, ���� �迭�� �� �߰�

int main(void) {
    cout << "20215229 ��ä��" << endl;
    cout << endl;

    inputValues(); 

    sort(arr, arr + 10);//���� �迭 �������� ����

    cout << "����(���� �迭) : ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }//���� �迭 ���
    cout << endl;

    sort(v.begin(), v.end());//���� �迭 �������� ����
    cout << "����(���� �迭) : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }//���� �迭 ���
    return 0;
}
