#include <iostream>
#include <string>

using namespace std;

bool validateBinary(int num);
int binaryToDecimal(int num);

int main() {
    int num;
    int decimal;
    cout << "20215229 ��ä��" << endl;  
    
    while (true) {//������ ���ö����� ��� �ݺ�
        cout << endl;
        cout << "������(1 �Ǵ� 0): "; 
        cin >> num;
        if (validateBinary(num)) {
            decimal = binaryToDecimal(num);
            cout << endl;
            cout << "�Է��� ������: " << num << endl;
            cout << "��ȯ �� ������ : " << decimal;
            break;
        }
        else {
            cout << "������(1�Ǵ� 0)�� �Է� �����մϴ�!!!";
        }
    }
}

bool validateBinary(int num) {
    string str = to_string(num);//�Է¹��� ������ ���ڿ��� ��ȯ
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > '1') {
            return false;//10������ false
        }
    }
    return true;//2������ true
}

int binaryToDecimal(int num) {
    int sum = 0;
    string str = to_string(num);//�Է¹��� ������ ���ڿ��� ��ȯ
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            sum += 1 << (str.size() - 1 - i);//bit ������ ���� 2���� ���
        }
    }
    return sum;
}