#include <iostream>
#include <string>
#include <stack>

using namespace std;

int testPair(string str);

int main(void) {

	string str;
	bool state;
	cout << "���� �Է�: ";
	getline(cin, str);

	state = testPair(str);
	if (state == true)
		cout << "������ ��ȣ ���� �½��ϴ�." << endl;
	else
		cout << "������ ��ȣ ���� Ʋ���ϴ�." << endl;

	return 0;
}

int testPair(string str) {
	stack<int> s;
	char symbol;

	for (int i = 0; i < str.length(); i++) {
		//1) ���� ��ȣ : ���ÿ� PUSH
		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
			s.push(str[i]);

		//2) �ݴ� ��ȣ : ���ÿ��� POP�Ͽ� ���� ��ȣ�� ¦�� ��
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

