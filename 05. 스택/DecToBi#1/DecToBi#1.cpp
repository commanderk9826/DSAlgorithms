#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int num;
	cout << "십진수 입력: "; cin >> num;

	stack<int> s;
	while (num) {
		s.push(num % 2);
		num /= 2;
	}

	cout << "2진수 변환: ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}