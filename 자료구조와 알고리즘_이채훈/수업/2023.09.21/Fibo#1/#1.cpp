/*
03. 재귀
피보나치 수열:동적 프로그래밍
#연습문제 2-3: 피보나치 수열--비재귀적 용법
*/
#include <iostream>

using namespace std;

int Fibo(int num);

int main(void) {
    int num;
    cout << "### 피보나치 수열 구하기###" << endl;
    cout << "몇번째 수열까지 출력할까요? : "; cin >> num;
    for (int i = 1; i <=num; i++) {
        cout.width(8);
        if (i % 5)cout << Fibo(i);
        else cout << Fibo(i) << endl;
    }
}

int Fibo(int num) {
    if (num == 1 || num == 2)
        return 1;
    int first = 1, second = 1, res = 0;
    for (int i = 3; i <= num; ++i) {
        res = first + second;
        first = second;
        second = res;
    }
    return res;
}
/*
03. 재귀
피보나치 수열:동적 프로그래밍
내기 짜다가 망한 코드
*/
/*
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int Fibo(int n);

int main(void) {
    int n;
    cout << "### 피보나치 수열 구하기###" << endl;
    cout << "몇번째 수열까지 출력할까요? : "; cin >> n;
    for (int i = 0; i < n; i++) {
        Fibo(n);
        cout << setw(8) << Fibo(n);
    }
    return 0;
}

int Fibo(int n) {
    vector<int> arr(n + 1, 0);
    arr[0] = 1;
    arr[1] = 1;

    for (int i = 2; i <= n; ++i) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[n];
}
*/