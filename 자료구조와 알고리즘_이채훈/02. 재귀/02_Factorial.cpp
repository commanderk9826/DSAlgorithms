/*
* 02. 재귀
* 예제2-2. 계승(Factorial 구하기)
*/

#include <iostream>
using namespace std;

int Factorial(int num);

int main(void) {

	int num;
	cout << "임의의 정수: ";
	cin >> num;
	cout << num << " Factorial: " << Factorial(num) << endl;
	return 0;
}

//재귀적 용법 : Factorial
int Factorial(int num) {
	if (num == 0)//재귀함수 탈출(종료) 조건
		return 1;
	return num * Factorial(num - 1);
}

//반복적 용법 : Factorial
/*
int Factorial(int num) {
	int res = 1;
	for (int i = 0; i <= num; i++)
		res = res * i;
	return res;
}
*/
