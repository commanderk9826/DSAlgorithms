#include <iostream>

using namespace std;

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax);

int main(void) {
	int stuSize;
	double* pArr = nullptr;
	double sum, ave, max;

	cout << "20215229 ��ä��" << endl;
	cout << endl;
	cout << "�Է��� �л�(����) ��: ";
	cin >> stuSize;

	pArr = new double[stuSize];//�Է� ���� �л� ���� ����, �������� �迭 �Ҵ�

	for (int i = 0; i < stuSize; i++){
		cin >> *(pArr + i);
	}//�Է� ���� �л� ����ŭ, ���� �Է� ����
		
	stuGrade(pArr, stuSize, sum, ave, max);
	cout << endl;
	cout << " ##### ���� ��� ��� ##### " << endl;
	cout << endl;
	cout << "�л���: " << stuSize << endl;
	cout << "��  ��: " << sum << endl;
	cout << "��  ��: " << ave << endl;
	cout << "�ִ밪: " << max << endl;

	delete[] pArr; //�������� �Ҵ�� �޸� ��ü

	return 0;
}

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax) {
	rSum = 0;
	rMax = *pArr;

	for (int i = 0; i < num; i++) {
		rSum += *(pArr + i);//�л����� ���� ����
		if (rMax < *(pArr + i)) {
			rMax = *(pArr + i);
		}//�л����� ���� �ִ밪

		rAve = rSum / num;//�л����� ���� ���
	}
}