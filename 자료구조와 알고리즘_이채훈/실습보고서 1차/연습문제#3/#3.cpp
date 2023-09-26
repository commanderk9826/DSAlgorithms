#include <iostream>

using namespace std;

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax);
/*
세 개의 참조 매개변수(rSum, rAve, rMax)를 통해 결과를 반환함.
pArr이라는 const double* 타입의 포인터, num이라는 int 매개변수를 입력으로 받음.
*/

int main(void) {
	int stuSize;
	double* pArr = nullptr;//동적배열의 포인터 초기화
	double sum, ave, max;

	cout << "20215229 이채훈" << endl;
	cout << endl;
	cout << "입력할 학생(성적) 수: ";
	cin >> stuSize;

	pArr = new double[stuSize];//입력 받은 학생 수에 따라, 동적으로 배열 할당

	for (int i = 0; i < stuSize; i++){
		cin >> *(pArr + i);
	}
		
	stuGrade(pArr, stuSize, sum, ave, max);
	cout << "\n ##### 성적 결과 출력 ##### \n" << endl;
	cout << "학생수: " << stuSize << endl;
	cout << "총  점: " << sum << endl;
	cout << "평  균: " << ave << endl;
	cout << "최대값: " << max << endl;

	delete[] pArr; //동적으로 할당된 메모리 해체

	return 0;
}

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax) {
	rSum = 0;
	rMax = *pArr;

	for (int i = 0; i < num; i++) {
		rSum += *(pArr + i);//학생들의 성적 총점
		if (rMax < *(pArr + i)) {
			rMax = *(pArr + i);
		}//학생들중 성적 최대값

		rAve = rSum / num;//학생들의 성적 평균
	}
}