#include <iostream>
#include <string>
using namespace std;

int my_stoi(const string& rStr);

int main(void) {
    string str;
    cout << "20215229 이채훈" << endl;
    cout << endl;
    cout << "정수로 변환할 문자열 입력: "; cin >> str;
    int result = my_stoi(str);
    cout << "입력 문자열: " << str << ", " << "변환된 숫자(int): " << result;
}

int my_stoi(const string& rStr) {
    const char* ptr = rStr.c_str();//문자열의 첫번째 문자에 대한 포인터
  
    int result = 0;
    int sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ++ptr;
    }
    else if (*ptr == '+') {
        ++ptr;
    }

    while (*ptr != NULL) {
        if (*ptr >= '0' && *ptr <= '9') {
            result = result * 10 + (*ptr - '0');
        }
        else {
            break;
        }
        ++ptr; 
    }
    return result * sign;
}









