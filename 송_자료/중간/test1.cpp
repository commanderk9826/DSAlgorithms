#include <iostream>
#define arrMaxSize 1024
using namespace std;

/*
* ������ �� �ȳ���;
*/
int Fibo_repeat(int num) {

	int* fn = new int[arrMaxSize];

	fn[0] = 1;
	fn[1] = 1;

	for (int i = 2; i < num; i++) {
		fn[i] = fn[i-1] + fn[i-2];
	}
	return fn[num-1];
}

int main() {
	int n;
	cout << " �� ��° �������� ����ұ��? : ";
	cin >> n;

	for (int i = 1; i < n+1; i++) {
		cout << Fibo_repeat(i);
		cout << "  ";
		if (i % 5 == 0) cout << '\n';
	}

}