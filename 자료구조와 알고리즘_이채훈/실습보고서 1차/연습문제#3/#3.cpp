#include <iostream>

using namespace std;

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax);

int main(void) {
	int stuSize;
	double* pArr = nullptr;
	double sum, ave, max;

	cout << "20215229 이채훈" << endl;
	cout << endl;
	cout << "입력할 학생(성적) 수: ";
	cin >> stuSize;

	pArr = new double[stuSize];//입력 받은 학생 수에 따라, 동적으로 배열 할당

	for (int i = 0; i < stuSize; i++){
		cin >> *(pArr + i);
	}//입력 받은 학생 수만큼, 성적 입력 받음
		
	stuGrade(pArr, stuSize, sum, ave, max);
	cout << endl;
	cout << " ##### 성적 결과 출력 ##### " << endl;
	cout << endl;
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