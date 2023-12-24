#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
	stack<char> S;// ���ڸ� �����ϴ� ���� ����
	string str;
	int ans = 0, temp = 1;// ����� �� �ӽ� �� �ʱ�ȭ

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '(')
		{
			temp *= 2;// ���� �Ұ�ȣ�� ���, temp ���� 2��� ������Ű�� ���ÿ� �߰�
			S.push('(');
		}
		else if (str[i] == '[')
		{
			temp *= 3;
			S.push('[');
		}
		else if (str[i] == ')')
		{
			//��ȣ�� �� ������ ���� ���
			if (S.empty() || S.top() != '(')
			{
				ans = 0; break;
			}

			// ¦�� �´� �Ұ�ȣ�� ���, ������� ���� temp ���� ���ϰ� temp�� ������ 2
			if (str[i - 1] == '(') ans += temp;

			temp /= 2;
			S.pop();
		}
		else if (str[i] == ']')
		{
			//��ȣ�� �� ������ ���� ���
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

	if (!S.empty()) ans = 0;//��ȣ�� ¦�� ���� �ʴ� ���

	cout << ans;// ����� ���

	return 0;
}

