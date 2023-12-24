#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void) {
	string str;

	cout << "문자열 입력: "; getline(cin, str);

	stack<char> s;
	for (int i = 0; i < str.length(); i++)
		s.push(str[i]);

	cout << "문자열 역순 출력: ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}