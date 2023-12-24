#include <iostream>
using namespace std;

#define queueMAXSIZE 100

template <typename E>
class arrayQueue {
private:
    E queue[queueMAXSIZE];
    int front, rear, count;
public:
    //생성자 & 소멸자
    arrayQueue();
    ~arrayQueue();
    //조사
    bool isEmpty(void) const;
    bool isFull(void) const;
    //출력
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

    if (isEmpty()) cout << "큐가 비어있습니다. " << endl;
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
        cout << "큐가 꽉 찼습니다." << endl;
    else {
        rear = (rear + 1) % queueMAXSIZE;
        queue[rear] = e;
        count++;
        cout << "현재 count : " << count << endl;
    }

}
template<typename E>
E arrayQueue<E>::deQueue() {
    if (isEmpty()) cout << "큐가 비어있습니다. " << endl;
    else {
        count--;
        cout << "현재 count : " << count << endl;
        return queue[++front];
    }
}

template<typename E>
E arrayQueue<E>::peek() const {
    if (isEmpty()) cout << "큐가 비어있습니다. " << endl;
    else return queue[front + 1];
}

int main(void)
{

    cout << "20215229 이채훈\n" << endl;

    int   num, choice;
    arrayQueue<int> aQ;

    while (true) {
        system("cls");
        cout << "\n ### 큐 구현: 단순 연결 리스트 ### \n" << endl;
        cout << "1) 데이터 삽입: enQueue" << endl;
        cout << "2) 데이터 삭제: deQueue" << endl;
        cout << "3) 전체 출력" << endl;
        cout << "4) 프로그램 종료 \n" << endl;
        cout << "메뉴 선택 : ";
        cin >> choice;

        switch (choice) {
        case 1: cout << "\n삽입 할 데이터 입력: ";
            cin >> num;
            aQ.enQueue(num);
            break;
        case 2: cout << "삭제 된 데이터: " << aQ.deQueue() << endl;
            break;
        case 3: aQ.printQueue();
            break;
        case 4: cout << "프로그램 종료..." << endl;
            return 0;
        default: cout << "잘못 선택 하셨습니다." << endl;
        }
        system("pause");
    }

    return 0;
}