/*
03. 재귀
예제2-3. 1부터 n까지의 합
*/
#include <iostream>

using namespace std;

int SUM(int num);

int main(void) {
	int num;
	cout << "임의의 정수 입력: "; cin >> num;
	cout << "1부터 " << num << "까지의 합: " << SUM(num) << endl;
	return 0;
}

//재귀적 용법: 1부터 n까지의 합
int SUM(int num) {
	if (num < 0)
		return 0;
	return num + SUM(num - 1);
}

//반복적 용법: 1부터 n까지의 합
/*
int SUM(int num) {
	int tot = 0;
	for(int i = 1; i< num + 1; i++)
		tot += i;
	return tot;
}
*/