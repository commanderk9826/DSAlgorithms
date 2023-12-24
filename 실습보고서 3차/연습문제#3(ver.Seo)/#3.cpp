#include <iostream>
using namespace std;

#define queueMAXSIZE 7

template <typename E>
class CircularQueue {
private:
    E queue[queueMAXSIZE] = { 0 };
    int frontIndex, rearIndex, count;
public:
    //생성자 & 소멸자
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

//push(enQueue): 큐에 데이터 항목 삽입(맨 마지막 원소)
template<typename E>
void CircularQueue<E>::push(const E& e) {
    if (full()) {
    cout << "큐가 포화 상태입니다." << endl;
    //return;
    }
    else{
        rearIndex = (rearIndex + 1) % queueMAXSIZE;
        queue[rearIndex] = e;
        count++;
    }
}

//pop(deQueue): 큐에서 맨 첫 번째로 삽입된 데이터 항목 삭제
template<typename E>
void CircularQueue<E>::pop() {
    if (empty()) {
        cout << "큐가 공백 상태입니다." << endl;
        //return;
    }
    else {
        frontIndex = (frontIndex + 1) % queueMAXSIZE;
        queue[frontIndex] = 0;
        count--;
    }
 }

//front(peek): 큐에서 맨 첫 번째로 삽입된 데이터 항목 확인
template<typename E>
E CircularQueue<E>::front() const {
        return queue[(frontIndex+1)%queueMAXSIZE];
}

//back(peek): 큐에서 맨 마지막에 삽입된 데이터 항목 확인
template<typename E>
E CircularQueue<E>::back() const {
        return queue[rearIndex];
}

//size: 큐의 크기(항목의 개수)
template<typename E>
int CircularQueue<E>::size() const {
    return count;
}

//empty: 큐의 공백 여부 확인
template<typename E>
bool CircularQueue<E>::empty() const {
    return count == 0;
}

//full: 큐의 포화 상태 확인
template<typename E>
bool CircularQueue<E>::full() const {
    return (rearIndex + 1) % queueMAXSIZE == frontIndex;
}

//printQueue: 큐의 전체 데이터 항목 출력
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
            cout << "삭제 된 데이터: " << CQ.front() << endl;
            CQ.pop();
            break;
        case 3: 
            cout << "원형 큐 전체 원소 출력: "; CQ.printQueue();
            cout << "\nFront: " << CQ.front() << ", Rear: " << CQ.back() << ", Size: " << CQ.size() << endl;
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

