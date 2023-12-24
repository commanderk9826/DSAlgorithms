#include <iostream>
using namespace std;

#define queueMAXSIZE 7

template <typename E>
class CircularQueue {
private:
    E queue[queueMAXSIZE] = { 0 };
    int frontIndex, rearIndex, count;
public:
    //������ & �Ҹ���
    CircularQueue();
    ~CircularQueue();

    //push, pop,front, back
    void push(const E& e);
    void pop();
    E front() const;
    E back() const;

    //size, empty, full
    int size() const;
    bool empty() const;
    bool full() const;

    //printQueue
    void printQueue() const;
};

template<typename E>
CircularQueue<E>::CircularQueue()
    : frontIndex(-1), rearIndex(-1), count(0) {}

template<typename E>
CircularQueue<E>::~CircularQueue() {}

//push(enQueue): ť�� ������ �׸� ����(�� ������ ����)
template<typename E>
void CircularQueue<E>::push(const E& e) {
    if (full()) {
    cout << "ť�� ��ȭ �����Դϴ�." << endl;
    //return;
    }
    else{
        rearIndex = (rearIndex + 1) % queueMAXSIZE;
        queue[rearIndex] = e;
        count++;
    }
}

//pop(deQueue): ť���� �� ù ��°�� ���Ե� ������ �׸� ����
template<typename E>
void CircularQueue<E>::pop() {
    if (empty()) {
        cout << "ť�� ���� �����Դϴ�." << endl;
        //return;
    }
    else {
        frontIndex = (frontIndex + 1) % queueMAXSIZE;
        queue[frontIndex] = 0;
        count--;
    }
 }

//front(peek): ť���� �� ù ��°�� ���Ե� ������ �׸� Ȯ��
template<typename E>
E CircularQueue<E>::front() const {
        return queue[(frontIndex+1)%queueMAXSIZE];
}

//back(peek): ť���� �� �������� ���Ե� ������ �׸� Ȯ��
template<typename E>
E CircularQueue<E>::back() const {
        return queue[rearIndex];
}

//size: ť�� ũ��(�׸��� ����)
template<typename E>
int CircularQueue<E>::size() const {
    return count;
}

//empty: ť�� ���� ���� Ȯ��
template<typename E>
bool CircularQueue<E>::empty() const {
    return count == 0;
}

//full: ť�� ��ȭ ���� Ȯ��
template<typename E>
bool CircularQueue<E>::full() const {
    return (rearIndex + 1) % queueMAXSIZE == frontIndex;
}

//printQueue: ť�� ��ü ������ �׸� ���
template<typename E>
void CircularQueue<E>::printQueue() const {
    cout << "\n QUEUE [";
    for (int i = 0; i < queueMAXSIZE; i++) {
        cout.width(3);
        cout << queue[i];
    }
    cout << "]" << endl;
}

int main(void)
{
    int   num, choice;
    CircularQueue<int> CQ;

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
            cout << "���� �� ������: " << CQ.front() << endl;
            CQ.pop();
            break;
        case 3: 
            cout << "���� ť ��ü ���� ���: "; CQ.printQueue();
            cout << "\nFront: " << CQ.front() << ", Rear: " << CQ.back() << ", Size: " << CQ.size() << endl;
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

