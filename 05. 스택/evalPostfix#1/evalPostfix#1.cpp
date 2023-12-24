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
    //생성자 & 소멸자
    linkedStack();
    ~linkedStack();
    //생성
    stackNode<E>* makeStackNode(const E& e);
    //조사
    bool isEmpty();
    //출력
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
//생성
template<typename E>
stackNode<E>* linkedStack<E>::makeStackNode(const E& e) {
    stackNode<E>* nNode = new stackNode<E>;

    nNode->data = e;
    nNode->link = NULL;

    return nNode;
}

//조사
template<typename E>
bool linkedStack<E>::isEmpty() {
    return top == NULL;
}

//출력
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
    if (isEmpty()) error("스택 공백 에러");

    stackNode<E>* old = top;
    E data = old->data; //data 백업
    top = old->link;
    delete old;

    return data;
}

template<typename E>
E linkedStack<E>::peek() {
    if (isEmpty()) error("스택 공백 에러");

    return top->data;
}

inline void error(const char* message) {
    cout << message << endl;
    exit(100);
}

//후위 표기법 함수
int evalPostfix(char* str) {
    int op1, op2, res;
    char temp[bufferMAXSIZE], * p; //임시배열 : 두자리 수 이상도 처리하기 위해
    linkedStack<int> s;

    while (*str) {
        //case 1 : 피연산자
        if (*str >= '0' && *str <= '9') {
            p = temp;

            while (*str >= '0' && *str <= '9')
                *p++ = *str++;
            *p++ = '\0';
            s.push(atoi(temp));
        }
        //case 2: 연산자
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
            cout << "잘못된 수식입니다. " << endl;
            return 0;
        }
    }

    if (!s.isEmpty()) res = s.pop();

    return res;
}

void InfixToPostfix(char* postfix, char* infix) {
    linkedStack<int> s;

    while (*infix) {
        // case 1 : 괄호 '(' : 스택에 push
        if (*infix == '(') s.push(*infix++);
        // case 2 : 괄호 ')' : '('가 나올 때까지 pop 한 후에 ')'는 버린다.
        else if (*infix == ')') {
            while (s.peek() != '(') {
                *postfix++ = s.pop();
                *postfix++ = ' ';
            }
            s.pop(); // '(' 를 버린다.
            infix++;
        }
        // case 3 : 연산자인 경우, 자신보다 우선순위가 높은 연산자는 스택에서 pop한 후, 자신을 push한다.
        else if (isOperator(*infix)) {
            while (!s.isEmpty() &&
                precedence(s.peek()) >= precedence(*infix))
            {
                *postfix++ = s.pop();
                *postfix = ' ';
            }
            s.push(*infix++);
        }
        // case 4 : 피연산자
        else if (*infix >= '0' && *infix <= '9') {
            while (*infix >= '0' && *infix <= '9')
                *postfix++ = *infix++;
            *postfix++ = ' ';
        }
        else if (*infix == ' ') infix++;
        else {
            cout << "잘못된 수식입니다. " << endl;
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

    cout << "수식 입력: ";
    cin.getline(infixStr, bufferMAXSIZE);	// getline(cin, infixStr);

    cout << "입력된 수식 : " << infixStr << endl;

    InfixToPostfix(postfixStr, infixStr); //infixstr의 수식을 postfixstr로 변환
    cout << "\n후위표기법 변환: " << postfixStr << endl;

    res = evalPostfix(postfixStr);

    cout << "연산결과: " << res << endl;

    return 0;
}