#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int num;
	cout << "������ �Է�: "; cin >> num;

	stack<int> s;
	while (num) {
		s.push(num % 2);
		num /= 2;
	}

	cout << "2���� ��ȯ: ";
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}