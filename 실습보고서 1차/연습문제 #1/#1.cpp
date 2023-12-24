#include <iostream>
#include <string>

using namespace std;

bool validateBinary(int num);
int binaryToDecimal(int num);

int main() {
    int num;
    int decimal;
    cout << "20215229 이채훈" << endl;  
    
    while (true) {//이진수 나올때까지 계속 반복
        cout << endl;
        cout << "이진수(1 또는 0): "; 
        cin >> num;
        if (validateBinary(num)) {
            decimal = binaryToDecimal(num);
            cout << endl;
            cout << "입력한 이진수: " << num << endl;
            cout << "변환 된 십진수 : " << decimal;
            break;
        }
        else {
            cout << "이진수(1또는 0)만 입력 가능합니다!!!";
        }
    }
}

bool validateBinary(int num) {
    string str = to_string(num);//입력받은 정수를 문자열로 전환
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > '1') {
            return false;//10진수면 false
        }
    }
    return true;//2진수면 true
}

int binaryToDecimal(int num) {
    int sum = 0;
    string str = to_string(num);//입력받은 정수를 문자열로 전환
    for (int i = str.size() - 1; i >= 0; i--) {
        if (str[i] == '1') {
            sum += 1 << (str.size() - 1 - i);//bit 연산을 통해 2진수 계산
        }
    }
    return sum;
}