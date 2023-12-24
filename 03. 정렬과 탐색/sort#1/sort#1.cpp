#include <iostream>
#include <vector> //vector
#include <algorithm> //sort
using namespace std;

int main(void) {
	int N;
	int temp;
	vector<int> arr;

	// 입력 : N개의 수
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	cout << endl;

	// std::sort : 퀵 정렬 기반으로 구현, 시간 복잡도 : O(nlogn)
	sort(arr.begin(), arr.end());

	//출력
	for (int i = 0; i < N; i++ )
		cout << arr[i] << endl;

	return 0;
}