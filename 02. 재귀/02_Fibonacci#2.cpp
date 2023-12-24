/*
02. 재귀
피보나치 수열:동적 프로그래밍
#연습문제 2-2: 피보나치 수열--비재귀적 용법
*/
#include <iostream>

using namespace std;

int Fibo(int num);

int main(void) {
    int num;
    cout << "### 피보나치 수열 구하기 ###" << endl;
    cout << "몇번째 수열까지 출력할까요? : "; cin >> num;
    for (int i = 1; i <= num; i++) {
        cout.width(8);
        if (i % 5)cout << Fibo(i);
        else cout << Fibo(i) << endl;
    }
}

int Fibo(int num) {
    if (num == 1 || num == 2)
        return 1;
    //동적 메모리 할당
    int* pArr = new int[num];
    if (pArr == NULL) {
        cout << "메모리 할당 실패!!!" << endl;
        exit(100);
    }
    int i, temp;
    *pArr = *(pArr + 1) = 1;
    for (i = 2; i <num ; i++) {//for문 범위 수정 <=/<, num+1->num
        *(pArr + i) = *(pArr + i - 1) + *(pArr + i - 2);
    }
    temp = *(pArr + i - 1);
   
    delete []pArr;//동적 메모리 할당 해제가 루프안에 들어가 있던 것을, for문에 중괄호를 추가해서 구분
    return temp;
}
