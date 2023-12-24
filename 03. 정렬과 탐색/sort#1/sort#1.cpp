#include <iostream>
#include <vector> //vector
#include <algorithm> //sort
using namespace std;

int main(void) {
	int N;
	int temp;
	vector<int> arr;

	// �Է� : N���� ��
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> temp;
		arr.push_back(temp);
	}
	cout << endl;

	// std::sort : �� ���� ������� ����, �ð� ���⵵ : O(nlogn)
	sort(arr.begin(), arr.end());

	//���
	for (int i = 0; i < N; i++ )
		cout << arr[i] << endl;

	return 0;
}