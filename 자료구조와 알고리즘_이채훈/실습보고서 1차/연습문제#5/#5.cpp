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
    const char* ptr = rStr.c_str();
    //string를 문자열로 변환하는 멤버함수 c_str()
  
    int result = 0;
    int sign = 1;

    if (*ptr == '-') {
        sign = -1;
        ++ptr;
    }//첫번째 문자의 음수 판단

    else if (*ptr == '+') {
        ++ptr;
    }//첫번째 문자의 양수 판단

    while (*ptr != NULL) {
        if (*ptr >= '0' && *ptr <= '9') {
            result = result * 10 + (*ptr - '0');
        }
        else {
            break;
        }
        ++ptr; 
    }//0~9이외의 문자가 존재할 경우, 숫자 변환 작업 중단

    return result * sign;
    //숫자*부호(sign) 값을 반환
}









