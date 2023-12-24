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
        //���� ��ȣ�� ���
        if (str[i] == '(') s.push(-1);

        //���� ���ȣ�� ���
        else if (str[i] == '[') s.push(-3);
        
        //����1 : ���� ��ȣ�� �� ���� ���
        else if (s.empty()) 
            return 0;

        else {
            //������ ������ ���� ��ȣ�̰�, ���� ��ȣ�� ���� ��ȣ�� ���
            if (s.top() == -1 && str[i] == ')') {
                s.pop();
                s.push(2);
            }

            //������ ������ ���� ���ȣ�̰�, ���� ��ȣ�� ���� ���ȣ�� ���
            else if (s.top() == -3 && str[i] == ']') {
                s.pop();
                s.push(3);
            }
            //s.top()�� ������ ���, ����3 : ��ȣ�� ¦�� ���� �ʴ� ���
            else {
                temp = 0;

                //������ ��ų�, ���� ��ȣ�� ���� ������ ���� ����
                while (s.top() != -1 && s.top() != -3) {
                    temp += s.top();
                    s.pop();

                    // ����1 : ���� ��ȣ�� �� ���� ���
                    if (s.empty()) 
                        return 0;
                }

                //������ �� ���� ���� ��ȣ�̰�, ���� ��ȣ�� ���� ��ȣ�� ���
                if (s.top() == -1 && str[i] == ')') {
                    temp *= 2;
                    s.pop();
                }

                //������ �� ���� ���� ���ȣ�̰�, ���� ��ȣ�� ���� ���ȣ�� ���
                else if (s.top() == -3 && str[i] == ']') {
                    temp *= 3;
                    s.pop();
                }

                // ����3 : ��ȣ�� ¦�� ���� �ʴ� ���
                else
                    return 0;  

                s.push(temp);
            }
        }
    }

    //���ÿ� ���� �ִ� ������ ����
    while (!s.empty()) {
        // ���� 2 : ������ȣ�� �� ���� ���
        if (s.top() == -1 || s.top() == -3) 
            return 0;

        result += s.top();
        s.pop();
    }
    return result;
}

int main() {
    string st;

    cout << " 20215229 ��ä�� " << endl;
    cout << "��ȣ�� :"; cin >> st;
    cout << "��ȣ���� ��(�ùٸ��� ���� ��ȣ��: 0): "<<bracket(st);
}



