#include <iostream>
#define stackMAXSIZE 10

using namespace std;

template<typename E>
class arrStack
{
public:
    arrStack();
    ~arrStack();

    void push(const E& e);  //������ ����
    void pop();             //������ ����
    E peek() const;          //top ���

    int size() const;       //���� ũ�� ���
    bool empty() const;     //���� �� ���� Ȯ��
    bool full() const;      //���� �� ���� Ȯ��

    void printStack() const;//���� ��ü ���
private:
    E stack[stackMAXSIZE];  //���� �迭
    int top;                //������ ž(�迭�� ���� ū �ε���)
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
        cout << "���� ��ȭ ���·� Ǫ�� �Ұ�" << endl;
        return;
    }
    stack[++top] = e;
}

template<typename E>
void arrStack<E>::pop()
{
    if (empty())
    {
        cout << "������ ��� ���� " << endl;
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
    arrStack<int> st;   //���� Ŭ���� ����

    cout << "\n### ���� ����: 1���� �迭 ###\n" << endl;
    cout << "1) ������ ����: PUSH" << endl;
    cout << "2) ������ ����: POP" << endl;
    cout << "3) ��ü ���" << endl;
    cout << "4) ���α׷� ����" << endl << endl;

    while (true)
    {
        cout << "�޴� ���� : "; cin >> menu;

        switch (menu)       //������ ��ȣ�� ���� ��� ����
        {
        case 1: //1) ������ ����
            int input;
            cout << "������ ������ �Է�: "; cin >> input;
            st.push(input); break;
        case 2: //2) ������ ����
            st.pop(); break;
        case 3: //3) ��ü ���
            st.printStack(); cout << endl;
            break;
        case 4: //4) ���α׷� ����
            return 0;
        }

        cout << endl;
    }

    return 0;
}

