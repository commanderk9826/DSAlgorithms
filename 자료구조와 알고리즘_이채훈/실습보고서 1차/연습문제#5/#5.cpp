#include <iostream>
#include <string>
using namespace std;

int my_stoi(const string& rStr);

int main(void) {
    string str;
    cout << "20215229 ��ä��" << endl;
    cout << endl;
    cout << "������ ��ȯ�� ���ڿ� �Է�: "; cin >> str;
    int result = my_stoi(str);
    cout << "�Է� ���ڿ�: " << str << ", " << "��ȯ�� ����(int): " << result;
}

int my_stoi(const string& rStr) {
    const char* ptr = rStr.c_str();
    //string�� ���ڿ��� ��ȯ�ϴ� ����Լ� c_str()
  
    int result = 0;
    int sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ++ptr;
    }//ù��° ������ ���� �Ǵ�

    else if (*ptr == '+') {
        ++ptr;
    }//ù��° ������ ��� �Ǵ�

    while (*ptr != NULL) {
        if (*ptr >= '0' && *ptr <= '9') {
            result = result * 10 + (*ptr - '0');
        }
        else {
            break;
        }
        ++ptr; 
    }//0~9�̿��� ���ڰ� ������ ���, ���� ��ȯ �۾� �ߴ�

    return result * sign;
    //����*��ȣ(sign) ���� ��ȯ
}









