#include <iostream>
#include <random>//���� ������ ���� ���̺귯��

using namespace std;

void HappyLotto(int num);

int main (void) {
	int num;
	cout << "20215229 ��ä��" << endl;
	cout << endl;
	cout << "�ζ� ������ �� �� ���� �ϽǷ���? "; cin >> num;
	cout << endl;
	cout << " ### ������ �ζ� ��ȣ ### " << endl;
	cout << endl;
	HappyLotto(num);

	return 0;
}

void HappyLotto(int num) {
	const int NUM_MIN = 1;
	const int NUM_MAX = 45;
	//�ζ� ��ȣ ���� 1~45

	random_device rd;
	//���� ������ �ʱ�ȭ
	mt19937 gen((rd()));
	//�޸��� Ʈ������ ���� �ʱ�ȭ
	uniform_int_distribution <int> distribution(NUM_MIN, NUM_MAX);
	//�ζǹ�ȣ 1~45 ���� ���� ����

	for (int i = 0; i < num; i++) {
		int** lotto = new int* [6];
		for (int j = 0; j < 6; j++) {
			lotto[j] = new int;
		}
		//6���� int�� ������ ���Ҹ� ���� 2���� ���� �迭 ����
		
		for (int j = 0; j < 6; j++) {
			bool duplicate;
			do {
				duplicate = false;
				*lotto[j] = distribution(gen);

				for (int k = 0; k < j; k++) {
					if (*lotto[k] == *lotto[j]) {
						duplicate = true;
						break;
					}
				}

			} while (duplicate);
		}
		/*�ߺ��� ��ȣ�� ���ϸ鼭 �ζ� ��ȣ ����.
		�ϴ� �ζ� ��ȣ�� ���� ��Ű�� ���� do-while�� �����.*/

		for (int j = 0; j < 6; j++) {
			cout.width(3);
			cout << *lotto[j] << " ";
		} cout << endl;
		//������ �ζ� ��ȣ ���, ����3 ���߱�

		for (int j = 0; j < 6; j++) {
			delete lotto[j];
		}
		delete[] lotto;
		//���� �޸� ��ü
	}
}