#include <iostream>
#include <ctime>		// clock, clock_t, CLOCKS_PER_SEC

using namespace std;

int  Fibo(int  num);

int main(void)
{
	int	num;

	cout << "### 피보나치 수열 구하기 ###" << endl;
	cout << "몇번째 수열까지 출력할까요? : ";
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
	cout << num << "번쨰 피보나치 수열 계산 시간: " << seconds << endl;

	return 0;
}
//재귀적 용법
int  Fibo(int  num) {

	if(num == 1 || num == 2)
		return 1;
	return Fibo(num - 1) + Fibo(num - 2);
}


//비 재귀적 용법 
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


