#include <iostream>
using namespace std;

#define queueMAXSIZE 100

template <typename E>
class arrayQueue {
private:
    E queue[queueMAXSIZE];
    int front, rear, count;
public:
    //������ & �Ҹ���
    arrayQueue();
    ~arrayQueue();
    //����
    bool isEmpty(void) const;
    bool isFull(void) const;
    //���
    void printQueue(void) const;
    //enQueue,deQueue,peek
    void enQueue(const E& e);
    E deQueue(void);
    E peek(void) const;
};

template<typename E>
arrayQueue<E>::arrayQueue() {
    front = -1;
    rear = -1;
    count = 0;
}

template<typename E>
arrayQueue<E>::~arrayQueue() {}

template<typename E>
bool arrayQueue<E>::isEmpty() const {
    return front == rear;
}


template<typename E>
bool arrayQueue<E>::isFull() const {
    return count == queueMAXSIZE;
    //return (rear+1)%queueMAXSIZE == front;
}

template<typename E>
void arrayQueue<E>::printQueue() const {

    if (isEmpty()) cout << "ť�� ����ֽ��ϴ�. " << endl;
    else {
        if (rear > front) {
            for (int i = front + 1; i <= rear; i++) {
                cout.width(3);
                cout << queue[i];
            }
        }
        else if (rear < front) {
            for (int i = front + 1; i < queueMAXSIZE; i++) {
                cout.width(3);
                cout << queue[i];
            }
            for (int i = 0; i <= rear; i++) {
                cout.width(3);
                cout << queue[i];
            }
        }

        cout << endl;
    }
}

template<typename E>
void arrayQueue<E>::enQueue(const E& e) {
    if (isFull())
        cout << "ť�� �� á���ϴ�." << endl;
    else {
        rear = (rear + 1) % queueMAXSIZE;
        queue[rear] = e;
        count++;
        cout << "���� count : " << count << endl;
    }

}
template<typename E>
E arrayQueue<E>::deQueue() {
    if (isEmpty()) cout << "ť�� ����ֽ��ϴ�. " << endl;
    else {
        count--;
        cout << "���� count : " << count << endl;
        return queue[++front];
    }
}

template<typename E>
E arrayQueue<E>::peek() const {
    if (isEmpty()) cout << "ť�� ����ֽ��ϴ�. " << endl;
    else return queue[front + 1];
}

int main(void)
{

    cout << "20215229 ��ä��\n" << endl;

    int   num, choice;
    arrayQueue<int> aQ;

    while (true) {
        system("cls");
        cout << "\n ### ť ����: �ܼ� ���� ����Ʈ ### \n" << endl;
        cout << "1) ������ ����: enQueue" << endl;
        cout << "2) ������ ����: deQueue" << endl;
        cout << "3) ��ü ���" << endl;
        cout << "4) ���α׷� ���� \n" << endl;
        cout << "�޴� ���� : ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "\n���� �� ������ �Է�: ";
            cin >> num;
            aQ.enQueue(num);
            break;
        case 2: cout << "���� �� ������: " << aQ.deQueue() << endl;
            break;
        case 3: aQ.printQueue();
            break;
        case 4: cout << "���α׷� ����..." << endl;
            return 0;
        default: cout << "�߸� ���� �ϼ̽��ϴ�." << endl;
        }
        system("pause");
    }

    return 0;
}