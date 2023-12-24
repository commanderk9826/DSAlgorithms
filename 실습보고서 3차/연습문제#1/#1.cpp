#include <iostream>
#include <stack>
#include <string>

using namespace std;

//( : -1, ) : -2, [ : -3, ]: -4
int bracket(string str) {
    stack <int> s;
    int len = str.length();
    int temp = 0;
    int result = 0;

    for (int i = 0; i < len; i++) {
        //열린 괄호인 경우
        if (str[i] == '(') s.push(-1);

        //닫힌 대괄호인 경우
        else if (str[i] == '[') s.push(-3);
        
        //예외1 : 닫힌 괄호가 더 많은 경우
        else if (s.empty()) 
            return 0;

        else {
            //스택의 맨위가 열린 괄호이고, 현재 괄호가 닫힌 괄호인 경우
            if (s.top() == -1 && str[i] == ')') {
                s.pop();
                s.push(2);
            }

            //스택의 맨위가 열린 대괄호이고, 현재 괄호가 닫힌 대괄호인 경우
            else if (s.top() == -3 && str[i] == ']') {
                s.pop();
                s.push(3);
            }
            //s.top()이 숫자인 경우, 예외3 : 괄호의 짝이 맞지 않는 경우
            else {
                temp = 0;

                //스택이 비거나, 열린 괄호를 만날 때까지 값을 더함
                while (s.top() != -1 && s.top() != -3) {
                    temp += s.top();
                    s.pop();

                    // 예외1 : 닫힌 괄호가 더 많은 경우
                    if (s.empty()) 
                        return 0;
                }

                //스택의 맨 위가 열린 괄호이고, 현재 괄호가 닫힌 괄호인 경우
                if (s.top() == -1 && str[i] == ')') {
                    temp *= 2;
                    s.pop();
                }

                //스택의 맨 위가 열린 대괄호이고, 현재 괄호가 닫힌 대괄호인 경우
                else if (s.top() == -3 && str[i] == ']') {
                    temp *= 3;
                    s.pop();
                }

                // 예외3 : 괄호의 짝이 맞지 않는 경우
                else
                    return 0;  

                s.push(temp);
            }
        }
    }

    //스택에 남아 있는 값들을 더함
    while (!s.empty()) {
        // 예외 2 : 열린괄호가 더 많은 경우
        if (s.top() == -1 || s.top() == -3) 
            return 0;

        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    string st;

    cout << " 20215229 이채훈 " << endl;
    cout << "괄호열 :"; cin >> st;
    cout << "괄호열의 값(올바르지 않은 괄호열: 0): "<<bracket(st);
}



