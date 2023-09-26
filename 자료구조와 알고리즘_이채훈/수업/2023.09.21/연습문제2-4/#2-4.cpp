/*
03. 재귀
연습문제 2-4: 피보나치수열 -- 재귀적 용법
*/
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;
int Fibo(int num);
int main(void) {
	int num;
	cout << "### 피보나치 수열 구하기 ###" << endl << endl;
	cout << "몇 번째 수열까지 출력할까요: "; cin >> num;

	for (int i = 1; i <= num; i++) {
		if (i % 5) {
			cout.width(8);
			cout << Fibo(i);
		}
		else {
			cout.width(8);
			cout << Fibo(i);
			cout << endl;
		}
	}
	cout << endl;
	return 0;
}
//재귀적 용법 : 피보나치 수열
int Fibo(int num) {
	//재귀 탈출 : 탈출 조건
	if (num == 1 || num == 2)
		return 1;
	else {
		return Fibo(num - 1) + Fibo(num - 2);//O(2^n)
	}
}