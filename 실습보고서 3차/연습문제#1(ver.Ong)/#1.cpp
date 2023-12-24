#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> S;// 문자를 저장하는 스택 선언
	string str;
	int ans = 0, temp = 1;// 결과값 및 임시 값 초기화

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;// 여는 소괄호일 경우, temp 값을 2배로 증가시키고 스택에 추가
			S.push('(');
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			S.push('[');
		}
		else if (str[i] == ')')
		{
			//괄호가 잘 닫히지 않은 경우
			if (S.empty() || S.top() != '(')
			{
				ans = 0; break;
			}

			// 짝이 맞는 소괄호일 경우, 결과값에 현재 temp 값을 더하고 temp를 나누기 2
			if (str[i - 1] == '(') ans += temp;

			temp /= 2;
			S.pop();
		}
		else if (str[i] == ']')
		{
			//괄호가 잘 닫히지 않은 경우
			if (S.empty() || S.top() != '[')
			{
				ans = 0; break;
			}
			if (str[i - 1] == '[') 
				ans += temp;
			temp /= 3;
			S.pop();
		}
	}

	if (!S.empty()) ans = 0;//괄호가 짝이 맞지 않는 경우

	cout << ans;// 결과값 출력

	return 0;
}

