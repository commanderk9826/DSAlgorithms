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
    //생성자 & 소멸자
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

//push(enQueue): 큐에 데이터 항목 삽입(맨 마지막 원소)
template<typename E>
void CircularQueue<E>::push(const E& e) {
    if (full())
        error("원형 큐 포화 에러");
    else {
        __rear = (__rear + 1) % queueMAXSIZE;
        queue[__rear] = e;
        __count++;
    }

}

//pop(deQueue): 큐에서 맨 첫 번째로 삽입된 데이터 항목 삭제
template<typename E>
E CircularQueue<E>::pop() {
    if (empty()) 
        error("원형 큐 공백 에러");
    else {
        __count--;
        return queue[++__front];
    }
}

//front(peek): 큐에서 맨 첫 번째로 삽입된 데이터 항목 확인
template<typename E>
E CircularQueue<E>::front() const {
    if (empty())
        error("원형 큐 공백 에러");
    else
        return queue[(__front + 1) % queueMAXSIZE];
}

//back(peek): 큐에서 맨 마지막에 삽입된 데이터 항목 확인
template<typename E>
E CircularQueue<E>::back() const {
    if (empty())
        error("원형 큐 공백 에러");
    else
        return queue[__rear];
}

//size: 큐의 크기(항목의 개수)
template<typename E>
int CircularQueue<E>::size() const {
    return __count;
}

//empty: 큐의 공백 여부 확인
template<typename E>
bool CircularQueue<E>::empty() const {
    return __front == __rear;
}

//full: 큐의 포화 상태 확인
template<typename E>
bool CircularQueue<E>::full() const {
    return __count == queueMAXSIZE;
}

//printQueue: 큐의 전체 데이터 항목 출력
template<typename E>
void CircularQueue<E>::printQueue() const {

    if (empty()) 
        error("원형 큐 공백 에러");
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
    CircularQueue<int> CQ= CircularQueue<int>();// 빈 큐 생성

    while (true) {
        system("cls");
        cout << " 20215229 이채훈 " << endl;
        cout << "\n ### 큐 구현: 1차원 배열 ### \n" << endl;
        cout << "1) 데이터 삽입(enQueue): " << endl;
        cout << "2) 데이터 삭제(deQueue): " << endl;
        cout << "3) 전체 출력" << endl;
        cout << "4) 프로그램 종료 \n" << endl;
        cout << "메뉴 선택 : ";
        cin >> choice;

        switch (choice) {
        case 1: 
            cout << "\n삽입 할 데이터 입력: ";
            cin >> num;
            CQ.push(num);
            break;
        case 2: 
            cout << "삭제 된 데이터: " << CQ.pop() << endl;
            break;
        case 3: 
            CQ.printQueue();
            cout << "Front: " << CQ.front() << ", Rear: " << CQ.back() << ", Size: "<<CQ.size()<<endl;
            break;
        case 4: 
            cout << "프로그램 종료..." << endl;
            return 0;
        default: 
            cout << "잘못 선택 하셨습니다." << endl;
        }
        system("pause");
    }
    return 0;
}