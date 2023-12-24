#include <iostream>
#define stackMAXSIZE 10

using namespace std;

template<typename E>
class arrStack
{
public:
    arrStack();
    ~arrStack();

    void push(const E& e);  //데이터 삽입
    void pop();             //데이터 삭제
    E peek() const;          //top 출력

    int size() const;       //스택 크기 출력
    bool empty() const;     //스택 빈 여부 확인
    bool full() const;      //스택 찬 여부 확인

    void printStack() const;//스택 전체 출력
private:
    E stack[stackMAXSIZE];  //스택 배열
    int top;                //스택의 탑(배열의 가장 큰 인덱스)
};

template<typename E>
arrStack<E>::arrStack() : top(-1) {}

template<typename E>
arrStack<E>::~arrStack() {}

template<typename E>
void arrStack<E>::push(const E& e)
{
    if (full())
    {
        cout << "스택 포화 상태로 푸쉬 불가" << endl;
        return;
    }
    stack[++top] = e;
}

template<typename E>
void arrStack<E>::pop()
{
    if (empty())
    {
        cout << "스택이 비어 있음 " << endl;
        return;
    }
    --top;
}

template<typename E>
E arrStack<E>::peek() const
{
    if (empty()) return 0;
    return stack[top];
}

template<typename E>
int arrStack<E>::size() const
{
    if (empty()) return 0;
    return (top + 1);
}

template<typename E>
bool arrStack<E>::empty() const
{
    if (top == -1) return true;
    else return false;
}

template<typename E>
bool arrStack<E>::full() const
{
    if (top + 1 == stackMAXSIZE) return true;
    else return false;
}

template<typename E>
void arrStack<E>::printStack() const
{
    for (int i = 0; i <= top; i++) cout << stack[i] << " ";
}

int main()
{
    int menu;
    arrStack<int> st;   //스택 클래스 선언

    cout << "\n### 스택 구현: 1차원 배열 ###\n" << endl;
    cout << "1) 데이터 삽입: PUSH" << endl;
    cout << "2) 데이터 삭제: POP" << endl;
    cout << "3) 전체 출력" << endl;
    cout << "4) 프로그램 종료" << endl << endl;

    while (true)
    {
        cout << "메뉴 선택 : "; cin >> menu;

        switch (menu)       //선택한 번호에 따라 기능 실행
        {
        case 1: //1) 데이터 삽입
            int input;
            cout << "삽입할 데이터 입력: "; cin >> input;
            st.push(input); break;
        case 2: //2) 데이터 삭제
            st.pop(); break;
        case 3: //3) 전체 출력
            st.printStack(); cout << endl;
            break;
        case 4: //4) 프로그램 종료
            return 0;
        }

        cout << endl;
    }

    return 0;
}

