#include <iostream>
#include <random>//난수 생성을 위한 라이브러리

using namespace std;

void HappyLotto(int num);

int main (void) {
	int num;
	cout << "20215229 이채훈" << endl;
	cout << endl;
	cout << "로또 복권을 몇 장 구입 하실래요? "; cin >> num;
	cout << endl;
	cout << " ### 생성된 로또 번호 ### " << endl;
	cout << endl;
	HappyLotto(num);

	return 0;
}

void HappyLotto(int num) {
	const int NUM_MIN = 1;
	const int NUM_MAX = 45;
	//로또 번호 범위 1~45

	random_device rd;
	//난수 생성기 초기화
	mt19937 gen((rd()));
	//메르센 트위스터 엔진 초기화
	uniform_int_distribution <int> distribution(NUM_MIN, NUM_MAX);
	//로또번호 1~45 난수 범위 설정

	for (int i = 0; i < num; i++) {
		int** lotto = new int* [6];
		for (int j = 0; j < 6; j++) {
			lotto[j] = new int;
		}
		//6개의 int형 포인터 원소를 갖는 2차원 동적 배열 생성
		
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
		/*중복된 번호를 피하면서 로또 번호 생성.
		일단 로또 번호를 생성 시키기 위해 do-while문 사용함.*/

		for (int j = 0; j < 6; j++) {
			cout.width(3);
			cout << *lotto[j] << " ";
		} cout << endl;
		//생성된 로또 번호 출력, 간격3 맞추기

		for (int j = 0; j < 6; j++) {
			delete lotto[j];
		}
		delete[] lotto;
		//동적 메모리 해체
	}
}