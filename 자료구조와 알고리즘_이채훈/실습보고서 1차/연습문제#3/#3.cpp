#include <iostream>

using namespace std;

void stuGrade(const double* pArr, int num, double& rSum, double& rAve, double& rMax);
/*
�� ���� ���� �Ű�����(rSum, rAve, rMax)�� ���� ����� ��ȯ��.
pArr�̶�� const double* Ÿ���� ������, num�̶�� int �Ű������� �Է����� ����.
*/

int main(void) {
	int stuSize;
	double* pArr = nullptr;//�����迭�� ������ �ʱ�ȭ
	double sum, ave, max;

	cout << "20215229 ��ä��" << endl;
	cout << endl;
	cout << "�Է��� �л�(����) ��: ";
	cin >> stuSize;

	pArr = new double[stuSize];//�Է� ���� �л� ���� ����, �������� �迭 �Ҵ�

	for (int i = 0; i < stuSize; i++){
		cin >> *(pArr + i);
	}
		
	stuGrade(pArr, stuSize, sum, ave, max);
	cout << "\n ##### ���� ��� ��� ##### \n" << endl;
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