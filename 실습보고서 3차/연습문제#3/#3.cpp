#include <iostream>
using namespace std;
inline void error(const char* message);

#define queueMAXSIZE 7

template <typename E>
class CircularQueue {
private:
    E queue[queueMAXSIZE];
    int __front, __rear, __count;
public:
    //������ & �Ҹ���
    CircularQueue();
    ~CircularQueue();

    //push, pop,front, back
    void push(const E& e);
    E pop(void);
    E front(void) const;
    E back(void) const;

    //size, empty, full
    int size(void) const;
    bool empty(void) const;
    bool full(void) const;

    //printQueue
    void printQueue(void) const;
};

template<typename E>
CircularQueue<E>::CircularQueue()
    : __front(-1), __rear(-1), __count(0) {}

template<typename E>
CircularQueue<E>::~CircularQueue() {}

//push(enQueue): ť�� ������ �׸� ����(�� ������ ����)
template<typename E>
void CircularQueue<E>::push(const E& e) {
    if (full())
        error("���� ť ��ȭ ����");
    else {
        __rear = (__rear + 1) % queueMAXSIZE;
        queue[__rear] = e;
        __count++;
    }

}

//pop(deQueue): ť���� �� ù ��°�� ���Ե� ������ �׸� ����
template<typename E>
E CircularQueue<E>::pop() {
    if (empty()) 
        error("���� ť ���� ����");
    else {
        __count--;
        return queue[++__front];
    }
}

//front(peek): ť���� �� ù ��°�� ���Ե� ������ �׸� Ȯ��
template<typename E>
E CircularQueue<E>::front() const {
    if (empty())
        error("���� ť ���� ����");
    else
        return queue[(__front + 1) % queueMAXSIZE];
}

//back(peek): ť���� �� �������� ���Ե� ������ �׸� Ȯ��
template<typename E>
E CircularQueue<E>::back() const {
    if (empty())
        error("���� ť ���� ����");
    else
        return queue[__rear];
}

//size: ť�� ũ��(�׸��� ����)
template<typename E>
int CircularQueue<E>::size() const {
    return __count;
}

//empty: ť�� ���� ���� Ȯ��
template<typename E>
bool CircularQueue<E>::empty() const {
    return __front == __rear;
}

//full: ť�� ��ȭ ���� Ȯ��
template<typename E>
bool CircularQueue<E>::full() const {
    return __count == queueMAXSIZE;
}

//printQueue: ť�� ��ü ������ �׸� ���
template<typename E>
void CircularQueue<E>::printQueue() const {

    if (empty()) 
        error("���� ť ���� ����");
    else {
        if (__rear > __front) {
            for (int i = __front + 1; i <= __rear; i++) {
                cout.width(3);
                cout << queue[i];
            }
        }
        else if (__rear < __front) {
            for (int i = __front + 1; i < queueMAXSIZE; i++) {
                cout.width(3);
                cout << queue[i];
            }
            for (int i = 0; i <= __rear; i++) {
                cout.width(3);
                cout << queue[i];
            }
        }
        cout << endl;
    }
}

inline void error(const char* message) {
    cout << message;
    exit(100);
}


int main(void)
{
    int   num, choice;
    CircularQueue<int> CQ= CircularQueue<int>();// �� ť ����

    while (true) {
        system("cls");
        cout << " 20215229 ��ä�� " << endl;
        cout << "\n ### ť ����: 1���� �迭 ### \n" << endl;
        cout << "1) ������ ����(enQueue): " << endl;
        cout << "2) ������ ����(deQueue): " << endl;
        cout << "3) ��ü ���" << endl;
        cout << "4) ���α׷� ���� \n" << endl;
        cout << "�޴� ���� : ";
        cin >> choice;

        switch (choice) {
        case 1: 
            cout << "\n���� �� ������ �Է�: ";
            cin >> num;
            CQ.push(num);
            break;
        case 2: 
            cout << "���� �� ������: " << CQ.pop() << endl;
            break;
        case 3: 
            CQ.printQueue();
            cout << "Front: " << CQ.front() << ", Rear: " << CQ.back() << ", Size: "<<CQ.size()<<endl;
            break;
        case 4: 
            cout << "���α׷� ����..." << endl;
            return 0;
        default: 
            cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
        }
        system("pause");
    }
    return 0;
}