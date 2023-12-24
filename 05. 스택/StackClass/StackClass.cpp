#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	stack<int> S;

	S.push(10);
	S.push(20);
	S.push(30);

	cout << "stack is empty : " << S.empty() << endl;
	cout << "stack size     : " << S.size() << endl;

	while (!S.empty()) {
		cout << "top element : " << S.top() << endl;
		S.pop();
	}
	return 0;
}

/*
#include <stack> 
using namespace std;
stack<DataType> stackName // 빈 스택 생성
void push(const value_type& val); // 스택에 데이터 항목 추가
void pop(); // 스택에 데이터 항목 삭제
value_type& top();// 스택의 데이터 항목 반환(top)
bool empty() const; // 스택이 비어 있는지 여부 확인
size_type size() const; // 스택의 크기 반환
swap(stack1, stack2) // 스택 SWAP
*/