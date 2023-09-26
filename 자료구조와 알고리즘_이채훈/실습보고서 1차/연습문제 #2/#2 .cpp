#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[10];
vector<int> v;

void inputValues() {
    cout << "임의의 정수 10개를 입력하세요..." << endl;
    for (int i = 0; i < 10; i++) {
        cout << "arr[" << i << "] : ";
        cin >> arr[i];
        v.push_back(arr[i]);
    }
}//값 입력 및 정적, 동적 배열에 값 추가

int main(void) {
    cout << "20215229 이채훈" << endl;
    cout << endl;

    inputValues(); 

    sort(arr, arr + 10);//정적 배열 오름차순 정렬

    cout << "정렬(정적 배열) : ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }//정적 배열 출력
    cout << endl;

    sort(v.begin(), v.end());//동적 배열 오름차순 정렬
    cout << "정렬(동적 배열) : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }//동적 배열 출력
    return 0;
}
