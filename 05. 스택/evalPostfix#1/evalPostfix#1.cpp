#include <iostream>
using namespace std;

#define	 bufferMAXSIZE	 1024

int 	evalPostfix(char* str);
void	InfixToPostfix(char* postfix, char* infixStr);
int	isOperator(int op);
int	precedence(int op);

inline void error(const char* message);

template<typename E>
class stackNode {
    E data;
    stackNode<E>* link;
    template<typename V> friend class linkedStack;
};

template<typename E>
class linkedStack {
    stackNode<E>* top;
public:
    //������ & �Ҹ���
    linkedStack();
    ~linkedStack();
    //����
    stackNode<E>* makeStackNode(const E& e);
    //����
    bool isEmpty();
    //���
    void printStack();
    //push,pop,peek
    void push(const E& e);
    E pop();
    E peek();
};

template<typename E>
linkedStack<E>::linkedStack() : top(NULL) {}

template<typename E>
linkedStack<E>::~linkedStack() {
    while (!isEmpty()) pop();
}
//����
template<typename E>
stackNode<E>* linkedStack<E>::makeStackNode(const E& e) {
    stackNode<E>* nNode = new stackNode<E>;

    nNode->data = e;
    nNode->link = NULL;

    return nNode;
}

//����
template<typename E>
bool linkedStack<E>::isEmpty() {
    return top == NULL;
}

//���
template<typename E>
void linkedStack<E>::printStack() {
    stackNode<E>* temp = top;

    cout << "\n STACK [";
    while (temp) {
        cout.width(3);
        cout << temp->data;
        temp = temp->link;
    }
    cout << " ]" << endl;
}

//push,pop,peek
template<typename E>
void linkedStack<E>::push(const E& e) {
    stackNode<E>* SNode = makeStackNode(e);

    SNode->link = top;
    top = SNode;
}
template<typename E>
E linkedStack<E>::pop() {
    if (isEmpty()) error("���� ���� ����");

    stackNode<E>* old = top;
    E data = old->data; //data ���
    top = old->link;
    delete old;

    return data;
}

template<typename E>
E linkedStack<E>::peek() {
    if (isEmpty()) error("���� ���� ����");

    return top->data;
}

inline void error(const char* message) {
    cout << message << endl;
    exit(100);
}

//���� ǥ��� �Լ�
int evalPostfix(char* str) {
    int op1, op2, res;
    char temp[bufferMAXSIZE], * p; //�ӽù迭 : ���ڸ� �� �̻� ó���ϱ� ����
    linkedStack<int> s;

    while (*str) {
        //case 1 : �ǿ�����
        if (*str >= '0' && *str <= '9') {
            p = temp;

            while (*str >= '0' && *str <= '9')
                *p++ = *str++;
            *p++ = '\0';
            s.push(atoi(temp));
        }
        //case 2: ������
        else if (isOperator(*str)) {
            op2 = s.pop();
            op1 = s.pop();
            switch (*str) {
            case '+': s.push(op1 + op2); break;
            case '-': s.push(op1 - op2); break;
            case '*': s.push(op1 * op2); break;
            case '/': s.push(op1 / op2); break;
            }
            str++;
        }
        else if (*str == ' ') str++;
        else {
            cout << "�߸��� �����Դϴ�. " << endl;
            return 0;
        }
    }

    if (!s.isEmpty()) res = s.pop();

    return res;
}

void InfixToPostfix(char* postfix, char* infix) {
    linkedStack<int> s;

    while (*infix) {
        // case 1 : ��ȣ '(' : ���ÿ� push
        if (*infix == '(') s.push(*infix++);
        // case 2 : ��ȣ ')' : '('�� ���� ������ pop �� �Ŀ� ')'�� ������.
        else if (*infix == ')') {
            while (s.peek() != '(') {
                *postfix++ = s.pop();
                *postfix++ = ' ';
            }
            s.pop(); // '(' �� ������.
            infix++;
        }
        // case 3 : �������� ���, �ڽź��� �켱������ ���� �����ڴ� ���ÿ��� pop�� ��, �ڽ��� push�Ѵ�.
        else if (isOperator(*infix)) {
            while (!s.isEmpty() &&
                precedence(s.peek()) >= precedence(*infix))
            {
                *postfix++ = s.pop();
                *postfix = ' ';
            }
            s.push(*infix++);
        }
        // case 4 : �ǿ�����
        else if (*infix >= '0' && *infix <= '9') {
            while (*infix >= '0' && *infix <= '9')
                *postfix++ = *infix++;
            *postfix++ = ' ';
        }
        else if (*infix == ' ') infix++;
        else {
            cout << "�߸��� �����Դϴ�. " << endl;
            return;
        }

    }

    while (!s.isEmpty()) {
        *postfix++ = s.pop();
        *postfix++ = ' ';
    }
    postfix--;
    *postfix = '\0';

    return;
}

int  isOperator(int  op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int  precedence(int op) {
    if (op == '(') return 0;
    else if (op == '+' || op == '-') return 1;
    else if (op == '*' || op == '/') return 2;
    else return 3;
}

int main() {
    int	res;
    char	infixStr[bufferMAXSIZE], postfixStr[bufferMAXSIZE];

    cout << "���� �Է�: ";
    cin.getline(infixStr, bufferMAXSIZE);	// getline(cin, infixStr);

    cout << "�Էµ� ���� : " << infixStr << endl;

    InfixToPostfix(postfixStr, infixStr); //infixstr�� ������ postfixstr�� ��ȯ
    cout << "\n����ǥ��� ��ȯ: " << postfixStr << endl;

    res = evalPostfix(postfixStr);

    cout << "������: " << res << endl;

    return 0;
}