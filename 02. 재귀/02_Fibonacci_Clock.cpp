#include <iostream>
#include <ctime>		// clock, clock_t, CLOCKS_PER_SEC

using namespace std;

int  Fibo(int  num);

int main(void)
{
	int	num;

	cout << "### �Ǻ���ġ ���� ���ϱ� ###" << endl;
	cout << "���° �������� ����ұ��? : ";
	cin >> num;

	clock_t		start, finish;
	double		seconds;

	start = clock();		
	for(int i=1; i<=num; i++ ) {
		cout.width(8);
		if(i%5)	cout << Fibo(i);
		else	cout << Fibo(i) << endl;
	}
	finish = clock();		

	seconds = (double)(finish - start)/CLOCKS_PER_SEC;  
	cout << num << "���� �Ǻ���ġ ���� ��� �ð�: " << seconds << endl;

	return 0;
}
//����� ���
int  Fibo(int  num) {

	if(num == 1 || num == 2)
		return 1;
	return Fibo(num - 1) + Fibo(num - 2);
}


//�� ����� ��� 
int  Fibo(int  num) {
	if(num == 1 || num == 2)
		return 1;

	int	first, second, res = 0;
	first  =  second  =  1;    
	for(int i=3; i<=num; i++) {
		res  =  first  +  second;
		first = second;
		second  =  res;
	}
	return res;
}


