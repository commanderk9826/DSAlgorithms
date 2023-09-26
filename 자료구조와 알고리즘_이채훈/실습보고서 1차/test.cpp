#include <string>
#include <iostream>
using namespace std;

int main (void){

    string s="123456789";
    cout<<"string s vlaue : "<<s<<endl;
    int stoint = stoi(s);
    cout << "converted s value(INT) : "<<stoint<<endl;
    return 0;
}
/*
실행결과
string s value : 123456789
converted s value(INT) : 123456789
*/
/*
stoid는 선행 공백 문자, +/- 기호, 16진수 접두사(0x또는0X)
, 여러 개의 0을 처리하고 정수를 올바르게 반환 할 수 있음.
숫자 앞의 다른 문자는 처리할수 없으며, 하나를 찾으면,
std::invalid_argumetn 예외가 발생함.
*/