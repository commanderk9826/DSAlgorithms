#include <iostream>
#include <string>
#include <stack>

using namespace std;

int testPair(string str);

int main(void) {

	string str;
	bool state;
	cout << "수식 입력: ";
	getline(cin, str);

	state = testPair(str);
	if (state == true)
		cout << "수식의 괄호 쌍이 맞습니다." << endl;
	else
		cout << "수식의 괄호 쌍이 틀립니다." << endl;

	return 0;
}

int testPair(string str) {
	stack<int> s;
	char symbol;

	for (int i = 0; i < str.length(); i++) {
		//1) 여는 괄호 : 스택에 PUSH
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);

		//2) 닫는 괄호 : 스택에서 POP하여 여는 괄호와 짝을 비교
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (s.empty())
				return false;
			symbol = s.top();
			if (str[i] == ')' && symbol != '('
				|| str[i] == '}' && symbol != '{'
				|| str[i] == ']' && symbol != ']')
				return false;
			s.pop();
		}
	}
	int state;
	if (s.empty()) state = true;
	else state = false;
	//s.~LinkedStack();
	return state;

}

